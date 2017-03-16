#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <queue>
#include <map>
#include <cstdio>
#include <iomanip>
#include <sstream>
#include <iostream>
#include <cstring>
#define REP(i,x,v)for(int i=x;i<=v;i++)
#define REPD(i,x,v)for(int i=x;i>=v;i--)
#define FOR(i,v)for(int i=0;i<v;i++)
#define FORE(i,t) for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define REMIN(x,y) (x)=min((x),(y))
#define REMAX(x,y) (x)=max((x),(y))
#define pb push_back
#define sz size()
#define mp make_pair
#define fi first
#define se second
#define ll long long
#define IN(x,y) ((y).find((x))!=(y).end())
#define un(v) v.erase(unique(ALL(v)),v.end())
#define LOLDBG
#ifdef LOLDBG
#define DBG(vari) cerr<<#vari<<" = "<<vari<<endl;
#define DBG2(v1,v2) cerr<<(v1)<<" - "<<(v2)<<endl;
#else
#define DBG(vari)
#define DBG2(v1,v2)
#endif
#define CZ(x) scanf("%d",&(x));
#define CZ2(x,y) scanf("%d%d",&(x),&(y));
#define CZ3(x,y,z) scanf("%d%d%d",&(x),&(y),&(z));
#define ALL(x) (x).begin(),(x).end()
#define tests int dsdsf;cin>>dsdsf;while(dsdsf--)
#define testss int dsdsf;CZ(dsdsf);while(dsdsf--)
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
template<typename T,typename TT> ostream &operator<<(ostream &s,pair<T,TT> t) {return s<<"("<<t.first<<","<<t.second<<")";}
template<typename T> ostream &operator<<(ostream &s,vector<T> t){s<<"{";FOR(i,t.size())s<<t[i]<<(i==t.size()-1?"":",");return s<<"}"<<endl; }

vector<pair<ll,int> > s;

int main()
{
    int T;cin>>T;
    FOR(te,T)
    {
        printf("Case #%d:\n",te+1);
        int n;cin>>n;
        vector<ll> v(n);
        FOR(i,n) cin>>v[i];
        sort(ALL(v));
        bool ok=0;
        int w1,w2;
        int cnt=0;
        while(!ok)
        {
            //DBG("gsd");
            cnt++;
            if (n==20 && cnt>10) break;
            s.clear();
            int d=min(n,24);
            FOR(i,(1<<d))
            {
                ll z=0;
                FOR(j,d) if ((1<<j)&i) z+=v[j];
                s.pb(mp(z,i));
            }
            sort(ALL(s));
            FOR(i,s.sz-1)
            {
                if (s[i].fi==s[i+1].fi)
                {
                    ok=1;
                    w1=s[i].se;
                    w2=s[i+1].se;
                    break;
                }
            }
            if (!ok) random_shuffle(ALL(v));
        }
        if (!ok)
        {
            puts("impossible");
        }
        else
        {
            FOR(i,30) if ((1<<i)&w1) cout<<v[i]<<" ";
            cout<<"\n";
            FOR(i,30) if ((1<<i)&w2) cout<<v[i]<<" ";
            cout<<"\n";
        }
    }

    return 0;
}
