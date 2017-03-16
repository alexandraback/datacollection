#include <bits/stdc++.h>

using namespace std;

typedef long long Int;

void solve()
{
	Int N;
	scanf("%lld", &N);

	bool digits[10] = {0};
	for (int i = 1; i <= 1000000; i++){
		Int M = N * i;
		while (M){
			digits[M % 10] = true;
			M /= 10;
		}
		bool ok = true;
		for (int j = 0; j < 10; j++) ok &= digits[j];
		if (ok){
			printf("%lld\n", N * i);
			return;
		}
	}

	printf("INSOMNIA\n");
}

int main()
{
	int T;
	scanf("%d", &T);

	for (int i = 0; i < T; i++){
		printf("Case #%d: ", i + 1);
		solve();
	}

	return (0);
}