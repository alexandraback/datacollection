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

const int NS = 110;
const int MS = 210;
const int MOD = 1000000007;
const double PI = acos(-1.0);

#define form(_i, L, R) for (int (_i) = L; (i) <= (R); ++(_i))
inline bool isdigit(char ch)
{
    return ((ch<='9')and(ch>='0'));
}
inline void read(int &x)
{
    char ch;
    bool flag=false;
    for (ch=getchar(); !isdigit(ch); ch=getchar()) if (ch=='-') flag=true;
    for (x=0; isdigit(ch); x=x*10+ch-'0',ch=getchar());
    x=flag?-x:x;
}

int B;
LL M;
int ans[NS][NS];
LL cnt[NS];

void printans()
{

    for(int i = 0; i < B; i++)
    {
        for(int j = 0; j < B; j++)
        {
            printf("%d", ans[i][j]);
        }
        puts("");
    }
}

int main()
{
    // ios::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    freopen("B-large.in", "r", stdin);
    freopen("B-large.out", "w", stdout);
#endif

    cnt[0] = cnt[1] = 1;
    for(int i = 2; i < NS; i++)
    {
        cnt[i] = cnt[i - 1] * 2;
    }
    int nCase;
    while(cin>>nCase)
    {
        for(int nT = 1; nT <= nCase; nT++)
        {
            cin>>B>>M;
            LL maxv = 1;
            for(int i = 1; i <= B - 2; i++)
            {
                maxv *= 2;
            }
            if(maxv < M)
            {
                printf("Case #%d: IMPOSSIBLE\n", nT);
                continue;
            }
            printf("Case #%d: POSSIBLE\n", nT);

            memset(ans, 0, sizeof(ans));


            ans[0][B - 1] = 1;  M--;
            int pos = 1;
            while(M > 0)
            {
            //    printf("pos = %d M = %I64d\n", pos, M);
                ans[pos][B - 1] = 1;
                for(int j = pos - 1; j >= 0; j--)
                {
                    if(M >= cnt[j])
                    {
                        ans[j][pos] = 1;
                        M -= cnt[j];
                 //       printf("--->j = %d M = %I64d\n", j, M);
                    }
                }
                pos++;
            }
            printans();
        }
    }
    return 0;
}


//   __typeof(val.begin()) it = val.begin();
// ios::sync_with_stdio(false);
// cout<<setprecision(30);
