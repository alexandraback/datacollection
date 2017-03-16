#include <iostream>
#include <map>
#include <cmath>
#include <vector>
#include <queue>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long int uint64;
#define MAXN 110

int N, S, P;
int n[MAXN];

int main() {

	int cases;
	int caseindex = 0;

	freopen("input", "r", stdin);
	freopen("output", "w", stdout);

	scanf("%d", &cases);
	//gets(s);
	while (cases--) {
		int ans = 0;
		int mem = 0;
		int val = 0;
		scanf("%d%d%d", &N, &S, &P);
		for( int i = 0;i < N; i++ ){
			scanf("%d", &n[i]);
			mem = n[i] % 3;
			val = (n[i] - mem) / 3;
			if( val >= P ){
				ans++;
			}else if( mem == 0 ){
				if( val > 0 && val + 1 >= P && S > 0 ){
					S--;
					ans++;
				}
			}else if( mem == 1 ){
				if( val + 1 >= P ){
					ans++;
				}
			}else if( mem == 2 ){
				if( val + 1 >= P ){
					ans++;
				}else if( val + 2 >= P && S > 0 ){
					S--;
					ans++;
				}
			}
			//printf("%d: %d, mod:%d, %d %d\n", n[i], val, mem, i, ans);
		}


		caseindex++;
		printf("Case #%d: %d\n", caseindex, ans);
	}

	return 0;
}
