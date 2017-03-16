#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

#define ss second
#define ff first

vector <pair<int,int> >d;
int s[30];
int n;

int main () {
	int i, j, k, ca, T;

	freopen ("/home/shuo/Desktop/A.in", "r", stdin);
	freopen ("/home/shuo/Desktop/A.ou", "w", stdout);
	scanf ("%d", &T);
	for (ca = 1; ca <= T; ca++) {
		d.clear ();
		scanf ("%d", &n);
		for (i = 0; i < n; i++) scanf ("%d", &s[i]);
		for (i = 0; i < (1<<n); i++) {
			int sum = 0;
			for (j = 0; j < n; j++) if (i & (1<<j))
				sum += s[j];
			d.push_back (make_pair (sum, i));
		}
		//printf ("%d\n", 1<<n);
		sort (d.begin (), d.end());

		printf ("Case #%d:\n", ca);
		bool flag = false;
		int m = d.size ();
		for (i = 1; i < m - 1; ++i) if (d[i].ff == d[i+1].ff && !(d[i].ss& d[i+1].ss)){
			int x = d[i].ss, y = d[i+1].ss;
			bool first = true;
			for (k = 0; k < n; k++) if ((1<<k) & x) {
				if (first) printf ("%d", s[k]), first = false;
				else printf (" %d", s[k]);
			} printf ("\n");
			first = true;
			for (k = 0; k < n; k++) if ((1<<k) & y) {
				if (first) printf ("%d", s[k]), first = false;
				else printf (" %d", s[k]);
			}printf ("\n");
			flag = true;
			break;
		}
		if (!flag) printf ("Impossible\n");
	}
	return 0;
}
