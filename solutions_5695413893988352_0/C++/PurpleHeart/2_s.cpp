#include <cstdio>
#include <cstring>

int cases, best_i, best_j, ans;
char C[20], J[20], ooo[20];
int len_C, len_J, now_i, now_j;

int sabs(int x){
	if(x>0)return x;else return -x;
}

int dfs(int now){
	if(now == len_C + len_J){
		if(sabs(now_i - now_j) < ans){
			ans = sabs(now_i - now_j);
			best_i = now_i;
			best_j = now_j;
		} else if(now == ans){
			if(now_i < best_i){
				best_i = now_i;
				best_j = now_j;
			} else if(now_i == best_i){
				if(now_j < best_j){
					best_j = now_j;
				}
			}
		}
		return 0;
	}
	if(now < len_C){
		if(C[now] != '?'){
			int t_i = now_i;
			now_i = now_i * 10 + (C[now] - '0');
			dfs(now + 1);
			now_i = t_i;
		} else {
			for(int i = 0; i < 10; ++i){
				int t_i = now_i;
				now_i = now_i * 10 + i;
				dfs(now + 1);
				now_i = t_i;
			}
		}
	} else {
		if(J[now - len_C] != '?'){
			int t_j = now_j;
			now_j = now_j * 10 + (J[now - len_C] - '0');
			dfs(now + 1);
			now_j = t_j;
		} else {
			for(int i = 0; i < 10; ++i){
				int t_j = now_j;
				now_j = now_j * 10 + i;
				dfs(now + 1);
				now_j = t_j;
			}
		}
	}
	return 0;
}

void oz(int v){
	for(int i = 0; i < v; ++i) printf("0");
}

int main(){
	scanf("%d", &cases);
	for(int xx = 1; xx <= cases; ++xx){
		scanf("%s%s", C, J);
		len_C = strlen(C);
		len_J = strlen(J);
		ans = 999999999;
		best_i = best_j = 99999999;
		now_i = now_j = 0;
		dfs(0);
		printf("Case #%d: ", xx);
		sprintf(ooo, "%d", best_i);
		oz(len_C - strlen(ooo));
		printf("%d ", best_i);
		sprintf(ooo, "%d", best_j);
		oz(len_J - strlen(ooo));
		printf("%d\n", best_j);
	}
}
