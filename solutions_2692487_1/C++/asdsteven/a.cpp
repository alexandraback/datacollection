#include <cstdio>
#include <algorithm>

using namespace std;

int solve()
{
	int A, N;
	scanf("%d%d", &A, &N);
	int a[100];
	for (int i(0); i < N; i++)
		scanf("%d", a + i);
	if (A == 1)
		return N;
	sort(a, a + N);
	int ans(0), wer(N);
	for (int i(0); i < N; i++) {
		while (A <= a[i]) {
			A += A - 1;
			ans++;
		}
		A += a[i];
		wer = min(wer, ans + N - i - 1);
	}
	return wer;
}

int main()
{
	int T;
	scanf("%d", &T);
	for (int i(1); i <= T; i++)
		printf("Case #%d: %d\n", i, solve());
}