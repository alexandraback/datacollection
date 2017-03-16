#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	int a[100][100];
	int T,N,M;
	int i,j,k,l; // for loop

	scanf("%d", &T);

	for(i=0;i<T;i++){
		int ng=0;
		scanf("%d %d", &N, &M);
		for(j=0;j<N;j++){
			for(k=0;k<M;k++){
				scanf("%d", &a[j][k]);
			}
		}

		for(j=0;j<N;j++){
			for(k=0;k<M;k++){
				int target = a[j][k];
				int row=1,col=1;

				// row
				for(l=0;l<M;l++){
					if(a[j][l] > target){
						row = 0;
						break;
					}
				}
				// col
				for(l=0;l<N;l++){
					if(a[l][k] > target){
						col = 0;
						break;
					}
				}
				if(row == 0 && col == 0){
					// ng
					ng = 1;
					goto out;
				}
			}
		}
out:
		printf("Case #%d: ", i+1);
		if(ng == 1){
			printf("NO\n");
		} else {
			printf("YES\n");
		}

	}


	return 0;
}