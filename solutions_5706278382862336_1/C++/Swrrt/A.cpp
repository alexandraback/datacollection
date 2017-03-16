#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

void solve(long long A, long long B)
{
	long long t = B;
	while (t > 1) {
		if (t & 1) {
			puts("impossible");
			return;
		}
		t >>= 1;
	}
	for (int i = 1; i <= 40; ++ i) {
		if (A + A >= B) {
			printf("%d\n", i);
			return;
		}
		B /= 2;
	}
	puts("impossible");
}

int main()
{
	int T;
	scanf("%d", &T);
	for (int no = 1; no <= T; ++ no) {
		long long A, B;
		scanf("%I64d/%I64d", &A, &B);
		long long d = __gcd(A, B);
		A /= d;
		B /= d;
		
		printf("Case #%d: ", no);
		solve(A, B);
	}
	return 0;
}

