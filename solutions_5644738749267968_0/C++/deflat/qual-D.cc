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
        std::cout<<"Solving Case "<<CASE<<"...\n";
        int warret=0;
        int dwarret=0;
        double input;
        int n;
        ifs>>n;
        std::vector<double> naolst1;
        std::vector<double> naolst2;
        std::vector<double> kenlst1;
        std::vector<double> kenlst2;
        for(int i=0;i<n;i++){
            ifs>>input;
            naolst1.push_back(input);
            naolst2.push_back(input);
        }
        for(int i=0;i<n;i++){
            ifs>>input;
            kenlst1.push_back(input);
            kenlst2.push_back(input);
        }
        std::sort(naolst1.begin(),naolst1.end());
        std::sort(naolst2.begin(),naolst2.end());
        std::sort(kenlst1.begin(),kenlst1.end());
        std::sort(kenlst2.begin(),kenlst2.end());
        while(!naolst1.empty()){
            if(naolst1[naolst1.size()-1] > kenlst1[kenlst1.size()-1]){
                warret++;
                naolst1.erase(naolst1.end()-1);
                kenlst1.erase(kenlst1.begin());
            }else{
                int pt=kenlst1.size()-1;
                while(pt!=0 && naolst1[naolst1.size()-1] < kenlst1[pt-1]){
                    pt--;
                    
                }
                naolst1.erase(naolst1.end()-1);
                kenlst1.erase(kenlst1.begin()+pt);
                
            }
        }
        while(!naolst2.empty()){
            if(naolst2[0] > kenlst2[0]){
                dwarret++;
                naolst2.erase(naolst2.begin());
                kenlst2.erase(kenlst2.begin());
            }else{
                naolst2.erase(naolst2.begin());
                kenlst2.erase(kenlst2.end()-1);
                
            }
        }

        ofs<<"Case #"<<CASE<<": "<< dwarret<<" "<<warret<<"\n";
    }
    
    
    
    return 0;
}