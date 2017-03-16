#include <cstdio>
#include <algorithm>
#include <cstring>
#include <utility>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <iostream>
#include <set>
#include <cmath>
#include <cassert>
#include <ctime>
#include <string>
#define fr(a,b,c) for(int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)
#define inf 0x3f3f3f3f
#define maxn 1111111
typedef long long ll;

using namespace std;

int T, N;
ll A, x[maxn];
ll test(int k) {
	ll op = N-k;
	ll B = A;
	rp(i,k) {
		while (B <= x[i]) B+=(B-1), op++;
		B+=x[i];
	}
	return op;
}

int main() {
	int cas = 1;
	scanf("%d", &T);
	while (T--) {
		scanf("%lld%d", &A, &N);
		rp(i,N) scanf("%lld", &x[i]);
		if (A == 1) printf("Case #%d: %d\n", cas++, N);
		else {
			sort(x,x+N);
			ll resp = inf;
			rp(i,N+1) resp = min(resp,test(i));
			printf("Case #%d: %lld\n", cas++, resp);
		}
	}
	return 0;
}