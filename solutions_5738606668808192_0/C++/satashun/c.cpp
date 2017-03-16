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
int N, J;
int u[40];

int main() {
    scanf("%d %d %d", &TC, &N, &J);
    printf("Case #1:\n");

    int num = (N - 4) / 2;
    for (int i = 0; J && i < (1 << (num)); ++i, --J) {
	u[0] = u[N - 1] = 1;

	int c = 2;
	rep(j, num) {
	    bool f = (i >> j) & 1;
	    u[c] = u[c + 1] = f;
	    c += 2;
	}
	rep(j, N) printf("%d", u[j]);
	for (int j = 2; j <= 10; ++j) printf(" %d", j + 1);
	puts("");
    }

    return 0;
}
