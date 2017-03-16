#include <bits/stdc++.h>

using namespace std;
// Constants and macros
#define INF 		(int)1e9
#define EPS 		1e-9
#define bitcount 	__builtin_popcount
#define gcd 		__gcd
#define forall(i,a,b) 	for(int i=a;i<b;i++)
#define pb 		push_back
#define mp		make_pair
#define MAX(a,b)	( (a)>(b) ? (a):(b))
#define MIN(a,b)	( (a)<(b) ? (a):(b))
#define s(a)		scanf("%d", &a)
#define ss(a,b)		scanf("%d %d", &a,&b)
#define sss(a,b,c)	scanf("%d %d %d", &a,&b,&c)
#define sl(a)		scanf("%I64d", &a)

int T, N;
int fr[1004], vis[1004], tim[1004], bes[1004], rt[1005];

int t, btime, unr, root;
void dfs(int n){
	//cout << n;
	if (vis[n] != -1) {
		if (fr[fr[n]] ==n){ // special case of bff
			btime = 2;
			bes[fr[n]] = bes[n] = btime;
			rt[n] = n; rt[fr[n]]=fr[n];
			unr = 2;
			root = n;
		}
		else if (bes[n]==0) { //reached real loop first time
			btime = t - tim[n]+1;
			btime = -btime;
			unr = 1005;
			root = n;
		}
		else if (bes[n] > 0) {
			btime = bes[n];
			root = rt[n];
			unr = 1005;
		}
		else if (bes[n] < 0) {
			btime = bes[n];
			root = n;
		}
		return;
	}
	else {
		t++;
		tim[n] = t;
		vis[n]=1;
		dfs(fr[n]);
	}
	if (bes[n]==0) {
		if (btime > 0 ) btime++;
		bes[n] = btime;
		rt[n] = root;
	}
}

int main(){
	s(T);
	forall(i,0,T){
		s(N);
		memset(fr, 0, sizeof fr);
		memset(vis, -1, sizeof vis);
		memset(tim, 0, sizeof tim);
		memset(bes, 0, sizeof bes);
		memset(rt, 0, sizeof rt);
		forall(i, 0, N){
			s(fr[i]);
			fr[i]--;
		}
		int lc= -1;
		forall(j,0,N){
			if (vis[j]!=-1) continue;
			unr = t = btime = 0;
			dfs(j);
		}
		int bess[2222] = {0};
		forall(j,0,N){
		//	cout << endl <<bes[j] <<" "<< rt[j] << endl;
			if (bes[j] <0)	lc = MAX(lc, - bes[j]);
			else {
				bess[rt[j]] = MAX(bess[rt[j]],bes[j]);
			}
		}
		forall(j,0,N){
			if (bess[j] != 0)
				lc = MAX(lc, bess[j]+bess[fr[j]]-2);
		}
		printf("Case #%d: %d\n", i+1, lc);
	}
}
