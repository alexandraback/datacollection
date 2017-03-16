#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <cmath>
#include <cstdlib>
#include <climits>
#include <limits>
using namespace std;
int tc, tcn;

void solve(){
	scanf("%d", &tc);
	while (tc--){
		int r, c, w;
		scanf("%d %d %d", &r, &c, &w);
		int re = (c / w)*(r - 1);
		int Max = 0;
		for (int j = w,k = 0; j <= c; j+=w,k++){
			if (j != c)
				Max = max(Max, k + w + 1);
			else
				Max = max(Max, k + w);
		}
		re += Max;
		printf("Case #%d: %d\n", ++tcn, re);
	}
}

int main(void){
	//freopen("A-large.in", "r", stdin);
	//freopen("output.txt", "w", stdout);
	solve();
	return 0;
}