#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#define max_S 12
using namespace std;

int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int T;
	scanf("%d", &T);

	int J, P, S, K;
	int st[1300][3];
	int top;
    int ma[3][max_S][max_S];

	for(int i=0; i<T; i++){
		printf("Case #%d: ", i+1);

		top = 0;

		scanf("%d %d %d %d", &J, &P, &S, &K);

		for(int j=0; j<3; j++){
			for(int k=0; k<max_S; k++){
				for(int m=0; m<max_S; m++){
					ma[j][k][m] = 0;
				}
			}
		}

		for(int j=0; j<J; j++){
			for(int k=0; k<P; k++){
				for(int m=0; m<S; m++){
					if(ma[0][j][k] < K && ma[1][j][m] < K && ma[2][k][m] < K){
                            st[top][0] = j;
							st[top][1] = k;
							st[top][2] = m;
							ma[0][j][k]++;
							ma[1][j][m]++;
							ma[2][k][m]++;
							top++;
					}
				}
			}
		}

		printf("%d\n", top);
		for(int j=0; j<top; j++)
			printf("%d %d %d\n", st[j][0]+1, st[j][1]+1, st[j][2]+1);

		//printf("\n");
	}

	return 0;
}
