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
#define B (1<<15)
int pre1[1<<17];



int main()
{
    //ios_base::sync_with_stdio(0);
    int te;cin>>te;
    REP(tes,1,te)
    {
		DBG(tes);
		int a,b,k;cin>>a>>b>>k;
		k--;
		
		ll pre=0;
		int kb=k%B;
		//DBG(kb);
		FOR(i,B)
		{
			pre1[i]=0;
			FOR(j,B)
			{
				if ((i&j)<=kb) {pre++;pre1[i]++;}
			}
		}
		//DBG(pre);
		//a--;b--;k--;
		ll wyn=0;
		for(int i=0;i<=a-B;i+=B)for(int j=0;j<=b-B;j+=B)
		{
			if ((i&j)>k) continue;
			if ((i&j) + B-1<=k) wyn+=B*1LL*B;
			else
			{
				wyn+=pre;
			}
		}
		int am=a-a%B,bm=b-b%B;
		for(int i=am;i<a;i++)for(int j=0;j<=b-B;j+=B)
		{
			if ((i&j)>k) continue;
			if ((i&j) + B-1<=k) wyn+=B;
			else
			{
				wyn+=pre1[i%B];
			}
		}
		for(int i=bm;i<b;i++)for(int j=0;j<=a-B;j+=B)
		{
			if ((i&j)>k) continue;
			if ((i&j) + B-1<=k) wyn+=B;
			else
			{
				wyn+=pre1[i%B];
			}
		}
		for(int i=am;i<a;i++)for(int j=bm;j<b;j++) if ((i&j)<=k) wyn++;

		printf("Case #%d: %I64d\n",tes,wyn);
	}
    
    return 0;
}
