#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;
int T,t;
int main(){
	int i,j,k;
	scanf("%d",&T);
	int x,y;
	for(t=1;t<=T;t++){
		scanf("%d%d",&x,&y);
		printf("Case #%d: ",t);
		//printf(">%d %d\n",x,y);
		if(x>=0)
			for(i=0;i<x;i++){
				printf("WE");
}
		else for(i=0;i>x;i--){
				printf("EW");
			}
		if(y>=0)
		for(i=0;i<y;i++){
			printf("SN");
			
		}
		else
		for(i=0;i>y;i--){
			printf("NS");
			
		}
		printf("\n");
	}
	return 0;
}
		
