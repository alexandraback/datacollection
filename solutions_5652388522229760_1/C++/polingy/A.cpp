#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <cmath>

#include <iostream>
#include <iomanip>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <queue>
#include <stack>
#include <utility>
#include <vector>
#include <functional>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

ll lastEnc(int N);

int main()
{
	int T;
	scanf("%d", &T);
	for (int tc = 1; tc <= T; ++tc) {
		int N;
		scanf("%d", &N);
		ll temp = lastEnc(N);
		if (temp > 0)
			printf("Case #%d: %lld\n", tc, lastEnc(N));
		else
			printf("Case #%d: %s\n", tc, "INSOMNIA");
	}
}

ll lastEnc(int N)
{
	int tab[10];
	for (int i = 0; i < 10; ++i)
		tab[i] = 0;

	int lim = 1e7 + 10, cnt = 0;
	for (ll i = 1; i <= lim; ++i) {
		ll temp = i * N;
		while(temp) {
			if (!tab[temp % 10])
				++cnt;
			tab[temp % 10] = 1;
			temp /= 10;
		}
		if (cnt == 10) {
			return i * N;
		}
	}

	return -1;
}
