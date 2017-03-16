#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long LL;

int Main () {
	int J, P, S, K;
	scanf ("%d %d %d %d", &J, &P, &S, &K);
		
	vector <int> ans[3];
		
	for (int i=0; i<J; i++) {
		for (int j=0; j<P; j++) {
			for (int k=0; k<min(S, K); k++) {
				ans[0].push_back(i);
				ans[1].push_back(j);
				ans[2].push_back((j+k)%S);
			}
		}
	}
	
	printf ("%d\n", ans[0].size());
	for (int i=0; i<ans[0].size(); i++) {
		printf ("%d %d %d\n", ans[0][i] + 1, ans[1][i] + 1, ans[2][i] + 1);
	}
	
}

int main () {
	freopen ("C-small-attempt0 (1).in", "r", stdin);
	freopen ("C-small-attempt0 (1).out", "w", stdout);

	int t;
	scanf ("%d", &t);
	for (int tc=0; tc<t; tc++) {
		printf ("Case #%d: ", tc + 1);
		Main();
	}
	return 0;
}