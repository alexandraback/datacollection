#include <bits/stdc++.h>
using namespace std;
#define fo(i,n) for(int i=0;i<(n);i++)
#define upd(a,b) (a)=min((a),(b))

int T, r, c, w, ans;

int main(){
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
	scanf("%d\n", &T);
	for(int z = 1; z <= T; z++) {
		scanf("%d %d %d", &r, &c, &w);
		ans = r * (c/w) + w - 1;
		if(c % w) ans++;
		/*
		int leftad = c % w;
		int rightad = leftad + w * (c/w) - c;
		ans += min(leftad, rightad);
		*/
		printf("Case #%d: %d\n", z, ans);
	}
}
