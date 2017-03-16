#include <cstdio>

int rot[10000001];
int use[2000001];
int pwr[10] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000};

void pre(){
	for(int i = 0, j = 1, k = 10; i < 7; i++, k *= 10)
		for(; j < k; ++j){
			rot[j] = j / 10 + (j % 10) * pwr[i];
			while(rot[j] < k / 10)
				rot[j] = rot[j] / 10 + (rot[j] % 10) * pwr[i];	
		}
	return;
}

int main(){
	//freopen("C-small-attempt0.in", "r", stdin);
	//freopen("C-small-attempt0.out", "w", stdout);
	freopen("C-large.in", "r", stdin);
	freopen("C-large.out", "w", stdout);
	pre();
	int T;
	scanf("%d", &T);
	for(int t = 1; t <= T; t++){
		int A, B;
		long long ans = 0;
		scanf("%d%d", &A, &B);
		for(int i = A; i <= B; i++)
			use[i] = 0;
		for(int i = A; i <= B; i++){
			int tmp = rot[i];
			while(tmp != i){
				if(tmp <= B && tmp > i && use[tmp] != i){
					use[tmp] = i;
					++ans;
				}
				tmp = rot[tmp];
			}
		}
		printf("Case #%d: %lld\n", t, ans);
	}
}