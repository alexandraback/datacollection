#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>
#include <vector>
#include <set>
#include <map>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int M = 20005;
const int inf = 0x7fffffff;

int T;
ll A, B;
vector<ll> have;

bool check(ll x)
{
	char a[20], b[20];
	int t;
	int cnt = 0;
	while(x)
	{
		t = x % 10;
		a[cnt++] = '0' + t;
		x /= 10;
	}
	for(int i = 0; i < cnt; i++)
	{
		b[cnt - i - 1] = a[i];
	}
	for(int i = 0; i < cnt; i++)
	{
		if(a[i] != b[i])
			return false;
	}
	return true;
}

int main()
{
	freopen("C-small-attempt0.in", "r", stdin);
	freopen("C-out.out", "w", stdout);
	ll tmp;
	have.clear();
	for(int i = 1; i <= 1000; i++)
	{
		if(check(i))
		{
			tmp = (ll)(i) * (ll)(i);
			if(check(tmp))
			{
				have.push_back(tmp);
			}
		}
	}
	scanf("%d", &T);
	int cs = 1;
	while(T--)
	{
		scanf("%lld%lld", &A, &B);
		int len = have.size();
		ll ans = 0;
		for(int i = 0; i < len; i++)
		{
			if(have[i] < A)
				continue;
			if(have[i] > B)
				break;
			ans++;
		}
		printf("Case #%d: %lld\n", cs++, ans);
	}
	return 0;
}
