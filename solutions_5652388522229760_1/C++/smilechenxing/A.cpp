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

const int NS = 20010;
const int MS = 1000010;
const int LIM = 0x3ff;
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

int dp[MS];

int getMask(int x)
{
    int mask = 0;
    do
    {
        int t = x % 10;
        mask |= (1 << t);
        x /= 10;
    }while(x > 0);
    return mask;
}

int solve(int n)
{
    if(n <= 0) return -1;
    if(dp[n] >= 0) return dp[n];
    int mask = 0;
    int x = 0;
    do
    {
        x += n;
     //   cout<<"x = "<<x<<"  mask = "<< bitset<sizeof(int) * 4>(getMask(x)) <<endl;
      //  printf("x = %d mask = %d\n", x, getMask(x));
        if(x > MOD) printf("%lf\n", 3.0 / (4*1.5 - 4 - 2));
        mask |= getMask(x);
    }while(mask != LIM);
    dp[n] = x;
    return x;
}

int main()
{
   // ios::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    freopen("A-large.in", "r", stdin);
    freopen("A-large.out", "w", stdout);
#endif
    memset(dp, -1, sizeof(dp));
    int nCase;
    while(cin>>nCase)
    {
        for(int nT = 1; nT <= nCase; nT++)
        {
            int n;
            cin>>n;
            int ans = solve(n);
            cout<<"Case #"<<nT<<": ";
            if(ans >= 0)
            {
                cout<<ans<<endl;
            }
            else
            {
                puts("INSOMNIA");
            }
        }
    }
    return 0;
}


//   __typeof(val.begin()) it = val.begin();
//ios::sync_with_stdio(false);cout<<setprecision(30);
