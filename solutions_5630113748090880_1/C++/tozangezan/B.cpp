#include<stdio.h>
#include<algorithm>
using namespace std;
int p[3000];
int main(){
	int T;scanf("%d",&T);
	for(int t=1;t<=T;t++){
		int a;scanf("%d",&a);
		for(int i=0;i<3000;i++)p[i]=0;
		for(int i=0;i<2*a-1;i++){
			for(int j=0;j<a;j++){
				int b;scanf("%d",&b);
				p[b]++;
			}
		}
		printf("Case #%d:",t);
		for(int i=0;i<3000;i++)if(p[i]%2)printf(" %d",i);
		printf("\n");
	}
}