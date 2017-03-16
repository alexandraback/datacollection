#include <stdio.h>
#include <algorithm>

int v[10000];

int pd[1100][1100];

int main(){
	int t;
	scanf("%d",&t);
	for(int i=0;i<1100;i++){
		for(int j=i+1;j<1100;j++){
			pd[i][j]=pd[i][j-i]+1;
		}
	}


	for(int xxx=0;xxx<t;xxx++) {
		int d;
		scanf("%d",&d);
		for(int i=0;i<2000;i++) {
			v[i] = 0;
		}
		int maximo = 0;
		for(int i=0;i<d;i++){
			int x;
			scanf("%d",&x);
			v[x]++;
			maximo=std::max(maximo,x);
		}
		int ans=maximo;
		
		for (int direto=1;direto<=maximo;direto++){
			//printf("direto %d\n", direto);
			int quebras=0;
			for(int i=direto+1;i<=maximo;i++){
				if(v[i]==0)continue;
				quebras+=(pd[direto][i]*v[i]);
			}
			ans = std::min(ans,quebras+direto);
		}

		printf("Case #%d: %d\n", xxx+1,ans);
	}
}