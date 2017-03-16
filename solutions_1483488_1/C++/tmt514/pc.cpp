#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int u[2000005], ucs=0;
int go(int x, int A, int B) {
	int w[20]={}, wn=0, ans=0;
	int d=x;
	while(d>0) { w[wn++] = d%10; d/=10; }
	for(int i=0;i<wn;i++) w[wn+i]=w[i];
	for(int i=0;i<wn;i++) {
		d=0;
		for(int j=wn-1;j>=0;--j) d=d*10+w[i+j];
		if(d>x && d>=A && d<=B && u[d]!=ucs) {u[d]=ucs; ++ans;}
	}
	return ans;
}

void solve() {
	int ans=0, A, B;
	scanf("%d%d", &A, &B);
	for(int i=A;i<=B;i++,++ucs) ans += go(i, A, B);
	static int cs=0;
	printf("Case #%d: %d\n", ++cs, ans);
}

int main(void) {
	int T;
	scanf("%d", &T);
	while(T--) solve();
	return 0;
}
