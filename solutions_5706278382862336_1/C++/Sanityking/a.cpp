#include <iostream>
#include <cstdio>
using namespace std;

int t;
long long ans;
long long gcd(long long a, long long b){ return(b == 0 ? a : gcd(b, a%b)); }

int main(){
	scanf("%d", &t);
	long long i, j;
	for(int a = 1; a <= t; ++a){
		scanf("%lld/%lld", &i, &j);
		ans = 0;
		int div = gcd(i, j);
		i /= div;
		j /= div;
		long long temp = j;
		while(temp > 1){
			if(temp%2 != 0){
				ans = -1;
				break;
			}
			temp /= 2;
		}
		if(ans == -1){
			printf("Case #%d: impossible\n", a);
			continue;
		}
		while(i < j){
			i *= 2;
			++ans;
			//cout << i << ": " << ans << endl;
		}
		printf("Case #%d: %lld\n", a, ans);
	}
	return 0;
}
