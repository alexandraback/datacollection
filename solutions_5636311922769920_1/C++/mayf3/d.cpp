#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long LL;

int k, c, s;

int main(){
	int T;
	scanf("%d", &T);
	for(int cas = 1; cas <= T; cas++){
		printf("Case #%d:", cas);
		scanf("%d%d%d", &k, &c, &s);
		if (s * c >= k){
			for(int i = 0; i < k; i += c){
				int step = min(k, i + c) - i;
				LL st = 0;
				for(int j = 0; j < step; j++) st = st * k + i + j;
				for(int j = 0; j < c - step; j++) st *= k;
				printf(" %lld", st + 1);
			}
			puts("");
		}
		else{
			puts(" IMPOSSIBLE");
		}
	}
}
