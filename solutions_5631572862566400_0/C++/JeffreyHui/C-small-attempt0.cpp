#include <cstdio>
#include <algorithm>
using namespace std;
int main (){
	freopen ("C-small-attempt0.in", "r", stdin);
	freopen ("C-small-attempt0.out", "w", stdout);
	int T, N;
	int F[1000];
	bool B[1000];
	int P[1000];
	scanf("%d", &T);
	for (int i = 1; i <= T; i++){
		scanf("%d", &N);
		for (int j = 0; j < N; j++){
			scanf("%d", &F[j]);
			F[j]--;
			P[j] = 0;
		}
		int large_cnt = 0;
		for (int j = 0; j < N; j++){
			for (int k = 0; k < N; k++)
				B[k] = false;
			int start = j;
			int internal_cnt = 0;
			while (!B[j]){
				B[j] = true;
				internal_cnt++;
				j = F[j];
			}
			if (start == j)
				large_cnt = max(large_cnt, internal_cnt);
			j = start;
		}
		// ------
		int small_cnt = 0;
		for (int j = 0; j < N; j++){
			if (j == F[F[j]] && j < F[j]){
				F[F[j]] = -1;
				F[j] = -1;
				small_cnt += 2;
			}
		}
		for (int j = 0; j < N; j++){
			for (int k = 0; k < N; k++)
				B[k] = false;
			int start = j;
			int internal_cnt = 0;
			while (!B[j] && F[j] != -1){
				B[j] = true;
				internal_cnt++;
				j = F[j];
			}
			if (F[j] == -1)
				P[j] = max(P[j], internal_cnt);
			j = start;
		}
		for (int j = 0; j < N; j++)
			if (F[j] == -1)
				small_cnt += P[j];
		printf("Case #%d: %d\n", i, max(large_cnt, small_cnt));
		
	}
	fclose (stdin);
	fclose (stdout);
	return 0;
}
