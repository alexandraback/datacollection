#include <bits/stdc++.h>
#include <ext/numeric>
#include <hash_map>
using namespace std;
using namespace __gnu_cxx;

#define oo			1e9
#define OO			1e18
#define EPS			1e-7
#define f			first
#define s			second
#define pi 			acos(-1.0)
#define ll			long long
#define ld			long double
#define ull			unsigned long long
#define sz(x)		(int)x.size()
#define all(x)		x.begin(),x.end()
#define rall(x)		x.rbegin(),x.rend()
#define popCnt(x)   __builtin_popcount(x)

int T;
int k,c,s;

long long pwr(long long base, long long pw){
	long long res = 1;
	while (pw){
		if (pw % 2 == 1)res *= base;
		base *= base;
		pw /= 2;
	}
	return res;
}


int main() {
#ifndef ONLINE_JUDGE
	freopen("D-small-attempt0.in", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif
	scanf("%d",&T);
	for(int C=1;C<=T;C++){
		scanf("%d%d%d",&k,&c,&s);
		printf("Case #%d:",C);
		long long stp=pwr(k,c-1),cur=1;
		for(int i=1;i<=s;i++)
			printf(" %lld",cur),cur+=stp;
		printf("\n");
	}
}
