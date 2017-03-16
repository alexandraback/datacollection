#include <bits/stdc++.h>
using namespace std;
#define TR(i,v) 		for(__typeof((v).begin())i=(v).begin();i!=(v).end();++i)
#define DEBUG(x) 		cout << #x << " = "; cout << x << endl;
#define SIZE(p) 		(int)(p).size()
#define MP(a, b)		make_pair((a), (b))
#define ALL(p)			(p).begin(), (p).end()
#define rep(i, n)		for(int (i)=0; (i)<(int)(n); ++(i))
#define REP(i, a, n)	for(int (i)=(a); (i)<(int)(n); ++(i))
#define FOR(i, a, b)   	for(int (i)=(int)(a); (i)<=(int)(b); ++(i))
#define FORD(i, b, a)  	for(int (i)=(int)(b); (i)>=(int)(a); --(i)) 
typedef long long LL;
typedef pair<int, int> pii;
int A[50], B[50], K[50], C[50];
LL dp1[50], dp2[50], res;
int pa[50], pb[50], pk[50];
void print(LL x, int s[]) {	
	rep(i, 32)	s[i]=(x>>(32-i-1)&1);	
}
LL get(int x) {
	if(x==-1)	return 2;
	else		return 1;
}
LL gao(int a, int b) {
	if(a==-1) {
		if(b==-1)	return 3;
		if(b==0)	return 2;
		if(b==1)	return 1;
	}
	if(a==0) {
		if(b==-1) 	return 2;
		if(b==0)	return 1;
		if(b==1)	return 1;
	}
	if(a==1) {
		if(b==-1)	return 1;
		if(b==0)	return 1;
		if(b==1)	return 0;
	}
	assert(false);
	return 0;
}
void dfs(int k) {
	if(k==3) {
		LL c=1;
		rep(i, 32) {
			if(~pk[i]) {
				if(pk[i]) {
					if(pa[i]==0 || pb[i]==0)
						c=0;					
				}else{
					c*=gao(pa[i], pb[i]);
				}
			}else{
				c *= get(pa[i])*get(pb[i]);
			}
		}
		res+=c;
		return;
	}
	if(k==0) {
		memset(pk, -1, sizeof(pk));
		rep(i, 32) {
			if(K[i]) {
				pk[i]=0;
				dfs(k+1);
				pk[i]=K[i];
			}else
				pk[i]=K[i];
		}
	}else if(k==1) {
		memset(pa, -1, sizeof(pa));
		rep(i, 32) {
			if(A[i]) {
				pa[i]=0;
				dfs(k+1);
				pa[i]=A[i];
			}else
				pa[i]=A[i];
		}
	}else {
		memset(pb, -1, sizeof(pb));
		rep(i, 32) {
			if(B[i]) {
				pb[i]=0;
				dfs(k+1);
				pb[i]=B[i];
			}else
				pb[i]=B[i];
		}
	}
}
int main(int argc, char const *argv[])
{
	#ifndef ONLINE_JUDGE
    freopen("B.in", "r", stdin);	
    freopen("B.out", "w", stdout);
    #endif
	// ios::sync_with_stdio(false);    cin.tie(0);
	int T;	cin>>T;
	FOR(cs,1,T) {
		printf("Case #%d: ", cs);
		LL aa, bb, kk;
		cin>>aa>>bb>>kk;
		print(aa, A), print(bb, B), print(kk, K);		
		res=0;
		dfs(0);
		cout<<res<<"\n";
	}
	return 0;
}
