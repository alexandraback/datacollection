#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <set>
#include <map>
#include <stack>
#include <queue>

using namespace std;

#define mp(a,b) make_pair(a,b)
#pragma comment(linker, "/STACK:102400000,102400000")

const int mod = 100007;
const double eps = 1e-8;
const int N = 1e5+3;
const double pi = acos(-1.0);
const int inf = 0x3f3f3f3f;

int gcd(int a,int b){return !b?a:gcd(b,a%b);}

struct union_set{

    int fa[1000003];

    void init(int n){
        for(int i=0;i<=n;i++)
            fa[i] = i;
        return ;
    }

    int getroot(int i){
        if(fa[i] != i)
            fa[i] = getroot(fa[i]);
        return fa[i];
    }

    void _union(int i,int j){
        fa[i] = j;
    }
}root;

int pow_mod(int a,int b,int c){

    long long ans = 1;

    while(b){
        if(b&1)
            ans = ans*a%c;
        a = 1ll*a*a%c;
        b >>= 1;
    }

    return ans%c;
}

/**
ID: xianbin5
PROG: hidden
LANG: C++
*/

//ofstream fout ("hidden.out");
//ifstream fin ("hidden.in");

int dp[1<<20];

int can(int now,int c,int w)
{
    int cnt = 0;
    for(int i=0;i<c;i++)
    {
        if((1<<i)&now)
            cnt=0;
        else cnt++;
        if(cnt>=w)return 1;
    }
    return 0;
}

int dfs(int now,int c,int w)
{
    if(dp[now] < inf)
        return dp[now];
    int ans = inf;
    for(int i=0;i<c;i++)
        if(!((1<<i)&now))
        {
            int u = now |(1<<i);
            if(can(u,c,w))
                ans = min(ans,dfs(u,c,w)+1);
            else {
                int cnt = 1;
                for(int j=i+1;j<c;j++)
                    if(!((1<<j)&u))
                        cnt++;
                    else break;
                for(int j=i-1;j>=0;j--)
                    if(!((1<<j)&u))
                        cnt++;
                    else break;
                if(cnt>w)
                    ans = min(ans,w+1);
                else ans = min(ans,w);
            }
        }
    return dp[now] = ans;
}

int gao(int c,int w)
{
    for(int i=0;i<(1<<c);i++)
        dp[i] = inf;
    return dfs(0,c,w);
}

int main()
{
    int t;
    cin >> t;
    int r,c,w;
    for(int cas = 1;cas<=t;cas++)
    {
        cin >> r >> c >> w;
        printf("Case #%d: %d\n",cas,r*gao(c,w));
    }
    return 0;
}
