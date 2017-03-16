#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<fstream>
#include<sstream>
#include<algorithm>
#include<vector>
#include<string>
#include<climits>
#include<iomanip>

int main(int argc,char* argv[]){
    if(argc!=2){
        std::cerr<<"filename missing\n";
        return 1;
    }
    std::ifstream ifs(argv[1]);
    std::ofstream ofs("output.txt");
    std::string str;
    int T;
    ifs>>T;
    double c,f,x;
    ofs.setf(std::ios::fixed);
    ofs.precision(7);
    for(int CASE=0;CASE++<T;){
                std::cout<<"Solving Case "<<CASE<<"...\n";
        ifs>>c>>f>>x;
        double cps=2.0;
        double acc=0.0;
        while((c/cps)+(x/(cps+f))<x/cps){
            acc+=c/cps;
            cps+=f;
        }
        acc+=x/cps;
        ofs<<"Case #"<<CASE<<": "<<acc<<"\n";
    }
    
    
    
    return 0;
}