#include <iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#define INF 2000000000
#define MOD 1000000007
#define ull unsigned long long
#define loop(i, j, n)  for(int (i) = (j); i < n; i++)
#define sd(x) scanf("%d", &x)
#define slld(x) scanf("%lld", &x)

using namespace std;

ull gcd ( ull a, ull b )
{
	ull c;
	while ( a != 0 ) {
		c = a; a = b%a;  b = c;
	}
	return b;
}

int main() {
	int t;
	sd(t);
	loop(i, 0, t) {
		ull p, q;
		scanf("%llu/%llu", &p, &q);
		ull gcd_ = gcd(p, q), logq=0, temp, cnt=1;
		p /= gcd_;
		q /= gcd_;
		temp = q;
		bool impos = false;
		while(temp > 1) {
			if(temp&1) {
				impos = true;
				break;
			}
			temp >>= 1;
		}
		if(p > q) impos = true;
		if(!impos) {
			while(p < q>>1) {
				cnt++;
				q >>= 1;
			}
		}
		printf("Case #%d: ", i+1);
		if(impos) printf("impossible\n");
		else printf("%llu\n", cnt);
	}
	return 0;
}
