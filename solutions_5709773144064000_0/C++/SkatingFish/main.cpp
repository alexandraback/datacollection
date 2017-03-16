//
//  main.cpp
//  CookieCliker
//
//  Created by Liubing Yu on 4/12/14.
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
    
    
    int T,j,i,k;
    ifstream fin;    // Input file stream
    ofstream fout;   //Output file stream
    fout.precision(7);
    cout.precision(7);
    fout.setf(ios::fixed,ios::floatfield);
    cout.setf(ios::fixed,ios::floatfield);
    long double C,F,X,a,b,c,sum;
    
    fin.open ("/Users/liubingyu/Desktop/B-small-attempt0.in.txt");
    fout.open("/Users/liubingyu/Desktop/B-small-attempt0.out.txt");
    
    fin>>T;
    // std::cout << T<<"Hello, World!\n";
    for(j=0;j<T;j++){
        sum=0;
        fin>>C>>F>>X;
        if(C>=X) sum=X/2.0;
        else{
            for (i=1;true;i++){
                if((X-C)*(F*i+2)<X*(F*i-F+2))break;
            }
          //  cout<<i<<endl;
            i--;
            
           // cout<<sum<<endl;
            for(k=i-1;k>=0;k--){
                sum=sum+C/(F*k+2);// caculating from the end to begin
            //    cout<<sum<<endl;
            }
            sum=sum+X/(F*i+2);
        }
        fout<<"Case #"<<j+1<<": "<<sum<<endl;
        cout<<"Case #"<<j+1<<": "<<sum<<endl;
        
    }
    fin.close();
    fout.close();
    
}