#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0; i<int(n); ++i)
#define out(x) cout<<#x"="<<x<<endl
int f[1123456];
int rev(int x) {
	int y = 0;
	while(x){
		y=y*10+x%10;
		x/=10;
	}
	return y;
}
void init() {
	memset(f, -1, sizeof f);
	f[1] = 1;
	for (int i = 2; i<=1000000; ++i) {
		if (f[i] == -1 || f[i] > f[i-1] + 1) f[i] = f[i-1] + 1;
		int y=rev(i);
		if (y>1000000) continue;
		if (f[y] == -1 || f[y] > f[i] + 1) {
			f[y] = f[i] + 1;
		}
	}
}
int main() {
	init();
	int T;
	scanf("%d",&T);
	REP(tt,T){
		int n;
		scanf("%d", &n);
		printf("Case #%d: %d\n", tt+1, f[n]);
	}
}