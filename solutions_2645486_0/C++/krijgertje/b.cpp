#include <algorithm>  
#include <iostream>  
#include <sstream>  
#include <string>  
#include <vector>  
#include <queue>  
#include <set>  
#include <map>  
#include <cstdio>  
#include <cstdlib>  
#include <cctype>  
#include <cmath>  
#include <list>  
#include <climits>
#include <cassert>
using namespace std;  

#define PB push_back  
#define MP make_pair  
#define SZ(v) ((int)(v).size())  
#define FOR(i,a,b) for(int i=(a);i<(b);++i)  
#define REP(i,n) FOR(i,0,n)  
#define FORE(i,a,b) for(int i=(a);i<=(b);++i)  
#define REPE(i,n) FORE(i,0,n)  
#define FORSZ(i,a,v) FOR(i,a,SZ(v))  
#define REPSZ(i,v) REP(i,SZ(v))  
typedef long long ll;  

ll bf(int E,int R,int n,vector<ll> v) {
	vector<ll> dp(E+1,0);
	for(int i=n-1;i>=0;--i) {
		vector<ll> ndp(E+1,0);
		REPE(j,E) {
			int nj=min(E,j+R);
			ndp[j]=dp[nj];
			if(j>0&&v[i]+ndp[j-1]>ndp[j]) ndp[j]=v[i]+ndp[j-1];
		}
		dp=ndp;
	}
	return dp[E];
}

void run(int casenr) {
	int E,R,n; scanf("%d%d%d",&E,&R,&n);
	vector<ll> v(n); REP(i,n) scanf("%lld",&v[i]);

	ll ret=0;
	int cur=-1,cap=E-R;
	deque<int> q;
	for(int i=n-1;i>=0;--i) {
		while(!q.empty()&&v[q.back()]<=v[i]) q.pop_back();
		int rem=i==0?E:R;
		if(cur==-1||v[cur]<=v[i]) {
			ret+=v[i]*rem; cur=i; cap=E-rem;
//			printf("\tassigning %d to %d (%d)\n",i,cur,rem);
		} else {
			q.push_back(i);
			while(rem>0) {
				if(cap==0) {
					assert(!q.empty());
					cap=min(E,R*(cur-q.front())); cur=q.front(); q.pop_front();
				}
				int now=min(rem,cap);
				ret+=v[cur]*now; rem-=now; cap-=now;
//				printf("\tassigning %d to %d (%d)\n",i,cur,now);
			}
		}
	}
	printf("Case #%d: %lld\n",casenr,ret);
//	ll check=bf(E,R,n,v);
//	if(check!=ret) printf("\tExpected %lld\n",check);
}


int main() {
	int n; scanf("%d",&n); FORE(i,1,n) run(i);
	return 0;
}
