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
#define FOR(i, s, t) for(int i = (s); i < (t); i++)
#define RFOR(i, s, t) for(int i = (s)-1; i >= (t); i--)

int main(){
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
#endif
	int T, i0;
	scanf("%d", &T);
	for(i0 = 1; i0 <= T; i0++){
		int n, m;
		scanf("%d%d", &n, &m);
		int n2 = n/2;
		int i, j, k;
		printf("Case #%d:\n", i0);
		i = (1<<(n2-1))+1;
		while(m--){
			FOR(temp, 0, 2)
				for(j = n2-1; j >= 0; j--)
					printf("%d", i>>j&1);
			for(j = 2; j <= 10; j++){
				ll x = 1;
				for(k = 0; k < n2; k++)
					x *= j;
				x += 1;
				printf(" %lld", x);
			}
			printf("\n");
			i += 2;
		}
	}
	return 0;
}
