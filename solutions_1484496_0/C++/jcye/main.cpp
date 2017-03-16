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
#include <set>
#include <cmath>
int T;
int N;
std::vector<int> S;
std::vector<int> Choose;
std::vector<int> AF;
std::vector<int> NF;
std::ifstream fin("/Users/jcye/Downloads/C-small-attempt0.in");
std::ofstream fout("/Users/jcye/Downloads/C-small.out");

using namespace std;

int Judge()
{
    int Success = 0;
    int sum = 0;
    for(int i = 0; i < Choose.size(); i++)
    {
        sum = sum + S[Choose[i]];
    }
    int mycount = (int) pow(2.0,Choose.size()+0.0);
    for(int i = 1; i < mycount; i++)
    {
        int tempX = 0;
        AF.clear();
        NF.clear();
        for(int j = 0; j < Choose.size(); j++)
        {
            int flag = (i>>j)&1;
            if(flag)
            {
                tempX = tempX + S[Choose[j]];
                AF.push_back(S[Choose[j]]);
            }
            else
            {
                NF.push_back(S[Choose[j]]);
            }
        }
        if(tempX==sum/2)
        {
            for(int k = 0; k < AF.size(); k++)
            {
                fout<<AF[k]<<" ";
                cout<<AF[k]<<" ";
            }
            fout<<"\n";
            for(int k = 0; k < NF.size(); k++)
            {
                fout<<NF[k]<<" ";
                cout<<NF[k]<<" ";
            }
            fout<<"\n";
            return 1;
        }
    }
    return Success;
}


int main (int argc, const char * argv[])
{
    fin>>T;
    for(int i = 0;i < T; i++)
    {
        fin>>N;
        int temp;
        int X = 0;
        int sum = 0;
        S.clear();
        int count = 1024*1024;
        for(int j = 0;j < N; j++)
        {
            fin>>temp;
            X = X + temp;
            S.push_back(temp);
        }
        fout<<"Case #"<<i+1<<":\n";
        int GloablSuccess = 0;
        for(int j = 1; j < count; j++)
        {
            sum = 0;
            Choose.clear();
            for(int k = 0; k < 20; k++)
            {
                int flag = (j>>k)&1;
                if(flag==1)
                {
                    Choose.push_back(k);
                    sum = sum + S[k];
                }
            }
            if (sum%2==1)
                continue;
            else
            {
                GloablSuccess = Judge();
                if(GloablSuccess==1)
                {
                    break;   
                }
            }
        }
        if(GloablSuccess==0)
            fout<<"Impossible\n";
    }
    fin.close();
    fout.close();
    return 0;
}

