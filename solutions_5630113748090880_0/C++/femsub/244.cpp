//#include <bits/stdc++.h>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>
#include <algorithm>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <bitset>
#include <string>
using namespace std;
double esp=1e-11;
//#pragma comment(linker, "/STACK:1024000000,1024000000")
#define fi first
#define se second
#define all(a) (a).begin(),(a).end()
#define cle(a) while(!a.empty())a.pop()
#define mem(p) memset(p,0,sizeof(p))
#define memf(p) memset(p,0x3f,sizeof(p))
#define memn(p) memset(p,-1,sizeof(p))
#define mp(A, B) make_pair(A, B)
#define pb push_back
#define lson l , m , rt << 1
#define rson m + 1 , r , rt << 1 | 1
typedef long long int LL;
typedef long double LD;
const double PI = acos(-1.0);
const LL INF=0x3f3f3f3f3f3f3f3f;
const LL MOD =1000000007ll;
const int maxn = 100050;
int h[3000];
vector<int>ans;
int main()
{
    //freopen("in.txt", "r", stdin);
    freopen("B-small-attempt1.in", "r", stdin);
    freopen("B-small-attempt1.out", "w", stdout);
    //map<long long int,int>ma;                 %I64d
    //vector<int>::iterator iter;
    //memset(m,0,sizeof(int));               for(iter=trtr[rt].begin();iter!=trtr[rt].end();iter++)
    //for(int x=1;x<=n;x++)
    //for(int y=1;y<=n;y++)
    //scanf("%d%d",&a,&b);
    //scanf("%d",&n);
    //printf("%d\n",ans);
    int T,n;
    scanf("%d",&T);
    for(int gg=1;gg<=T;gg++)
    {
        scanf("%d",&n);
        int mi=3000,tem;
        mem(h);
        for(int x=1;x<=2*n-1;x++)
        {
            for(int y=1;y<=n;y++)
            {
                scanf("%d",&tem);
                h[tem]++;
            }
        }
        ans.clear();
        for(int x=0;x<3000;x++)
            if(h[x]&1)
                ans.pb(x);
        printf("Case #%d: ",gg);
        for(int x=0;x<n;x++)
        printf("%d ",ans[x]);
        putchar('\n');
    }
    return 0;
}
