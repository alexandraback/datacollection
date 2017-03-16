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
int N;

void solve(int x)
{
    if (x == 0) {
	puts("INSOMNIA");
	return ;
    }

    int c = x;
    set<int> s;

    while (true) {
	int d = c;

	while (d > 0) {
	    s.insert(d % 10);
	    d /= 10;
	}

	if (s.size() == 10) {
	    printf("%d\n", c);
	    return ;
	}

	c += x;
    }
}

int main() {
    scanf("%d", &TC);

    for (int tc = 1; tc <= TC; ++tc) {
	printf("Case #%d: ", tc);
	scanf("%d", &N);
	solve(N);
    }

    return 0;
}
