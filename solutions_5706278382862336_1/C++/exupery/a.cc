#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long ll;
ll gcd(ll a, ll b);
ll gcd(ll a, ll b)
{
	return b ? gcd(b,a%b):a;
}
int main()
{
	int T,TT;
	scanf("%d",&T);
	TT=T;
	while(T--) {
		int ans=0;
		char str[555];
		scanf("%s", str);
		ll p,q;
		char *pch = strtok(str, "/");
		p = atol(pch);
		pch = strtok(NULL, "/");
		q = atol(pch);
		ll g = gcd(p,q);
		p /= g;
		q /= g;
		bool s2=0;
		for (int i=0; i<63; i++) {
			if ((q & (~(1<<i))) == 0) {
				s2=1;				
			}
		}
		if (s2==0) {
			printf("Case #%d: impossible\n", TT-T);
			continue;
		}

		for (int i=0; i<40; i++) {
			ll g = gcd(p,q);
			p /= g;
			q /= g;
			if (p >= q) {
				ans = i;
				break;
			}
			p *= 2;
		}
		printf("Case #%d: %d\n", TT-T, ans);
	}
	return 0;
}
