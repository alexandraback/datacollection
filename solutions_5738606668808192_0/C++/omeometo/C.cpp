#include <stdio.h>
#include <vector>
using namespace std;
main(){
	int T,N,J;
	scanf("%d%d%d",&T,&N,&J);
	if(N%2!=0)return 0;
	puts("Case #1:");
	for(int b=1;b<2*J;b+=2){
		for(int i=0;i<=(N/2)-1;i++)printf("%d",(b>>i)&1);
		for(int i=(N/2)-1;i>=0;i--)printf("%d",(b>>i)&1);
		for(int i=2;i<=10;i++)printf(" %d",i+1);
		puts("");

	}
}