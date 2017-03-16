#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cstdlib>

using namespace std;
#define rep(i,a,b) for (int i=(a);i<=(b);i++)
#define repd(i,a,b) for (int i=(a);i>=(b);i--)

const int maxn=3000;
int a[maxn];
int b[maxn];
int n,m;

int main() {
	freopen("b.out","w",stdout);
	int T;scanf("%d\n",&T);
	rep(t,1,T) {
		printf("Case #%d:",t);
		scanf("%d\n",&n);
		memset(a,0,sizeof a);
		rep(i,1,n+n-1) {
			rep(j,1,n) {
				int x;scanf("%d\n",&x);
				a[x]++;
			}
		}
		m=0;
		rep(i,1,2500)
			if (a[i]&1) b[++m]=i;
		sort(b+1,b+m+1);
		rep(i,1,m) printf(" %d",b[i]);
		puts("");
	}
	return 0;
}
