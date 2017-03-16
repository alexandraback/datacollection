#include <stdio.h>
#include <algorithm>
#include <string>
#include <vector>
#include <utility>
using namespace std;
typedef pair<int, int> P;

int n;
double mi[1000];
double ken[1000];


P solve() {
	sort(mi, mi+n);
	sort(ken, ken+n);
	// normal
	// if Noami tell > max(ken), ken use the smallest
	// else ken use the first > told
	//deciful 
	// if Noami has wood < min(ken), use it to remove ken's largest, since it won't win.
	// else Noami tell > max(ken), cheat to win.
	int d = 0;
	int msmall = 0, mlarge = n-1;
	int ksmall = 0, klarge = n-1;
	while (msmall <= mlarge) {
		while (msmall <= mlarge && mi[msmall]< ken[ksmall]) {
			--klarge;
			++msmall;
		}
		while (msmall <= mlarge && mi[msmall] > ken[ksmall]) {
			++d;
			++msmall;
			++ksmall;
		}
	}

	int r = 0;
	int s = 0, t = 0;
	while (s < n && t < n && mi[s] < ken[n-1])
	{
		while (t<n && ken[t] < mi[s]) {
			++t;
		}
		++t;
		++s;
	}
	r = n-s;
	return P(d, r);
}
int main() {
	int T;
	scanf("%d", &T);
	for (int i = 0; i < T; ++i)
	{
		scanf("%d", &n);
		for (int j = 0; j < n; ++j)
		{
			scanf("%lf", &mi[j]);
		}
		for (int j = 0; j < n; ++j)
		{
			scanf("%lf", &ken[j]);
		}
		P p = solve();
		printf("Case #%d: ", i+1);

		printf("%d %d\n", p.first, p.second);

	}
	return 0;
}