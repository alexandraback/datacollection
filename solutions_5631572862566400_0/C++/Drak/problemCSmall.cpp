#include <bits/stdc++.h>
using namespace std;
typedef long long int LL;
int main() {
	int T, v[100], amigo[100], n;
	scanf("%d", &T);
	for(int caso=1 ; caso<=T ; caso++) {
		scanf("%d", &n);
		for(int i=0 ; i<n ; i++) {
			scanf("%d", &amigo[i]);
			amigo[i]--;
			v[i] = i;
		}
		int ans = 0;
		do {
			if( amigo[v[0]] == v[1] ) {
				int cnt = 1;
				for(int i=1 ; i<n ; i++) {
					if( amigo[v[i]] == v[i - 1] ) {
						ans = max(ans, i + 1);
					} else if( amigo[v[i]] == v[i + 1] ) {

					} else if( amigo[v[i]] == v[0] ) {
						ans = max(ans, i + 1);
						break;
					} else break;
				}
			}
		}while( next_permutation(v, v + n) );
		printf("Case #%d: %d\n", caso, ans);
	}
	return 0;
}