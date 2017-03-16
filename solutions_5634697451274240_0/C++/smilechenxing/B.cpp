#pragma comment(linker, "/STACK:1024000000,1024000000")
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<cmath>
#include<queue>
#include<sstream>
#include<string>
#include<bitset>
#include<utility>
#include<numeric>
#include<assert.h>

using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define repn(i,a,n) for (int i=a;i<=n;i++)

typedef long long LL;
typedef unsigned long long ULL;

const LL LINF = (1LL <<60);
const int INF = 1 << 30;

const int NS = 100;
const int MS = NS + 1;
const int MOD = 1000000007;
const double PI = acos(-1.0);

#define form(_i, L, R) for (int (_i) = L; (i) <= (R); ++(_i))
inline bool isdigit(char ch){return ((ch<='9')and(ch>='0'));}
inline void read(int &x){
    char ch;
    bool flag=false;
    for (ch=getchar();!isdigit(ch);ch=getchar()) if (ch=='-') flag=true;
    for (x=0;isdigit(ch);x=x*10+ch-'0',ch=getchar());
    x=flag?-x:x;
}

char str[NS + 10];

int getVal(char cur)
{
    return ('+' == cur);
}

int solve(char* sk)
{
    int n = strlen(sk);
    if(n <= 0) return 0;

    int ans = 0;
    int pid = 1;
    char cur, pre = getVal(sk[0]);
    while(pid < n)
    {
        cur = getVal(sk[pid]);
        if(cur != pre)
        {
            ans++;
            pre = cur;
        }
        pid++;
    }
    if(!pre)
    {
        ans++;
    }
    return ans;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("B-small-attempt0.in", "r", stdin);
    freopen("B-small-attempt0.out", "w", stdout);
#endif
    int nCase;
    int ans;
    while(cin>>nCase)
    {
        for(int nT = 1; nT <= nCase; nT++)
        {
            cin>>str;
            int ans = solve(str);
            cout<<"Case #"<<nT<<": "<<ans<<endl;
        }
    }
    return 0;
}


//   __typeof(val.begin()) it = val.begin();
//ios::sync_with_stdio(false);
//cout<<setprecision(30);
