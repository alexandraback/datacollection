#include <cstdio>
int ct[2513];
int T,n;
int main(){
	scanf("%d",&T);
	for (int Case=1;Case<=T;Case++){
		for (int i=1;i<=2500;i++)ct[i]=0;
		scanf("%d",&n);
		for (int i=0;i<2*n-1;i++){
			for (int j=0;j<n;j++){
				int x;
				scanf("%d",&x);
				ct[x]++;
			}
		}
		printf("Case #%d:", Case);
		for (int i=1;i<=2500;i++){
			if (ct[i]&1)printf(" %d",i);
		}
		printf("\n");
	}
	return 0;
}
