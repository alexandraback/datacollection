#include <iostream>
#include <iomanip>
#include <climits>
#include <stack>
#include <fstream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <cassert>

#define FOR(i,n) for(int i=0,_n=n;i<_n;i++)
#define FORR(i,s,n) for(int i=s,_n=n;i<_n;i++)
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define pli pair<ll,int>
#define vi vector<int>
#define fs first
#define sec second

#define maxn 100000

using namespace std;
typedef long long ll;

const ll MOD = 1000000007LL;

int usp[11][11];
int usj[11][11];
int upj[11][11];
int j,p,s,k;
vector<pair<int,pii> > rez;

bool vredu(int mask){
	memset(usp,0,sizeof(usp));
	memset(usj,0,sizeof(usj));
	memset(upj,0,sizeof(upj));
	FOR(i,rez.size()){
		if(!(mask & (1<<i)))continue;
		if(upj[rez[i].sec.fs][rez[i].fs]>=k)return 0;
		if(usj[rez[i].sec.sec][rez[i].fs]>=k)return 0;
		if(usp[rez[i].sec.sec][rez[i].sec.fs]>=k)return 0;
		upj[rez[i].sec.fs][rez[i].fs]++;
		usj[rez[i].sec.sec][rez[i].fs]++;
		usp[rez[i].sec.sec][rez[i].sec.fs]++;
	}
	return 1;
}

void solve(int prim){
	scanf("%d%d%d%d",&j,&p,&s,&k);
	rez.clear();
	FOR(i,j)FOR(l,p)FOR(u,s)rez.pb(mp(i,mp(l,u)));
	vector<pair<int,pii> > best;
	best.clear();
	FOR(i,(1<<((int)(rez.size())))){
		if(__builtin_popcount(i)>(int)best.size() && vredu(i)){
			best.clear();
			FOR(j,rez.size())
				if(i&(1<<j))best.pb(rez[j]);
		}
	}
	printf("Case #%d: %d\n",prim,(int)best.size());
	FOR(i,best.size())printf("%d %d %d\n",best[i].fs+1,best[i].sec.fs+1,best[i].sec.sec+1);
}

int main(){
	int n;
	scanf("%d",&n);
	FORR(i,1,n+1)solve(i);
	return 0;
}
