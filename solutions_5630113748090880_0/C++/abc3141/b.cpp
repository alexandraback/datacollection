#include<iostream>
#include<cstdio>
using namespace std;
int T;
int N;
int cou[2500];
int main()
{
	scanf("%d",&T);
	for(int cas=0;cas<T;cas++){
		scanf("%d",&N);
		for(int i=0;i<2500;i++)cou[i]=0;
		for(int i=0;i<2*N-1;i++){
			for(int j=0;j<N;j++){
				int X;
				scanf("%d",&X);
				cou[X-1]++;
			}
		}
		printf("Case #%d: ",cas+1);
		int couans=N;
		for(int i=0;i<2500;i++){
			if(cou[i]&1){
				if(couans==1)printf("%d\n",i+1);
				else printf("%d ",i+1);
			}
		}
		printf("\n");
	}
	return 0;
}
