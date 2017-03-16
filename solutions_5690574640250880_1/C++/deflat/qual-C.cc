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
        ofs<<"Case #"<<CASE<<":\n";
        int m,r,c;
        bool flag=false;
        ifs>>r>>c>>m;
        char map[r][c];
        m=r*c-m;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                map[i][j]='*';
            }
        }
        if(r==1){
            for(int i=0;i<m;i++) map[0][i]='.';
        }
        else if(c==1){
            for(int i=0;i<m;i++) map[i][0]='.';
        }
        else if(r==2){
            if(m==2||m%2==1) flag=true;
            else{
                m/=2;
                for(int i=0;i<m;i++) map[0][i]=map[1][i]='.';
            }
        }
        else if(c==2){
            if(m==2||m%2==1) flag=true;
            else{
                m/=2;
                for(int i=0;i<m;i++) map[i][0]=map[i][1]='.';
            }
        }else{
            if(m<=3||m==5||m==7) flag=true;
            else{
                map[0][0]=map[0][1]=map[1][0]=map[1][1]='.';
                m-=4;
                if(m>0){
                    map[2][0]=map[2][1]='.';
                    m-=2;
                }
                if(m>0){
                    map[0][2]=map[1][2]='.';
                    m-=2;
                }
                int tr=3;
                int tc=3;
                while(m>1&&tr<r){
                    map[tr][0]=map[tr][1]='.';
                    m-=2;
                    tr++;
                }
                while(m>1&&tc<c){
                    map[0][tc]=map[1][tc]='.';
                    m-=2;
                    tc++;
                }
                tr=tc=2;
                while(m>0){
                    map[tr][tc]='.';
                    m--;
                    tc++;
                    if(tc==c){
                        tc=2;
                        tr++;
                    }
                }
            }
        }
        if(flag&&m!=1) ofs<<"Impossible\n";
        else{
            map[0][0]='c';
            for(int i=0;i<r;i++){
                for(int j=0;j<c;j++){
                    ofs<<map[i][j];
                }
                ofs<<"\n";
            }
        }
    }

    
    
    return 0;
}