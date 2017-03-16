#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <map>
#include <vector>
#include <queue>
#include <set>

#define SZ 100006
#define INF (1<<29)
using namespace std;

int c,d,v,A[SZ];

int dp[SZ];

bool Possible(set<int>st)
{
	for(int i=0;i<=v;i++) dp[i] = 0;
	dp[0] = 1;
	for(set<int>::iterator it = st.begin();it!=st.end();it++) {
		int vl = *it;
		for(int i=v;i>=vl;i--) {
			if(dp[i-vl]==1) dp[i] = 1;
		}
	}
	for(int i=1;i<=v;i++) {
		if(dp[i]==0) return false;
	}
	return true;
}

int main()
{
	freopen("Csm.txt","rt",stdin);
	freopen("Can2.txt","wt",stdout);
	int tst,cas;
	scanf("%d",&tst);
	for(cas=1;cas<=tst;cas++) {
		scanf("%d%d%d",&c,&d,&v);
		for(int i=0;i<d;i++) scanf("%d",&A[i]);

		int mn = min(v,15);
		int ans = INF;
		for(int i=0;i<(1<<mn);i++) {
			set<int>st;
			int cnt = 0;
			for(int j=0;j<mn;j++) {
				if( (1<<j) & i) st.insert(j+1);
			}
			for(int j=0;j<d;j++) st.insert(A[j]);
			cnt += (st.size() - d);
			if(Possible(st)) {
				ans = min(ans,cnt);
			}

		}

		for(int i=1;i<=v;i++) {
			set<int>st;
			int cnt = 0;
			for(int j=0;j<d;j++) st.insert(A[j]);
			st.insert(i);
			cnt += (st.size() - d);
			if(Possible(st)) {
				ans = min(ans,cnt);
			}

		}
		//for(int n=1;n<=v;n++)
		for(int m=1;m<=v;m++)
		for(int l=m;l<=v;l++)
		for(int k=l;k<=v;k++)
		for(int i=k;i<=v;i++) {
			set<int>st;
			int cnt = 0;
			for(int j=0;j<d;j++) st.insert(A[j]);
			st.insert(i);
			st.insert(k);
			st.insert(l);
			st.insert(m);
			//st.insert(n);
			
			cnt += (st.size() - d);
			if(Possible(st)) {
				ans = min(ans,cnt);
			}

		}



		printf("Case #%d: %d\n",cas,ans);


	}
	return 0;
}