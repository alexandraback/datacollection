#include <cstdio>
#include <algorithm>

int T, N, v[20], S[20];
int ans[20], tmp[20], fnd;

void DFS(int dep, int sum, int ov){
	if(fnd || S[dep] + sum < 0 || sum - S[dep] > 0)return;
	if(dep < 0){
		if(sum == 0 && ov){
			for(int i = 0; i < 20; i++)
				ans[i] = tmp[i];
			fnd = 1;
		}
		return;
	}
	tmp[dep] = 1;
	DFS(dep - 1, sum + v[dep], 1);
	tmp[dep] = -1;
	DFS(dep - 1, sum - v[dep], 1);
	tmp[dep] = 0;
	DFS(dep - 1, sum, ov);
}

int main(){
	freopen("C-small.in", "r", stdin);
	freopen("C-small.out", "w", stdout);
	scanf("%d", &T);
	for(int t = 1; t <= T; t++){
		scanf("%d", &N);
		for(int i = 0; i < N; i++)
			scanf("%d", &v[i]);
		std::sort(v, v + N);
		S[0] = v[0];
		for(int i = 1; i < N; i++)
			S[i] = S[i - 1] + v[i];
		fnd = 0;
		DFS(19, 0, 0);
		printf("Case #%d:\n", t);
		if(!fnd) puts("impossible");
		else{
			fnd = 0;
			for(int i = 0; i < N; i++)
				if(ans[i] > 0){
					if(fnd)putchar(' ');
					fnd = 1;
					printf("%d", v[i]);
				}
			putchar('\n');
			fnd = 0;
			for(int i = 0; i < N; i++)
				if(ans[i] < 0){
					if(fnd)putchar(' ');
					fnd = 1;
					printf("%d", v[i]);
				}
			putchar('\n');
		}
		
	}
}
