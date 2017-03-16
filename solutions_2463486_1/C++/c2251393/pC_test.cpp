#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;

bool is_palin(ll x)
{
	int dig[20], cnt = 0;
	ll t = x;
	while(t)
	{
		dig[cnt++] = t % 10;
		t /= 10;
	}
	for(int i = 0; i < cnt; i++)
		if(dig[i] != dig[cnt - i - 1])
			return false;
	return true;
}

vector<ll> ans;

int main()
{
	/*
	ll n;
	scanf("%lld", &n);
	freopen("table.txt", "w", stdout);
	printf("%lld %lld\n", 1112111, 1112111 * 1112111);
	*/
	freopen("C-large-1.in", "r", stdin);
	freopen("C-large-1.out", "w", stdout);
	for(ll i = 1; i <= 30000000ll; i++)
		if(is_palin(i) && is_palin(i * i))
			ans.push_back(i * i);//, printf("%lld\n", i * i);
	int t;
	scanf("%d", &t);
	for(int Case = 1; Case <= t; Case++)
	{
		ll A, B;
		printf("Case #%d: ", Case);
		scanf("%lld %lld", &A, &B);
		int r = upper_bound(ans.begin(), ans.end(), B) - ans.begin();
		int l = lower_bound(ans.begin(), ans.end(), A) - ans.begin();
		//printf("%lld %lld\n", ans[l - 1], ans[r - 1]);
		printf("%d\n", r - l);
	}
}
