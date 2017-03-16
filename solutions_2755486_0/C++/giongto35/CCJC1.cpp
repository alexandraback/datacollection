#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <queue>
using namespace std ;

#define FOREACH(it,c) for( __typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define FOR(i,a,b) for( int i=(a),_b=(b);i<=_b;i++)
#define DOW(i,b,a) for( int i=(b),_a=(a);i>=_a;i--)
#define REP(i,n) FOR(i,0,(n)-1)
#define DEP(i,n) DOW(i,(n)-1,0)
#define all(a) (a).begin() , (a).end()
#define push(a,b) (a).push_back((b))

typedef vector<int> VI ;
typedef vector<string> VS ;
template<class T> inline int size(const T&c) { return c.size(); }

using namespace std;
const int maxn = 20;
int di[maxn],ni[maxn],wi[maxn],ei[maxn],si[maxn],ddi[maxn],dpi[maxn],dsi[maxn];

struct event
{
    int l;
    int r;
    int s;
    int d;
} e[100000];
int spt,bd,kt;
int a[100000+10];
const int con = 50000;
int res,n,T;

bool mycmp(event a,event b)
{
    return a.d<b.d;
}

int main()
{
    freopen("C-small-attempt0.in","r",stdin);
    freopen("CCJC1.out","w",stdout);
    cin>>T;
    FOR(st,1,T)
    {
        cin>>n;
        spt=0;
        FOR(i,1,n)
        {
            cin>>di[i]>>ni[i]>>wi[i]>>ei[i]>>si[i]>>ddi[i]>>dpi[i]>>dsi[i];
            FOR(j,1,ni[i])
            {
                spt++;
                e[spt].l=wi[i]+dpi[i]*(j-1);
                e[spt].r=ei[i]+dpi[i]*(j-1);
                e[spt].s=si[i]+dsi[i]*(j-1);
                e[spt].d=di[i]+ddi[i]*(j-1);
            }
        }
        sort(e+1,e+1+spt,mycmp);
        e[spt+1].d=-123124;
        e[0].d=-12321;
        memset(a,0,sizeof(a));
        res=0;
        //FOR(i,1,spt)
        //cout<<e[i].l<<' '<<e[i].r<<' '<<e[i].s<<' '<<e[i].d<<endl;
        //cout<<endl;
        FOR(i,1,spt)
        {
            if (e[i].d!=e[i-1].d) bd=i;
            if (e[i].d!=e[i+1].d)
            {
                kt=i;
                //cout<<bd<<' '<<kt<<endl;
                FOR(j,bd,kt)
                {
                    bool ok=false;
                    FOR(k,con+e[j].l*2,con+e[j].r*2) if (a[k]<e[j].s) ok=true;
                    if (ok) res++;
                }

                FOR(j,bd,kt)
                {
                    FOR(k,con+e[j].l*2,con+e[j].r*2) a[k]=max(a[k],e[j].s);
                }

            }
        }
        cout<<"Case #"<<st<<": "<<res<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

