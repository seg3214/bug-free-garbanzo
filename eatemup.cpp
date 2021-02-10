#include "../includes/filefunctions.cpp"
#include "../includes/ipfunctions.cpp"
//#include <string>
#include <iostream>
//#include <filesystem>
//#include <dirent.h>
//#include <unistd.h>
#include <vector>
#include <algorithm>

std::vector<std::string> container;

void filestringproccessor(std::string *str)
{
    std::vector<std::string> ar;
     int count= findIps_String_Vector(str,&ar);
     if (count!=0)
        for (int i=0;i<count;i++)
        if (std::find(container.begin(), container.end(), ar[i]) != container.end())
        {} else
        {
            container.push_back(ar[i]);
        }
}

int main(int argc, char const *argv[])
{
   std::vector<std::string> files,filecon;

    int r=getallfiles_currdir("txt",&files);
    if (r==0) return 0;
    for (int i=0;i<files.size();i++)
    loadstringsfromfile(&filecon,&files[i],filestringproccessor);
    write_vector("output.ip",&container,"\n");

    return 0;
}
