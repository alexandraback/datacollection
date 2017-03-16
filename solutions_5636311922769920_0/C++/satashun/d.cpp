#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef vector<int> vi;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define rep(i,n) rep2(i,0,n)
#define rep2(i,m,n) for(int i=m;i<(n);i++)
#define ALL(c) (c).begin(),(c).end()

int TC;
int K, C, S;

int main() {
    scanf("%d", &TC);

    for (int tc = 1; tc <= TC; ++tc) {
	printf("Case #%d:", tc);

	scanf("%d %d %d", &K, &C, &S);

	if (K > S) puts(" IMPOSSIBLE");
	else {
	    rep(i, K) {
		ll u = 0;
		rep(j, C) u = u * K + i;
		printf(" %lld", u + 1);
	    }
	    puts("");
	}
    }

    return 0;
}
