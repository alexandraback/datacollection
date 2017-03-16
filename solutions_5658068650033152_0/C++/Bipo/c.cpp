#include<stdio.h>

int main(){
	freopen("1C/C-small-attempt0.in","r",stdin);
	freopen("1C/out.txt","w",stdout);

	int T;
	scanf("%d",&T);

	for(int t=1;t<=T;t++){
		int N,M,K;

		scanf("%d%d%d",&N,&M,&K);

		int min=1000;

		for(int i=1;i<=N;i++){
			for(int j=1;j<=M;j++){
				int cnt=0;
				if(i<=2 || j<=2)cnt=K;
				else{
					cnt = (i+j-4)*2;
					if(K > i*j-4)cnt += K - (i*j-4);
				}
				if(cnt < min)min=cnt;
			}
		}
		printf("Case #%d: %d\n",t,min);
	}
}
