/*************************************************************************
	> File Name: pB.cpp
	> Author: fuyu0425/a0919610611
	> School: National Chiao Tung University
	> Team: NCTU_Ragnorok
	> Mail: a0919610611@gmail.com
	> Created Time: 2016/05/08 17:31:34   
 ************************************************************************/
#define op_io ios_base::sync_with_stdio(false); cin.tie(NULL);
#include <bits/stdc++.h>
using namespace std;
long long int pow(long long a,long long b)
{
    long long ans=1;
    long long base=a;
    while(b)
    {
        if(b&1) ans*=base;
        base*=base;
        b>>=1;
    }
    return ans;
}
int main()
{
    op_io;
    int T;
    cin>>T;
    int kase=0;
    while(T--)
    {
        cout<<"Case #1: ";
        long long int b,m;
        cin>>b>>m;
        int g[51][51]={};
        if(pow(2,b-2)<m)
        {
            cout<<"IMPOSSIBLE"<<endl;
        }else
        {
            cout<<"POSSIBLE"<<endl;
            if(b>2)
            {
                if(m&1)
                {
                    g[1][b]=1;
                }
            g[1][b-1]=1;
            vector<int>used;
            used.push_back(b-1);
            int index=b-2;
            for(int i=1;i<=63;i++)
            {

            if(index<=1) break; 
            g[1][index]=1;
            
                if(m&(1<<i))
                {
                    for(int j=0;j<used.size();j++)
                    {
                        g[used[j]][index]=1;
                    }
                    g[index][b]=1;
                }
            used.push_back(index);
            index--;
            }
            }else
            {
                g[1][2]=1;
            }
            for(int i=1;i<=b;i++)
            {
                for(int j=1;j<=b;j++)
                {
                    cout<<g[i][j];
                }
                cout<<endl;
            }
        }
    }
    return 0;
}
