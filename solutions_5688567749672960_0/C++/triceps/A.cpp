#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int rev(int x)
{
	char str[32] = {0};
	sprintf(str, "%d", x);

	auto n = strlen(str);
	reverse(str + 0, str + n);
	return atoi(str);
}

int main()
{
	int T = 0;
	cin >> T;

	const int N = 1000000;
	vector<int> v(N + 1, N * 2);
	v[0] = 0;
	for (int i = 1; i <= N; i++) {
		auto r = rev(i);
		v[i] = min(v[i], v[i - 1] + 1);
		if (r <= N)
			v[r] = min(v[r], v[i] + 1);
	}

	for (int t = 0; t < T; t++) {
		__int64 N = 0;
		cin >> N;
		printf("Case #%d: %d\n", t + 1, v[N]);
	}

	return 0;
}
