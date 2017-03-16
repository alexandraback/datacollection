//darkstallion's template

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<vector>
#include<map>
#include<list>
#include<set>
#include<stack>
#include<queue>
#include<algorithm>
#include<cmath>
#include<string>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define popb pop_back
#define del erase
#define sz size
#define ins insert
#define FOR(a,b,c) for(int a = b; a < c; a++)
#define FORS(a,b,c) for(int a = b; a <= c; a++)
#define FORN(a,b) for(int a = 0; a < b; a++)
#define FORD(a,b,c) for (int a = b; a >= c; a--)
#define RES(a,b) memset(a,b,sizeof(a))
#define LL long long
#define PII pair<int,int>
#define PLL pair<long long,long long>
#define PDD pair<double,double>
#define PCC pair<char,char>
#define PSS pair<string,string>
#define PI 3.1415926535897932384626433832795
#define eps 1e-9
using namespace std;

int main()
{
	int t;
	scanf("%d",&t);
	FORN(i,t)
	{
		int N,arr[1000];
		RES(arr,0);
		scanf("%d",&N);
		map<int,vector<PII> > data;
		int d[N],n[N],w[N],e[N],s[N],deld[N],delp[N],dels[N];
		FORN(j,N)
		{
			scanf("%d%d%d%d%d%d%d%d",&d[j],&n[j],&w[j],&e[j],&s[j],&deld[j],&delp[j],&dels[j]);
			w[j] += 500;
			e[j] += 500;
			FORN(k,n[j])
				data[d[j]+k*deld[j]].pb(mp(j,k));
		}
		map<int,vector<PII> >::iterator it;
		int ans = 0;
		int tmp[1000];
		for (it = data.begin(); it != data.end(); it++)
		{
			RES(tmp,0);
			FORN(j,it->se.sz())
			{
				bool menang = true;
				FOR(k,w[it->se[j].fi]+it->se[j].se*delp[it->se[j].fi],e[it->se[j].fi]+it->se[j].se*delp[it->se[j].fi])
				{
					if (arr[k] < s[it->se[j].fi]+it->se[j].se*dels[it->se[j].fi])
						menang = false;
					tmp[k] = max(tmp[k],s[it->se[j].fi]+it->se[j].se*dels[it->se[j].fi]);
				}
				if (!menang)
					ans++;
			}
			FORN(j,1000)
				arr[j] = max(arr[j],tmp[j]);
		}
		printf("Case #%d: %d\n",i+1,ans);
	}
}
