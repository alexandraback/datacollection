#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 32;

int x[MAXN];
bool find_one;
int tc, cn(0), n;
vector <int> out1, out2;

void dfs(int d, int cc1, int cc2) {
	int i, j, k;
	if (find_one) return;
	if (cc1 == cc2 && cc1 && cc2) {
		find_one = true;
		for (i=0; i<out1.size(); ++i) printf("%d%s", out1[i], i==out1.size()-1?"\n":" ");
		for (i=0; i<out2.size(); ++i) printf("%d%s", out2[i], i==out2.size()-1?"\n":" ");
		return;
	}
	if (d == 20) return;
	
	out1.push_back(x[d]);
	dfs(d+1, cc1+x[d], cc2);
	if (find_one) return;
	out1.pop_back();
	
	out2.push_back(x[d]);
	dfs(d+1, cc1, cc2+x[d]);
	if (find_one) return;
	out2.pop_back();
	
	dfs(d+1, cc1, cc2);
	if (find_one) return;
}

int main() {
	int i, j, k;
	
	freopen("C-small-attempt2.in", "r", stdin);
//	freopen("C-small-attempt1.in", "r", stdin);
	freopen("out.txt", "w", stdout);
//	freopen("res.txt", "w", stdout);
	
	scanf("%d", &tc);
	while (tc--) {
		scanf("%d", &n);
		for (i=0; i<n; ++i) scanf("%d", x+i);
		sort(x, x+n);
		find_one = false;
		printf("Case #%d:\n", ++cn);
		out1.clear();
		out2.clear();
		dfs(0, 0, 0);
		if (!find_one) puts("Impossible");
	}
	return 0;
}