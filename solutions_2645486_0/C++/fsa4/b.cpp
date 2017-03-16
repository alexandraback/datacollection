#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>

#include <string>
#include <iostream>
#include <algorithm>

#include <vector>
#include <map>
#include <queue>

#define dbg(a) cout << a << endl

using namespace std;
typedef long long ll;

ll pd[15][10];
int v[15];

int main(){
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	int ca, e, r, n;
	ll melhor;
	scanf("%d", &ca);

	for(int caso = 1; caso <= ca; caso++){
		scanf("%d %d %d", &e, &r, &n);
		for(int i = 0; i < n; i++){
			scanf("%d", &v[i]);
		}

		for(int j = 0; j <= e; j++){
			pd[n-1][j] = j*v[n-1];
		}

		for(int i = n-2; i >= 0; i--){
			for(int j = 0; j <= e; j++){
				melhor = 0;
				for(int k = min(r, j); k <= j; k++){
					melhor = max(melhor, k*v[i] + pd[i+1][(j-k+r >= e) ? e : j-k+r]);
				}

				pd[i][j] = melhor;
			}
		}


		printf("Case #%d: %lld\n", caso, pd[0][e]);
	}

	return 0;
}
