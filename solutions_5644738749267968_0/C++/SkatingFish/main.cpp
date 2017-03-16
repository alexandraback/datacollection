//
//  main.cpp
//  DeceitfulWar
//
//  Created by Liubing Yu on 4/11/14.
//  Copyright (c) 2014 Liubing Yu. All rights reserved.
//

#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <fstream>
#include <unordered_map>
using namespace std;

int main(int argc, const char * argv[])
{
    
    
    int T,j,R,i,N,M,Dw,Rw;
    ifstream fin;    // Input file stream
    ofstream fout;   //Output file stream
    vector<double> Nonmi, Ken;
    vector<double>::iterator iter1,iter2;
    double a;

    fin.open ("/Users/liubingyu/Desktop/D-small-attempt0.in.txt");
    fout.open("/Users/liubingyu/Desktop/D-small-attempt0.out.txt");
    fin>>T;
   // std::cout << T<<"Hello, World!\n";
    for(j=0;j<T;j++){
        fin>>R;
        Nonmi.clear();
        Ken.clear();
        N=0;
        M=0;
        Dw=0;///deceitful war wins of Nonmi
        Rw=0;///regular war wins of Ken
        for(i=0;i<R;i++){
            fin>>a;
            Nonmi.push_back(a);
        }
        for(i=0;i<R;i++){
            fin>>a;
            Ken.push_back(a);
        }
        sort(Nonmi.begin(),Nonmi.end());
        sort(Ken.begin(),Ken.end());
        
        iter1=Nonmi.begin();
        iter2=Ken.begin();
        while(iter1!=Nonmi.end()&&iter2!=Ken.end()){
            if((*iter1)>(*iter2)){
                iter2++;
                N++;
                if(M>Rw)Rw++;
            }
            else{
                iter1++;
                M++;
                if(N>Dw)Dw++;
            }
        }
      //  cout<<N<<M<<Dw<<Rw<<endl;
        if(iter1==Nonmi.end())Rw=Rw-N+R;
        else Dw=Dw-M+R;
        
        fout<<"Case #"<<j+1<<": "<<Dw<<" "<<R-Rw<<endl;
        cout<<"Case #"<<j+1<<": "<<Dw<<" "<<R-Rw<<endl;

    }
    fin.close();
    fout.close();
    
}

