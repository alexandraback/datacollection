#include <stdio.h>
int main(){
	static int T, caso, i, j, k, a, b, pref[20], p10[20], w[2000001], passo, n, ans;
	scanf("%d",&T);
	for(caso=1;caso<=T;caso++){
		scanf("%d %d",&a,&b);
		ans = 0;
		p10[0] = 1;
		for(i = 1; i < 20; i++)
			p10[i] = 10 * p10[i-1];
		for(i=a;i<b;i++) {
			for(j = i, n = 0; j != 0; j /= 10, n++)
				pref[n] = j % 10 * p10[n] + (n ? pref[n-1] : 0);
			++passo;
			for(j=0;j+1<n;j++) {
				int x = pref[j], y = pref[n-1] - x;
				int z =  x * p10[n-j-1] + y / p10[j+1];
				x = x * p10[n-j-1] + y / p10[j+1];
				if(i < x && x <= b) {
					ans += w[x] != passo;
					w[x] = passo;
				}
			}
		}
		printf("Case #%d: %d\n",caso,ans);
	}
	return 0;
}
