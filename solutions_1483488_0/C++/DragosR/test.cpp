#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int T, A, B;
int pw[20];
int main() {

	freopen("test.in", "r", stdin);
	freopen("test.out", "w", stdout);

	scanf("%d\n", &T);
	
	pw[0] = 1; 
	for(int i = 1; i < 10; ++i)
		pw[i] = pw[i - 1] * 10;

	for(int test = 1; test <= T; ++test) {

		scanf("%d %d\n", &A, &B);
		int ans = 0;
		for(int i = A; i <= B; ++i) {
			int x = i;
			
			int v[20]; v[0] = 0;
			while(x > 0) {
				v[++v[0]] = x % 10 ; x /= 10;
			}
			reverse(v + 1, v + v[0] + 1) ; 
			
			int n = v[0];
			for(int j = 1; j < n; ++j) 
				v[++v[0]] = v[j];

			int val = i;
			int sol = 0; 
			map<int, int> m ;
			for(int j = n + 1; j <= v[0]; ++j) {
				
				val -= v[j - n] * pw[n - 1];
			       	val = val * 10 + v[j];
				//printf("%d, ", val);
				
				if(val > i && val <= B) {
					if(m[val]) continue;
					++sol ; m[val]++;
				}
			} 
			
			ans += sol;
		}
		printf("Case #%d: %d\n", test, ans);
	}
	return 0;
}
