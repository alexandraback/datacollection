#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
#include <vector>
#include <set>
#include <map>

using namespace std;

long long gcd(long long a, long long b){
	while(a && b){
		if(a > b)
			a %= b;
		else
			b %= a;
	}
	return a + b;
}

int main(){
	int t, ct, ans, tc = 0;
	long long p, q, tmp;
	scanf("%d", &t);
	while(t--){
		scanf("%lld/%lld", &p, &q);
		//printf("%lld/%lld\n", p, q);
		long long g = gcd(p, q);
		p /= g, q /= g;
		tmp = q, ct = 0;
		while(tmp){
			if(tmp & 1)
				ct++;
			tmp >>= 1;
		}
		printf("Case #%d: ", ++tc);
		if(ct != 1){
			puts("impossible");
			continue;
		}
		ans = 0;
		while(p < q){
			q >>= 1;
			ans++;
		}
		printf("%d\n", ans);
	}
	return 0;
}
