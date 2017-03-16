#include <algorithm>
#include <stdio.h>
#include <set>
using namespace std;

int a, b;

inline int rotate(int x, int dd, int d)
{
	return x / d + (x%d) * (dd / d);
}

set<pair<int, int> > check;
int main()
{
	int i;

	int t, tt=0;
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &a, &b);

		int d;
		for (i=1, d=0; i<=a; i*=10, d++) ;
		d = i;

		check.clear();
		int answer = 0;
		int n, m;
		for (n=a; n<b; n++) {
			for (i=1; i<d; i*=10) {
				m = rotate(n, d, i);
				if (m > n && m <= b && check.find(make_pair(n, m)) == check.end())
					answer++, check.insert(make_pair(n, m));
			}
		}

		fprintf(stderr, "%d\n", tt);
		printf("Case #%d: %d\n", ++tt, answer);
	}

	return 0;
}
