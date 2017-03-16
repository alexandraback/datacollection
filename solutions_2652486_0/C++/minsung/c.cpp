#include<cstdio>
#include<algorithm>

#define N 15
using namespace std;

int r,n,m,k;
int data[N];
int t[3];
int dg[4] = {3, 5, 2, 4};
int main(){
	int i,j,l;
	int tc;
	freopen("C-small-1-attempt1.in", "r", stdin);
	freopen("C-small-1-attempt1.out", "w", stdout);
	scanf("%d",&tc);
	while(tc--){
		scanf("%d %d %d %d", &r, &n, &m, &k);
		printf("Case #1:\n");
		while(r--){
			for(i = 0; i < k; i++){
				scanf("%d", &data[i]);
			}
			for (i = 0; i < n;i++){
				for(j = 0; j < m-1; j++){
					for(l = 0; l < k;l++){
						if (data[i]%dg[j]==0){
							data[i]/=dg[j];
							break;
						}
					}
					if(l != k){
						t[i] = dg[j];
						break;
					}
				}
			}
			for(i = 0; i < n; i++){
				if (t[i] != 2) continue;
				int ch = 0;
				for(j = 0; j < k;j++){
					if (data[j]%2 == 0){
						data[j]/=2;
						ch=1;
					}
				}
				if (ch)
					t[i]*=2;
			}

			for(i = 0; i < n;i++)
				printf("%d", t[i]);
			printf("\n");
		}
	}
	return 0;
}