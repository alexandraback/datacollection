#include <cstdio>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;

int solve()
{
	int N, v[1024];

	scanf("%d", &N);

	for (int i = 0; i < N; i++){
		scanf("%d", v + i);
	}

	int maxi = *max_element(v, v + N);
	int ret = maxi;

	for (int i = 1; i <= maxi; i++){
		int tmp = i;
		for (int j = 0; j < N; j++){
			tmp += max(0, (v[j] + i - 1) / i - 1);
		}
		ret = min(ret, tmp);
	}

	return (ret);
}

int main()
{
	int T;

	scanf("%d", &T);

	for (int i = 0; i < T; i++){
		printf("Case #%d: %d\n", i + 1, solve());
	}

	return (0);
}