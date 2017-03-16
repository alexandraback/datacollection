#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <set>
#include <ctime>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <cassert>
#include <climits>
#include <fstream>

using namespace std;

#define Filename ""
#define sqr(a) (a)*(a)

typedef long long lng;
typedef long double ldb;

const double EPS = 1e-8;

int N, was[1005], a[1005], b[1005];

void Load()
{
	scanf ("%d", &N);

	for (int i = 0;i < N;i++)
		scanf ("%d%d", &a[i], &b[i]); 
}

void Solve()
{
	memset (was, 0, sizeof (was));
	int ans = 0, all = 2 * N, stars = 0;

	while (all > 0) {
		bool found = false;
	 	for (int i = 0;i < N;i++)
	 		if (was[i] < 2 && b[i] <= stars) {
	 		 	stars += 2 - was[i];
	 		 	ans++;
	 		 	all -= 2 - was[i];
	 		 	was[i] = 2;
	 		 	found = true;
	 		}
	 	if (found) continue;
	 	int pos = -1;
	 	for (int i = 0;i < N;i++) {
	 	 	if (was[i]) continue;
	 	 	if (a[i] > stars) continue;
	 	 	if (pos == -1 || b[i] > b[pos]) {
	 	 	 	pos = i;
	 	 	}
	 	}
	 	if (pos == -1) break;
	 	all--;
	 	stars++;
	 	was[pos] = 1;
	 	ans++;
	}
	if (all == 0) {
	 	printf ("%d\n", ans);
	}
	else printf ("Too Bad\n");
}

int main()
{
	freopen(Filename"a.in", "r", stdin);
	//freopen(Filename".out", "w", stdout);

	int t;
	cin >> t;

	for (int i = 0;i < t;i++) {
		printf ("Case #%d: ", i + 1);
		Load();

		Solve();
	}

	return 0;
}
