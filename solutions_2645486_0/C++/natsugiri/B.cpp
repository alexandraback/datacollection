#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
#include<stack>
using namespace std;

typedef long long LL;

int E, R, N, v[10010];

LL rec(int l, int r, int g, int h) {
    if (r-l<1) return 0;
    int p=l;
    for (int i=l; i<r; i++) if (v[p]<v[i]) p=i;
    LL f=E;
    if (g) f=min(f, (p-l+1LL)*R);
    if (h) {
	LL x, y=LL(R)*(r-p);
	if (g) x=min(LL(E), (p-l+1LL)*R);
	else x=E;

	if (y+x<E) f=0;
	else if (E<=y) f=min(f, x);
	else f=min(f, x+y-E);
    }
    return f*v[p] + rec(l, p, g, 1) + rec(p+1, r, 1, h);
}

int main() {
    int T;
    scanf("%d", &T);
    for (int tc=1; tc<=T; tc++) {
	scanf("%d%d%d", &E, &R, &N);
	for (int i=0; i<N; i++) scanf("%d", v+i);

	LL ans=rec(0, N, 0, 0);
	printf("Case #%d: %lld\n", tc, ans);
    }
    return 0;
}
