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
    for(int CASE=0;CASE++<T;){
        int a,b,k,ret=0;
        std::cout<<"Solving Case "<<CASE<<"...\n";
        ifs>>a>>b>>k;
        if(a<b){
            int tmp=a;
            a=b;
            b=tmp;
        }
        for(int i=0;i<a;i++){
            for(int j=0;j<b;j++){
                if((i&j)<k) ret++;
            }
        }
        ofs<<"Case #"<<CASE<<": "<<ret<<"\n";
    }
    
    
    
    return 0;
}