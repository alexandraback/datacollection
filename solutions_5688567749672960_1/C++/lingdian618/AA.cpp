#include <stdio.h>
#include <iostream>
using namespace std;
typedef long long LL;
LL inv(LL x){
	LL r = 0;
	while(x){
		r = r*10 + x%10;
		x /= 10;
	}
	return r;
}
int main()
{
	// freopen("A-large.in", "r", stdin);
	// freopen("ou.txt", "w", stdout);
	int t, kase=0;
	scanf("%d", &t);
	while(t--){
		LL n;
		cin >> n;
		LL ans = 0;
		while(n){
			// printf("%lld\n", n);
			LL x = inv(n);
			if(n%10 && x<n)	n = x;
			else	n--;
			ans ++;
		}
		printf("Case #%d: ", ++kase);
		cout << ans << endl;
	}
	return 0;
}