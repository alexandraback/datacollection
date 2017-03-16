#include <cstdio>
#include <algorithm>
#include <climits>
using namespace std;

int reverse(int n) {
    if (n < 9)
    	return n;
    if ( n % 10 == 0 )
    	return INT_MAX;
    int rev = 0;
    while (n) {
    	rev *= 10;
    	rev += n % 10;
    	n /= 10;
    }
    return rev;
}

int sol(int N) {
	if ( N < 10 )
		return N;
    int DP[N + 1];
    int i;
    int rev;
    for (i = 0; i < 10; i++) {
    	DP[i] = i;
    }
    for (i = 10; i <= N; i++) {
    	rev = reverse(i);
    	if (rev < i)
    		DP[i] = min(DP[i - 1], DP[rev]) + 1;
    	else
    		DP[i] = DP[i - 1] + 1;
    	//printf("%d: %d\n", i, DP[i]);
    }
    return DP[N];
}

int main() {
	int T, N;
	int i;
	scanf("%d", &T);
    for (i = 1; i <= T; i++) {
    	scanf("%d", &N);
    	printf("Case #%d: %d\n", i, sol(N));
    	//printf("%d\n", reverse(N));
    }
}