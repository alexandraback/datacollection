#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

__int64 rev(__int64 x)
{
	char str[32] = {0};
	sprintf(str, "%lld", x);

	auto n = strlen(str);
	reverse(str + 0, str + n);
	return _atoi64(str);
}

int main()
{
	int T = 0;
	cin >> T;

	const __int64 E[] = { 91, 901, 9901, 99001, 999001, 9990001, 99990001, 999900001, 9999900001, 99999000001, 999999000001, 9999990000001, 99999990000001 };
	const __int64 B[] = { 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000, 10000000000, 100000000000, 1000000000000, 10000000000000, 100000000000000 };
	const __int64 S[] = { 10, 10, 100, 100, 1000, 1000, 10000, 10000, 100000, 100000, 1000000, 1000000, 10000000, 10000000 };
	const __int64 S2[] = { 1, 1, 10, 10, 100, 100, 1000, 1000, 10000, 10000, 100000, 100000, 1000000, 1000000, 10000000, 10000000 };
	map<__int64, __int64> m;
	for (int i = 1; i < 20; i++) m[i] = i;
	for (int i = 12; i < 20; i++) m[rev(i)] = m[i] + 1;
	for (int i = 1; i <= 13; i++) {
		m[B[i]] = m[E[i-1]] + S[i] - 1;
		for (__int64 j = B[i] + S2[i] + 1; j < B[i] + S[i]; j++){
			auto d = j - B[i];
			auto x = B[i] + rev(d);
			m[rev(x)] = m[B[i]] + x - B[i] + 1;
		}
	}

	for (int t = 0; t < T; t++) {
		__int64 N = 0;
		cin >> N;

		auto it = m.lower_bound(N);
		__int64 ans = 0;
		if (it->first == N) {
			ans = it->second;
		}
		else {
			--it;
			ans = it->second + N - it->first;
		}

		printf("Case #%d: %lld\n", t + 1, ans);
	}

	return 0;
}
