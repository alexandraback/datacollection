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
#define LOLDBG1
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

#define INF (1<<29)

priority_queue<pair<int,int> > Q;



#define D 111

int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};
int H,N,M;
int pd[D][D],sf[D][D];
int opt[D][D];
bool dod[D][D];

void dijkstra()
{
    FOR(i,N)FOR(j,M) dod[i][j]=0;
    FOR(i,N)FOR(j,M) opt[i][j]=INF;
    opt[0][0]=0;
    Q.push(mp(0,0));
    while(!Q.empty())
    {
        int p=(Q.top()).se;
        int a=p/D,b=p%D;
        if (dod[a][b]) 
        {
            Q.pop();
            continue;
        }
        opt[a][b]=-((Q.top()).fi);
        Q.pop();
        dod[a][b]=1;
        int T=opt[a][b];
        DBG(mp(a,b));
        FOR(k,4)
        {
            int a1=a+dx[k],b1=b+dy[k];
            if (a1<0 || b1<0 || a>=N || b1>=M) continue;
            if (sf[a1][b1]-pd[a1][b1]<50) continue;
            if (sf[a1][b1]-pd[a][b]<50) continue;
            if (sf[a][b]-pd[a1][b1]<50) continue;
            if (dod[a1][b1]) continue;
            int t=T;
            DBG(mp(a1,b1));
            REMAX(t,H-(sf[a1][b1]-50));
            REMAX(t,H-(sf[a][b]-50));
            DBG(t);
            if (t==0)
            {
                opt[a1][b1]=0;
                Q.push(mp(0,a1*D+b1));
            }
            else
            {
                int w;
                if (H-t>=pd[a][b]+20)
                {
                    w=t+10;
                    
                }
                else w=t+100;
                if (opt[a1][b1]>w)
                {
                    opt[a1][b1]=w;
                    Q.push(mp(-w,a1*D+b1));
                }
            }
        }
    }
}

int main()
{
    int T;cin>>T;
    FOR(te,T)
    {
        
        printf("Case #%d: ",te+1);
        cin>>H>>N>>M;
        FOR(i,N) FOR(j,M) cin>>sf[i][j];
        FOR(i,N) FOR(j,M) cin>>pd[i][j];
        dijkstra();
        printf("%.1lf\n",0.1*opt[N-1][M-1]);
    }

    return 0;
}
