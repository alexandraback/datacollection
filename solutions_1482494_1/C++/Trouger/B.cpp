#include <stdio.h>


int main(){
	int T;
	int a[1000], b[1000];
	int curlevel[1000];
	scanf("%d", &T);
	for (int ttt = 1; ttt <= T; ttt++){
		int N;
		scanf("%d", &N);
		for (int i = 0; i < N; i++){
			scanf("%d%d", a+i, b+i);
			curlevel[i] = 0;
		}
		int res = 0;
		int star = 0;
		int completed = 0;
		while (completed < N){
			int maxv = -1, maxp = -1;
			int i;
			for (i = 0; i < N; i++){
				if (curlevel[i] == 2) continue;
				if (b[i] <= star){
					star += 2 - curlevel[i];
					curlevel[i] = 2; 
					completed++;
					res++;
					break;
				}
				if (curlevel[i] == 0 && a[i] <= star){
					if (b[i] > maxv){
						maxv = b[i];
						maxp = i;
					}
				}
			}
			if (i == N){
				if (maxp != -1){
					curlevel[maxp] = 1;
					star++;
					res++;
				}else{
					res = -1;
					break;
				}
			}
		}
		if (res != -1)
			printf("Case #%d: %d\n", ttt, res);
		else
			printf("Case #%d: %s\n", ttt, "Too Bad");
	}
	return 0;
}