#include <iostream>
#include <cstdio>
#include <string>
#include <queue>
#include <vector>
#include <deque>
#include <algorithm>
#define ll long long
using namespace std;


ll noua(ll x)
{
    ll res = 0;
    while(x--)
    {
        res = res * 10 + 9;
    }
    return res;
}

ll calc1(string S)
{
    ll res = 0;
    for(int i = S.size()/2 - 1; i>=0; i--)
    {
        res = res * 10 + (S[i] - '0');
    }
    return res;
}
ll calc2(string S)
{
    ll res = 0;
    for(int i = S.size()/2; i<S.size(); i++)
    {
        res = res * 10 + (S[i] - '0');
    }
    return res;
}
ll stringToInt(string S)
{
    ll res = 0;
    for(int i = 0; i < S.size(); i++)
        res = res * 10 + (S[i] -'0');
    return res;
}
string intToString(ll x)
{
    string S;
    S.clear();
    while(x)
    {
        S.push_back(x % 10 + '0');
        x = x / 10;
    }
    reverse(S.begin(), S.end());
    return S;
}


ll T, sol[20];
string N;

int main()
{
    freopen("file.in","r",stdin);
    freopen("file.out","w",stdout);
    sol[1] = 1;
    sol[2] = 10;
    for(int i=3;i<=15;i++)
    {
        sol[i] = sol[i-1] + noua((i-1)/2) + noua((i-1) - ((i-1) / 2));
        if((i-1) - ((i-1) / 2))
            sol[i] = sol[i] + 1;
    }
    cin>>T;
    for(int t = 1; t <= T; t++)
    {
        cin>>N;
        int cnt = 0;
        if(N.size() == 1)
        {
            cout<<"Case #"<<t<<": "<<N<<"\n";
            continue;
        }
        if(N[N.size()-1] == '0')
        {
            cnt = 1;
            N = intToString(stringToInt(N) - 1);
        }
        ll jumatatea1 = calc1(N);
        ll jumatatea2 = calc2(N);
        ll solutie1 = sol[N.size()] + jumatatea2;
        if(jumatatea1 > 1)
        {
            solutie1 += jumatatea1 + 1;
        }
        ll solutie2 = sol[N.size()] + jumatatea1 + jumatatea2;
        cout<<"Case #"<<t<<": "<<min(solutie1, solutie2)+cnt<<"\n";
    }
    return 0;
}
