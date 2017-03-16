#include <cstdio>

int T,N;
int list[999][99];
int sorted[99][2];
int snum[999];
int checked[999];
int sol[999];
int main() {
	scanf("%d",&T);
	for(int ts=1;ts<=T;ts++) {
		scanf("%d",&N);
		int M=N+N-1;
		for(int i=0;i<M;i++) {
			for(int j=0;j<N;j++) scanf("%d",&list[i][j]);
			checked[i]=0;
		}
		for(int i=0;i<N;i++) {
			snum[i]=0;
			int kmin=9999;
			for(int j=0;j<M;j++) if(checked[j]==0) if(list[j][i]<kmin) kmin=list[j][i];
			for(int j=0;j<M;j++) {
				if(checked[j]==0) {
					if(list[j][i]==kmin) {
						sorted[i][snum[i]++]=j;
						checked[j]=1;
					}
				}
			}
		}
		for(int i=0;i<N;i++) {
			if(snum[i]==1) {
				//missing
				for(int j=0;j<N;j++) {
					if(i==j) {
						sol[j]=list[sorted[i][0]][j];
					} else {
						if(list[sorted[i][0]][j]==list[sorted[j][0]][i]) {
							sol[j]=list[sorted[j][1]][i];
						} else {
							sol[j]=list[sorted[j][0]][i];
						}
					}
				}
			}
		}
		printf("Case #%d:",ts);
		for(int i=0;i<N;i++) printf(" %d",sol[i]);
		printf("\n");
	}
	return 0;
}
