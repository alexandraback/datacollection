#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <iostream>

using namespace std;

long long f[20100],add[20100];
int v[10010];
int n,M,R;
int T;

void update( long long &x, long long y ){
	if (y>x) x=y;
}

long long solve( int st, int en, long long len, long long men ){
	if (st>en) return 0;
	long long mi=st;
	for (int i=st; i<=en; ++i)
		if (v[i]>v[mi]) mi=i;
	long long leastleft=max(0LL, men-(en-mi+1)*R);
	long long maxhave=min((long long)M, (mi-st)*R+len);
	long long use=min((long long)M, maxhave-leastleft);
	long long t1=solve(st, mi-1, len, leastleft+use);
	long long t2=solve(mi+1, en, leastleft+R, men);
	return t1+t2+use*v[mi];
}

int main(){
	int test=0;
	scanf("%d", &test);
	for (T=1; T<=test; ++T){
		memset(f,0,sizeof(f));
		scanf("%d %d %d", &M, &R, &n);
		if (R>M) R=M;
		for (int i=0; i<n; ++i){
			scanf("%d", v+i);
		}
		printf("Case #%d: %lld\n", T, solve(0,n-1,M,0));
	}
}
