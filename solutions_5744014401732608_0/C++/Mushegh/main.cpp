#include <iostream>
#include <stdio.h>
#include <vector>
#include <map>
#include <string>
#include <cstring>
#include <set>
#include <algorithm>
#include <cmath>
using namespace std;
long long b,m,i,j,t;
long long Q = 1;
long long ast[70];
bool mark[52][52];
vector <long long> v;
bool M[52];
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin>>t;
    ast[0] = 1;
    for(i=1;i<=62;i++) ast[i] = ast[i-1]*(long long)2;
    while(t)
    {
        t--;
        cin>>b>>m;
        cout<<"Case #"<<Q<<": ";
        Q++;
        if(m > ast[b-2])
        {
            cout<<"IMPOSSIBLE"<<endl;
            continue;
        }
        cout<<"POSSIBLE"<<endl;
        v.clear();
        // 2, 3, ... B-1
        long long t = 0;
        while(ast[t] < m) t++;
        // t<=B-2
        for(i=2;i<=t+1;i++) v.push_back(i);
        for(i=1;i<=b;i++)
            for(j=1;j<=b;j++) mark[i][j] = false;
        for(i=0;i<=b;i++) M[i] = false;
        long long F = ast[t];
        for(i = (long long)(v.size())-1;i>=0;i--)
        {
            if(F-ast[i] >= m)
            {
                F-=ast[i];
                M[i] = true;
            }
        }
        
        for(i = (long long)(v.size())-1;i>=0;i--)
        {
            for(j=i-1;j>=0;j--)
            {
                mark[v[i]][v[j]] = true;
            }
        }
        for(i=0;i<v.size();i++)
        {
            if(!M[i]) mark[1][v[i]] = true;
            mark[v[i]][b] = true;
        }
        mark[1][b] = true;
        for(i=1;i<=b;i++)
        {
            for(j=1;j<=b;j++) cout<<mark[i][j];
            cout<<endl;
        }
    }
    return 0;
}