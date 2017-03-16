//
//  main.cpp
//  A
//
//  Created by Jinchao Ye on 5/5/12.
//  Copyright (c) 2012 Stanford. All rights reserved.
//

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
int T;
int N;
std::vector<float> S;
std::ifstream fin("/Users/jcye/Downloads/A-small-attempt4.in");
std::ofstream fout("/Users/jcye/Downloads/A-small.out");

using namespace std;


int main (int argc, const char * argv[])
{
    fin>>T;
    for(int i = 0;i < T; i++)
    {
        fin>>N;
        float temp;
        int X = 0;
        S.clear();
        int count = 0;
        int money = 0;
        for(int j = 0;j < N; j++)
        {
            fin>>temp;
            X = X + temp;
            S.push_back(temp);
        }
        for(int j = 0; j < N; j++)
        {
            if(S[j]<(2*X/N))
            {
                count = count + 1;
                money = money + S[j];
            }
        }
        fout<<"Case #"<<i+1<<": ";
        for(int j = 0;j < N; j++)
        {
            cout<<S[j]<<"\n";
            cout<<(2.0/N - S[j]/X)<<"\n";
            if(S[j] >= 2*X/N)
                fout<<0<<" ";
            else
            {
                fout<<setprecision(10)<<100*(money+X-S[j]*count)/(count*X)<<" ";
            }
        }
        fout<<"\n";
    }
    fin.close();
    fout.close();
    return 0;
}

