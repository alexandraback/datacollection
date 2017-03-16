#include <stdio.h>
int D[1000][2];
bool U[1000][2];
int main(){
	freopen("B-small-attempt0.in","r",stdin);
	freopen("B-small-attempt0.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--> 0){
		//
		int n;
		scanf("%d", &n);
		int i;
		for(i=0;i<n;i++){
			scanf("%d %d",&D[i][0], &D[i][1]);
			U[i][0] = U[i][1] = false;
		}

		int star = 0;

		int sol = 0;
		while (1) {
			for(i=0;i<n;i++){
				if (!U[i][1] && D[i][1] <= star) break;
			}
			if (i < n) {
				sol ++;

				if (!U[i][0]) {
					star ++;
					U[i][0] = true;
				}
				star ++;
				U[i][1] = true;
				continue;
			}
			int who = -1;
			for(i=0;i<n;i++){
				if (!U[i][0]) {
					if (D[i][0] <= star) {
						if (who == -1) who = i;
						else {
							if (D[who][1] < D[i][1]) who = i;
						}
					}
				}
			}
			if (who == -1) break;
			sol ++;
			star ++;
			U[who][0] = true;
		}

		static int cs = 1;
		printf("Case #%d: ", cs ++);
		for(i=0;i<n;i++){
			if(!U[i][1]) break;
		}
		if (i<n) printf("Too Bad\n");
		else printf("%d\n", sol);
	}
	return 0;
}