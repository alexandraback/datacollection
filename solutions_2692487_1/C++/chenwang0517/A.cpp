#include <cstdio>
#include <algorithm>
using namespace std;

long long cur, a[1000010];
int ans, cnt, cases, n;

int main(){
	scanf("%d",&cases);
	for (int tot = 0; tot < cases; ++tot){
		scanf("%lld%d",&cur,&n);
	  cnt = 0;
		ans = n;
		for (int i = 0; i < n; ++i) scanf("%lld", &a[i]);
		sort(a,a+n);
		for (int i = 0; i < n; ++i){
			if (cur > a[i]){
				cur += a[i];
				if ((i + 1 == n) && (cnt < ans)) ans = cnt;
			}
			else{
				if (cnt + (n - i) < ans) ans = cnt + (n - i);
				if (cur > 1){
					while (cur <= a[i]){
						cur += cur - 1;
						cnt = cnt + 1;
					}
					cur += a[i];
					if ((i + 1 == n) && (cnt < ans)) ans = cnt;
				}
				else break;
			}
		}
		printf("Case #%d: %d\n", tot + 1, ans);
	}
}