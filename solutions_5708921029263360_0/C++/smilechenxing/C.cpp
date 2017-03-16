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
const int INF = 0x3f3f3f3f;

const int NS = 22;
const int MS = 1111;
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

int J, P, S, K;
int cnt[NS][NS];
int ans[NS][3], top;

void pushans(int a, int b, int c)
{
    ans[top][0] = a;
    ans[top][1] = b;
    ans[top][2] = c;
    cnt[a][b]++;
    cnt[b][c]++;
    cnt[a][c]++;
    top++;
}

bool isOK(int a, int b, int c)
{
    if(a > 0 && b > 0 && c > 0)
    {
        if(cnt[a][b] < K && cnt[b][c] < K && cnt[a][c] < K)
        {
            return true;
        }
    }
    return false;
}

void dfs(int mask)
{
    int c = mask % 10;
    int b = (mask/10) % 10;
    int a = (mask/100) % 10;
    if(c > S) c = S;
    if(b > P) b = P;
    if(a > J) a = J;

    if(a <= 0) return ;

    if(isOK(a, b, c))
    {
        pushans(a, b, c);
    }
    dfs(a * 100 + b * 10 + c - 1);
}


int main()
{
   // ios::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    freopen("C-small-attempt0.in", "r", stdin);
    freopen("C-small-attempt0.out", "w", stdout);
#endif
    int nCase;
    while(cin>>nCase)
    {
        for(int nT = 1; nT <= nCase; nT++)
        {
            cin>>J>>P>>S>>K;
            memset(cnt, 0, sizeof(cnt));
            top = 0;
            dfs(J * 100 + P * 10 + S);

            printf("Case #%d: %d\n", nT, top);
            for(int i = 0; i < top; i++)
            {
                printf("%d %d %d\n", ans[i][0], ans[i][1], ans[i][2]);
            }
        }
    }
    return 0;
}


//   __typeof(val.begin()) it = val.begin();
// ios::sync_with_stdio(false);
// cout<<setprecision(30);
