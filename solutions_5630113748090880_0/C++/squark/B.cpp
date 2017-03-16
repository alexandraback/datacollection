#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <sstream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <cassert>
using namespace std;
typedef long long ll;
typedef double R;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define FOR(i, s, t) for(i = (s); i < (t); i++)
#define RFOR(i, s, t) for(i = (s)-1; i >= (t); i--)

bool a[2512];

int main(){
#ifdef LOCAL
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
#endif
	int T, i0;
	scanf("%d", &T);
	for(i0 = 1; i0 <= T; i0++){
		printf("Case #%d:", i0);
		int n;
		int i, j, k;
		scanf("%d", &n);
		memset(a, 0, sizeof a);
		for(i = 0; i < 2*n-1; i++){
			for(j = 0; j < n; j++){
				scanf("%d", &k);
				a[k] ^= 1;
			}
		}
		vector<int> ans;
		for(i = 0; i < 2512; i++)
			if(a[i])
				ans.pb(i);
		sort(ans.begin(), ans.end());
		assert(ans.size() == n);
		for(i = 0; i < n; i++)
			printf(" %d", ans[i]);
		printf("\n");
	}
	return 0;
}
