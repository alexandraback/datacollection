#include <iostream>
#include <string>
#include <fstream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ifstream cinn("input.txt");
    ofstream coutt("output.txt");
    int T;
    cinn>>T;
    for(int iii=0;iii<T;iii++)
    {
        coutt<<"Case #"<<iii+1<<": ";
        vector<int> bin;
        long long int tower,slide;
        cinn>>tower>>slide;
        long long int max=pow(2,tower-2);
        if(max<slide)
        {
            coutt<<"IMPOSSIBLE"<<endl;
            continue;
        }
        coutt<<"POSSIBLE"<<endl;
        int map[51][51]={0,};
        for(int i=0;i<tower;i++)
        {
            for(int j=0;j<tower;j++)
            {

                if(j>i)map[i][j]=1;
            }
        }
        if(max==slide)
        {
            for(int i=0;i<tower;i++)
            {
                for(int j=0;j<tower;j++)
                {

                    if(j>i)map[i][j]=1;
                    coutt<<map[i][j];
                }
                coutt<<endl;
            }
            continue;
        }
        int tmp=slide;
        for(;;)
        {
            if(tmp<=0)break;
            bin.push_back(tmp%2);
            tmp/=2;
        }
        reverse(bin.begin(),bin.end());
        coutt<<'0';
        for(int i=0;i<tower-bin.size()-2;i++)coutt<<'0';
        for(int i=0;i<bin.size();i++)coutt<<bin[i];
        coutt<<'0'<<endl;
        for(int i=1;i<tower;i++)
            {
                for(int j=0;j<tower;j++)
                {

                    if(j>i)map[i][j]=1;
                    coutt<<map[i][j];
                }
                coutt<<endl;
            }

    }
    return 0;
}
