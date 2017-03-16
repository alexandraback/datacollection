#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int tc, tcn, d, p[1001], re;

void input(){
	scanf("%d", &d);
	for (int i = 0; i < d; i++){
		scanf("%d", &p[i]);
		re = max(p[i], re);
	}
}

void solve(){
	scanf("%d", &tc);
	while (tc--){
	
		re = 0;
		
		input();

		for (int i = 2; i <= re; i++){
			int cnt = 0;
			for (int j = 0; j < d; j++){
				if (p[j] <= i)
					continue;
				cnt += p[j] / i -1;
				if (p[j] % i)
					cnt++;
			
			}
			re = min(re, cnt + i);
		}
		
		printf("Case #%d: %d\n", ++tcn, re);
	}

}

int main(void){
	//freopen("input.txt", "r", stdin);
//	freopen("B-large.in", "r", stdin);
//	freopen("output.txt", "w", stdout);
	solve();
	return 0;
}