#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stdio.h>
#define FOR(i,a)    for(int i = 0;i<a;i++)
#define REP(i,a,b)  for(int i = a;i<b;i++)
#define REPC(i,a,b,c)   for(int i = a;i<b;i+=c)

using namespace std;
int caseno = 1;

int gcd(int a,int b)
{
    if(!b)  return a;
    else    return gcd(b,a%b);
}

void solve();

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int t;
    cin>>t;
    FOR(i,t)    solve();
    return 0;
}

long long p[1001][1001] = {0};
void solve()
{
    int n;
    cin>>n;
    FOR(i,n)    FOR(j,n)    p[i][j] = 0;
    FOR(i,n)
    {
        int m;
        cin>>m;
        FOR(j,m)
        {
            int k;
            cin>>k;
            p[i][k-1] = 1;
        }
    }
    FOR(i,n)
    {
        FOR(j,n)
        {
            FOR(k,n)
            {
                p[j][k] = p[j][k] + p[j][i]*p[i][k];
            }
        }
    }
    bool flag = false;
    FOR(i,n)    FOR(j,n)    if(p[i][j] >= 2)    flag = true;
    cout<<"Case #"<<caseno<<": ";
    if(flag)    cout<<"Yes";
    else    cout<<"No";
    cout<<"\n";
    caseno++;
}
