//
//  main.cpp
//  test2
//
//  Created by Liubing Yu on 5/3/14.
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
    int T,j,R,C,M,i,k,sum;
    ifstream fin;    // Input file stream
    ofstream fout;   //Output file stream
    fin.open ("/Users/liubingyu/Desktop/B-small-attempt0.in");
    fout.open("/Users/liubingyu/Desktop/B-small-attempt0.out.txt");
    fin>>T;
    //  std::cout << T<<"Hello, World!\n";
    for(j=0;j<T;j++){
        fin>>R>>C>>M;
        sum=0;
         // we caculate the number that ending in i
        for(i=0;i<R;i++){
            for(k=0;k<C;k++){
                if((i&k)<M)sum++;
            }
        }
        fout<<"Case #"<<j+1<<": "<<sum<<"\n";
        cout<<"Case #"<<j+1<<": "<<sum<<"\n";
        
    }
    fin.close();
    fout.close();
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}



