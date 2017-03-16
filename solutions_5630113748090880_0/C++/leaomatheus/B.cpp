#include <bits/stdc++.h>
using namespace std;
#define ii pair<int,int>
#define vi vector<int>
#define vii vector<ii, ii>
#define vvi vector<vi>
#define MAXN 105
#define MAXE 10005
#define FOR(x,n) for(int x = 0; x < n; x++)
#define FOR1e(x,n) for(int x = 1; x <= n; x++)
#define MOD 1000000007

char p[10005];
int missing[2505];

int main() {
	int n, t, val;
	scanf("%d", &t);
	FOR1e(caso, t) {
		memset(missing, 0, sizeof(missing));
		scanf("%d", &n);
		FOR(x, 2*n-1) {
			FOR(y, n) {
				scanf("%d", &val);
				missing[val]++;
			}
		}

		vector<int> tmp;
		FOR(x, 2505) {
			if(missing[x]%2) tmp.push_back(x);
		}
		sort(tmp.begin(), tmp.end());
		printf("Case #%d:", caso);
		FOR(x, n) printf(" %d", tmp[x]);
		printf("\n");
		if(tmp.size() != n) printf("TMPSIZE = %d\naaaaaaa\naaaaaa\naaaaaa\n", (int)tmp.size());
		tmp.clear();
	}
	return 0;
}