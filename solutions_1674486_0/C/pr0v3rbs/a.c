#include <stdio.h>

int flag[1000]={0,},N;
int cla[1000][1000]={0,};

int dia(int start,int end){
	int i,j,tem=0;
	//printf("%d\n" , start);
	if(start==end)
		return 1;

	for(i=0;i<N;i++){
		if(cla[start][i]==1){
			flag[i]=1;
			tem += dia(i,end);
			flag[i]=0;
		}
	}
	return tem;
}

int main(){
	int i,j,testn,test=1;
	scanf("%d" , &testn);
	while(testn--){
		int tem,chk=0;
		scanf("%d" , &N);

		for(i=0;i<N;i++){
			for(j=0;j<N;j++)
				cla[i][j]=0;
			flag[i]=0;
		}

		for(i=0;i<N;i++){
			int pt;
			scanf("%d" , &tem);
			for(j=0;j<tem;j++){
				scanf("%d" , &pt);
				cla[pt-1][i]=1;
			}
		}

		//for(i=0;i<N;i++){
		//	for(j=0;j<N;j++)
		//		printf("%d " , cla[i][j]);
		//	printf("\n");
		//}
		//printf("%d\n" , dia(N-1));
		for(i=N-1;i>=0 ; i--){
			for(j=N-1;j>=0 ; j--){
				if(dia(i,j)>1){
					chk=1;
					printf("Case #%d: Yes\n" , test++);
					i= -10;
					break;
				}
			}
		}
		if(chk==0)
			printf("Case #%d: No\n" , test++);
	}
}
