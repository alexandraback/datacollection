//
//  main.cpp
//  MineSweeper
//
//  Created by Liubing Yu on 4/11/14.
//  Copyright (c) 2014 Liubing Yu. All rights reserved.
//

//
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <fstream>
#include <unordered_map>
using namespace std;


int poss[101],xl[101],yl[101];  ///T[i] is to solve the cases that has i space;
//xl is the x-axis, yl is the y-axis

ifstream fin;    // Input file stream
ofstream fout;   //Output file stream

void printMine1(int R, int C,int k){
    
    // this case is that only 1 space
    char ch;
    if(k=1) ch='*';
    else  ch='.';
    
    char Array1[R][C];
        for(int i=0;i<R;i++){
            for(int j=0;j<C;j++){
               Array1[i][j]=ch;
            }
        }
        Array1[0][0]='c';
        for(int i=0;i<R;i++){
            for(int j=0;j<C;j++){
                fout<<Array1[i][j];
                cout<<Array1[i][j];
            }
            fout<<endl;
            cout<<endl;
        }
}
void printMine2(int R, int C, int space){
    
    // this case is that the space are equal or larger than (twice of the shorter edge)+2
   
    char Array1[R][C];
    if(R>=C){       /// x has larger size than y
        for(int i=0;i<R;i++){
            for(int j=0;j<C;j++){
                if(i*C+j<space){
                    Array1[i][j]='.';
                }
                else Array1[i][j]='*';
            }
        }
        Array1[0][0]='c';
        for(int i=0;i<R;i++){
            for(int j=0;j<C;j++){
                fout<<Array1[i][j];
                cout<<Array1[i][j];
            }
            fout<<endl;
            cout<<endl;
        }
        
    }
    else{       /// y has larger size than x
        for(int i=0;i<R;i++){
            for(int j=0;j<C;j++){
                if(i+j*R<space){
                    Array1[i][j]='.';
                }
                else Array1[i][j]='*';
            }
        }
        Array1[0][0]='c';
        for(int i=0;i<R;i++){
            for(int j=0;j<C;j++){
                fout<<Array1[i][j];
                cout<<Array1[i][j];
            }
            fout<<endl;
            cout<<endl;
        }
    }
}

void printMine3(int R, int C, int space,int m,int n){
    int i,j;
    char Array1[R][C];
    for(i=0;i<R;i++){
        for(j=0;j<C;j++){
            Array1[i][j]='*';
        }
    }
    for(i=0;i<2;i++){    /// set two rows to space
        for(j=0;j<n;j++){
            Array1[i][j]='.';
        }
    }
    for(i=0;i<m;i++){   ///set two column to space
        for(j=0;j<2;j++){
            Array1[i][j]='.';
        }
    }
    
    Array1[0][0]='c';
    
    space=space-2*(m+n)+4;
    for(i=2;i<m;i++){
        for(j=2;j<n;j++){
            if((i-2)+(j-2)*(m-2)<space){
                Array1[i][j]='.';
            }
            else Array1[i][j]='*';
        }
    }

    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            fout<<Array1[i][j];
            cout<<Array1[i][j];
        }
        fout<<endl;
        cout<<endl;
    }
    // this case is that the space can be formed by small rectangles
}



bool Minesweeper(int R, int C, int M){
    int i,j,k,space=R*C-M;    
    if(space==1){   //only one space
        printMine1(R,C,1);
        return 1;
    }
    if(M==0){       //all are space
        printMine1(R,C,0);
        return 1;
    }
    
    if(min(R,C)==1){
        printMine2(R,C,space);
        return 1;
    }
    // just one line or one row
  //  cout<<R<<C<<space<<endl;
    for(i=2;i<=R;i++){
        for(j=2;j<=C;j++){
           // cout<<i*j<<2*(i+j)-4<<endl;
            if(2*(i+j)-4<=space&&space<=i*j) {
               // cout<<i<<j<<endl;
                printMine3(R,C,space,i,j);
                return 1;
            }
        }
    }
    return 0;
}

int main(int argc, const char * argv[])
{
    

    int T,j,R,C,M,i;

    for(i=0;i<101;i++){
      //  cout<<i<<" "<<poss[i]<<" "<<xl[i]<<" "<<yl[i]<<endl;
    }
    fin.open ("/Users/liubingyu/Desktop/C-small-attempt1.in.txt");
    fout.open("/Users/liubingyu/Desktop/C-small-attempt1.out.txt");
    fin>>T;
    std::cout << T<<"Hello, World!\n";
    for(j=0;j<T;j++){
        fin>>R>>C>>M;
        fout<<"Case #"<<j+1<<":\n";
        cout<<"Case #"<<j+1<<":\n";
        if(Minesweeper(R, C, M)==0){//there is not ways to solve the problem
             fout<<"Impossible"<<endl;
             cout<<"Impossible"<<endl;
        }
    }
    fin.close();
    fout.close();
    
}


