#include <stdio.h>
#include <algorithm>
#include <queue>
#include <vector>
#include <set>

using namespace std;
typedef long long ll;

ll solve( int N ) {
    set<int> digit;
    ll cur = N;
    while ( true ) {
	ll tmp = cur;
	while ( tmp > 0 ) {
	    digit.insert( tmp % 10 );
	    tmp /= 10;
	}

	if ( digit.size() == 10 ) break;
	cur += N;
    }

    return cur;
}

int main()
{
    int T;
    scanf("%d", &T);
    
    for ( int t = 0; t < T; t++ ) {
	int N;
	scanf("%d", &N);
	if ( N == 0 ) {
	    printf("Case #%d: INSOMNIA\n", t+1);
	}
	else {
	    ll ans = solve( N );
	    printf("Case #%d: %lld\n", t+1, ans);
	}
    }

    return 0;
}
