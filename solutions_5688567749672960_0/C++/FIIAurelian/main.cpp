#include <iostream>
#include <cstdio>
#include <string>
#include <queue>
#include <vector>
#include <deque>
#include <algorithm>
#define ll long long
using namespace std;

int revers(int X)
{
    int sol = 0;
    while(X)
    {
        sol = sol * 10 + X % 10;
        X = X / 10;
    }
    return sol;
}


int N, T, DP[1000010],i,in_q[1000010];
deque<int> Q;
vector<int> V[1000010];

int main()
{
    freopen("file.in","r",stdin);
    freopen("file.out","w",stdout);
    for(i=1;i<=1e6;i++)
    {
        DP[i] = 1e6 + 10;
        V[i].push_back(i+1);
        if(revers(i) != i)
            V[i].push_back(revers(i));
    }
    DP[1] = 1;
    Q.push_back(1);
    in_q[1] = 1;
    while(!Q.empty())
    {
        int x = Q.front();
        for(vector<int>::iterator it = V[x].begin();it!=V[x].end();it++)
        {
            if(DP[*it] > DP[x] + 1)
            {
                DP[*it] = DP[x] + 1;
                if(!in_q[*it])
                    Q.push_back(*it);
                in_q[*it] = 1;
            }
        }
        Q.pop_front();
    }
    cin>>T;
    for(int t = 1; t <= T; t++)
    {
        cin>>N;
        cout<<"Case #"<<t<<": "<<DP[N]<<"\n";
    }
    return 0;
}
