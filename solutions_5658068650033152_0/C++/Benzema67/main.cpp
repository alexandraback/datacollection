#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>
typedef long long ll;
using namespace std;

int main(){
	int T;
	freopen("C-small-attempt0.in", "r", stdin);
	freopen("b.txt", "w", stdout);
	scanf("%d", &T);
	for(int t = 0; t < T; t++){
		int n, m, k;
		scanf("%d %d %d", &n, &m, &k);
		int ans = n * m;
		if(k == 1){
			ans = 1;
		}
		else if(k <= n * m && k >= n * m - 4){
			ans = (n + m - 4) * 2 + (k + 4 - n * m);
		}
		else{
			for(int i = 1; i < n - 1; i++){
				for(int j = 1; j < m - 1; j++){
					if(i * j + 2 * (i + j)> k) break;
					int tmp = k - (i * j + 2 * (i + j));
					int ok = 0;
					if(i < n - 2) ok = j;
					if(j < n - 2) ok = max(ok, i);
					if(tmp <= ok){
						if(tmp == 0) ans = min(ans, 2 * (i + j));
						else ans = min(ans, 2 * (i + j) + 1);
					}
				}
			}
		}
		printf("Case #%d: %d\n", t + 1, ans);
	}
}
