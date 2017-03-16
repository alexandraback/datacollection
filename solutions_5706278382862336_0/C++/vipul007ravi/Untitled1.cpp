#include<bits/stdc++.h>
using namespace std;
long long int gcd(long long int a, long long int b)
{
	if (b == 0)
		return a;
	else 
		gcd(b, a % b);
}
int main()
{
	freopen("A-small-attempt1.in", "r", stdin);
	freopen("my.out", "w", stdout);
	long long int i, t, p, q, l = 1;
	scanf("%lld", &t);
	char arr[100];
	while (t--) {
		//scanf("%lld%lld", &p, &q);
		scanf("%s", arr);
		p = 0;
		q = 0;
		i = 0;
		while (arr[i] != '/') {
			p = p * 10 + arr[i] - 48;
			i++;
		}
		i++;
		while (arr[i] != '\0') {
			q = q * 10 + arr[i] - 48;
			i++;
		}
		long long int g = gcd(q, p);
		p = p / g;
		q = q / g;
		long long int qq = q, c = 0;
		while (qq % 2 == 0) {
			c++;
			qq = qq / 2;
		}
		long long int f = 0;
		if (qq == 1) {
			while (p < q / 2) {
				q = q / 2;
				f++;
			}
			f++;
			printf("Case #%lld: %lld\n", l++, f);
			//if (p == 1)
			//	printf("Case #%lld: %lld\n", l++, f);
			//else
			//	printf("Case #%lld: 1\n", l++);
		} else {
			printf("Case #%lld: impossible\n", l++);
		}
	}
	return 0;
}
