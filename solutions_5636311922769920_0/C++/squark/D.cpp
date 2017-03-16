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



int main(){
#ifdef LOCAL
	//freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int T, i0;
	scanf("%d", &T);
	for(i0 = 1; i0 <= T; i0++){
		printf("Case #%d:", i0);
		int k, c, s;
		scanf("%d%d%d", &k, &c, &s);
		int i, j;
		if(c*s < k){
			printf(" IMPOSSIBLE\n");
			continue;
		}
		for(j = k; j > 0; ){
			ll x = 0;
			for(i = 0; i < c; i++){
				j--;
				x = x*k + max(j, 0);
			}
			printf(" %lld", x+1);
		}
		printf("\n");
	}
	return 0;
}
