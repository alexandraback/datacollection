//
//  main.cpp
//  1c_a
//
//  Created by Liubing Yu on 5/11/14.
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

long long gcd(long long a, long long b)
{
    if (b == 0) {
        return a;
    }
    else {
        return gcd(b, a % b);
    }
}

int main(int argc, const char * argv[])
{
    long long p,q,common_f;
    int i,j,errorI,T,sum,k,m;
    int x[64];
    int y[64];
    int z[64];
    char t;
    ifstream fin;    // Input file stream
    ofstream fout;   //Output file stream
    vector<int> Fl;
    fin.open ("/Users/liubingyu/Desktop/A-small-attempt0.in.txt");
    fout.open("/Users/liubingyu/Desktop/A-small-attempt0.out.txt");
    fin>>T;
    cout<<T<<endl;
    for(j=0;j<T;j++){
        fin>>p>>t>>q;
        cout<<p<<t<<q<<endl;
        common_f=gcd(p,q);
        p=p/common_f;
        q=q/common_f;
        
        
      m=0;
        k=0;
      errorI=0;
      for (int i = 0; i <= 50; i++) {
          x[i] = (q >> i) & 1;
          if(m&&x[i]){
            errorI=1;
            break;
          }
          if(m==0&&x[i])m=i;
          y[i] = (p >> i) & 1;
          if(y[i])k=i;
      }
    //  std::cout << T<<"Hello, World!\n";
        if(errorI){
            fout<<"Case #"<<j+1<<": impossible\n";
            cout<<"Case #"<<j+1<<": impossible\n";
        }
        else{
            fout<<"Case #"<<j+1<<": "<<m-k<<"\n";
            cout<<"Case #"<<j+1<<": "<<m-k<<"\n";
        }
        
        
    }
    fin.close();
    fout.close();
    // insert code here...
    // std::cout << "Hello, World!\n";
    return 1;
}


