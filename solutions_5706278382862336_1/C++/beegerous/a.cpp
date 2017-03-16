#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>
#include <stack>
#include <queue>
using namespace std;
const int maxn = 505;
typedef long long LL;

LL gcd(LL a, LL b)
{
	if(b == 0) return a;
	return gcd(b, a%b);
}

int main()
{
	int T, nc = 0;
	cin >> T;
	while(T--)
	{
		LL p, q;
		printf("Case #%d: ", ++nc);
		scanf("%lld/%lld", &p, &q);
		LL d = gcd(p, q);
		p /= d; q /= d;
		if(q != ((-q)&q)) { puts("impossible"); continue; }
		while(p != (p&(-p))) p -= p&(-p);
		q /= p;
		int ans;
		for(ans = 0; (q&(1<<ans)) == 0; ans++);
		cout << ans << endl;
	}
	return 0;
}