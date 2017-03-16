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
const LL INF=0x3f3f3f3f;
const int maxn=3010;
vector<pair<string,string> >m;
vector<int>q(2100);
int h[2100];
set<string>p[2];
int main()
{
    //freopen("in.txt", "r", stdin);
    freopen("C-small-attempt1.in", "r", stdin);
    freopen("C-small-attempt1.out", "w", stdout);
    //map<long long int,int>ma;                 %I64d
    //vector<int>::iterator iter;
    //memset(m,0,sizeof(int));               for(iter=trtr[rt].begin();iter!=trtr[rt].end();iter++)
    //for(int x=1;x<=n;x++)
    //for(int y=1;y<=n;y++)
    //scanf("%d%d",&a,&b);
    //scanf("%d",&n);
    //printf("%d\n",ans);
    int T;
    scanf("%d",&T);
    char s1[30],s2[30];
    string h1,h2;
    for(int gg=1;gg<=T;gg++)
    {
        int n;
        scanf("%d",&n);
        m.clear();
        for(int x=1;x<=n;x++)
        {
            scanf("%s%s",s1,s2);
            h1=s1;
            h2=s2;
            m.pb(mp(h1,h2));
        }
        sort(all(m));
        int ans=0;
        q.clear();
        p[0].clear();
        p[1].clear();
        mem(h);
        int l,r;
        l=r=1000;
        for(int x=0;x<n;x++)
        {
            if(p[0].find(m[x].fi)!=p[0].end()&&p[1].find(m[x].se)!=p[1].end())
            {
                l--;
                h[l]=1;
                q[l]=x;
            }
            else
            {
                q[r]=x;
                r++;
                p[0].clear();
                p[1].clear();
                for(int y=r-1;y>=l;y--)
                {
                    if(p[0].find(m[q[y]].fi)!=p[0].end()&&p[1].find(m[q[y]].se)!=p[1].end())
                        h[y]=1;
                    p[0].insert(m[q[y]].fi);
                    p[1].insert(m[q[y]].se);
                }
            }
        }
        for(int x=l;x<r;x++)
            ans+=h[x];
        printf("Case #%d: %d\n",gg,ans);
    }
    return 0;
}

