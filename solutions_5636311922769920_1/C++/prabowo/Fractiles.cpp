#include <cstdio>
#include <vector>

int Main () {
	int k, c, s;
	scanf ("%d %d %d", &k, &c, &s);
	
	std::vector <long long> ans;
	
	int left = 0;
	while (left < k) {
		long long pos = 0;
		for (int i=0; i<c; i++) {
			pos *= k;
			if (left < k) {
				pos += left;
				left++;
			}
		}
		
		ans.push_back (pos);
	}
	
	if (ans.size() > s) printf (" IMPOSSIBLE");
	else for (int i=0; i<ans.size(); i++) printf (" %lld", ans[i] + 1);
	
	return 0 * printf ("\n");
}

int main () {
	freopen ("D-large.in", "r", stdin);
	freopen ("D-large.out", "w", stdout);
	int t;
	scanf ("%d", &t);
	for (int tc=0; tc<t; tc++) {
		printf ("Case #%d:", tc + 1);
		Main ();
	}
	return 0;
}