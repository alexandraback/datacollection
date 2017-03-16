#include <cstdio>

int main(){
	//freopen("B-small-attempt0.in", "r", stdin);
	//freopen("B-small-attempt0.out", "w", stdout);
	freopen("B-large.in", "r", stdin);
	freopen("B-large.out", "w", stdout);
	int T;
	scanf("%d", &T);
	for(int t = 1; t <= T; t++){
		int N, S, P; 
		scanf("%d%d%d", &N, &S, &P);
		int ans = 0, up = P * 3 - 2, low = P * 3 - 4;
		if(low < 0) low = 1;
		for(int i = 0; i < N; i++){
			int tmp;
			scanf("%d", &tmp);
			if(tmp >= up) ++ans;
			else if(tmp >= low && S > 0) ++ans, --S;
		}
		printf("Case #%d: %d\n", t, ans);
	}
}

