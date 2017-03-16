#include <stdio.h>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;
typedef long long ll;
#define MAX_N (110)
int dp[MAX_N + 1];

ll calcIndex( int n, int K, int C ) {
    ll ret = 0;
    for ( int i = 0; i < C; i++ ) {
	ret *= K;
	ret += n;
    }

    return ret;
}

int main()
{
    int T;
    scanf("%d", &T);

    for ( int t = 0; t < T; t++ ) {
	int K, C, S;
	scanf("%d %d %d", &K, &C, &S);
	printf("Case #%d:", t + 1);
	if ( C == 1 ) {
	    if ( S >= K ) {
		for ( int i = 1; i <= K; i++ ) {
		    printf(" %d", i);
		}
		printf("\n");
	    }
	    else {
		printf(" IMPOSSIBLE\n");
	    }
	}
	else {			// C >= 2
	    int num_clean = (K >> 1) + (K % 2);
	    if ( S < num_clean ) printf(" IMPOSSIBLE\n");
	    else { 
		for ( int i = 0; i < K; i += 2 ) {
		    ll index = calcIndex( i, K, C );
		    if ( i < K - 1 ) index++;
		    printf(" %lld", index + 1);
		}
		printf("\n");
	    }
	}
    }
    
    return 0;
}
