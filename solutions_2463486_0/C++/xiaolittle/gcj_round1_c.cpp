#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX_N = 10000000;
long long num[100000];
int N = 0;

bool isPalindrome(long long a) {
	char s[20];
	sprintf(s, "%lld", a);
	int len = strlen(s);
	for (int i = 0, j = len - 1; i < j; ++i, --j) {
		if (s[i] != s[j]) {
			return false;
		}
	}
	return true;
}

void preProcess() {
	for (long long i = 1; i <= MAX_N; ++i) {
		if (isPalindrome(i) && isPalindrome(i * i)) {
			num[N++] = i * i;
			//printf("%lld\n", i * i);
		}
	}
}

int calc(long long k) {
	return upper_bound(num, num + N, k) - num;
}

int main() {
	int T;
	int cas = 0;

	//freopen("C-small-attempt0.in", "r", stdin);
	//freopen("C-small-attempt0.txt", "w", stdout);

	preProcess();
	scanf("%d", &T);
	while (T--) {
		long long A, B;
		scanf("%lld%lld", &A, &B);
		printf("Case #%d: %d\n", ++cas, calc(B) - calc(A - 1));
	}
	return 0;
}

	
