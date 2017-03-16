#include <stdio.h>
#include <vector>
#include <map>
#include <hash_map>
#include <algorithm>
#include <utility>

using namespace std;

typedef long long ll;


ll tab[1000001];
ll reverse(ll n) {
	vector<ll> digits;

	while (n > 0) {
		digits.push_back(n%10ll);
		n /= 10ll;
	}

	ll ans = 0;

	for (int i=0; i<digits.size(); i++) {
		ans = ans * 10 + digits[i];
	}
	return ans;
}

ll t;

void ttt(ll s, ll time) {
	if (tab[s] >= time) {
		tab[s] = time;
	}
	else return;
	time ++;
	//1
	
	ttt(reverse(s), time);
	ttt(s+1, time);
}

int main()
{
	freopen("D:\\gcj\\a\\a.txt", "r", stdin);
	freopen("D:\\gcj\\a\\r.txt", "w", stdout);

	for (ll i=1; i <= 1000000; i++)
		tab[i] = i;
	for (ll i=1; i <= 1000000; i++) {
		ll x = reverse(i);
		ll time = tab[i] + 1;
		if (tab[x] > time) {
			tab[x] = time;
			for (ll j=x+1; j<=1000000; j++)
				tab[j] = min(tab[j], tab[x] + j-x);
		}
	}
	//ttt(1, 1);

	//for (ll i=1; i <= 1000000; i++)
	//	printf("%lld\n", tab[i]);
	//return 0;


	int ncase;
	scanf("%d\n", &ncase);
	for (int icase=1; icase<=ncase; icase++) {
		scanf("%lld", &t);
		printf_s("Case #%d: %lld\n", icase, tab[t]);
	}

	return 0;
}