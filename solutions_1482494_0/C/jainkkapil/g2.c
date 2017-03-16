#include<stdio.h>
#include<stdlib.h>
main(){
int T,T1,N,curStar;
int **star;
int count,flag;
int i,j,k;
scanf("%d",&T);
	for(T1=1;T1<=T;T1++){
		curStar=0;
		flag=0;count=0;
		scanf("%d",&N);
		star=malloc(N*sizeof(int*));
		for(i=0;i<N;i++){
			star[i]=malloc(sizeof(int)*4);
			star[i][2]=star[i][3]=0;
			scanf("%d %d",&star[i][0],&star[i][1]);
			if(curStar >= star[i][1]){
				curStar += 2;
				star[i][2]=star[i][3]=1;
				count++;
			}
		}
		for(i=1;i<N;i++){
			for(j=0;j<i;j++){
				if(star[i][1] > star[j][1]){
					int t;
					t=star[i][0];
					star[i][0]=star[j][0];
					star[j][0]=t;
					t=star[i][1];
					star[i][1]=star[j][1];
					star[j][1]=t;
					t=star[i][2];
					star[i][2]=star[j][2];
					star[j][2]=t;
					t=star[i][3];
					star[i][3]=star[j][3];
					star[j][3]=t;
				}
			}
		}
/*		for(i=0;i<N;i++){
			printf("star[0]:%d star[1]:%d\n",star[i][0],star[i][1]);
		}
							printf("curStar:%d count:%d\n",curStar,count);
*/		for(i=0;i<N;i++){
			for(j=0;j<N;j++){
				for(k=0;k<N;k++)
					if(star[k][3] == 0 && curStar >= star[k][1]){
						if(star[k][2]==0)
							curStar+=2;
						else
							curStar+=1;
						star[k][2]=star[k][3]=1;
						count++;
//						printf("curStar:%d count:%d k:%d l2\n",curStar,count,k);
						k=-1;
					}
				for(k=0;k<N;k++)
					if(star[k][2] == 0 && curStar >= star[k][0]){
						curStar+=1;
						star[k][2]=1;
						count++;
//						printf("curStar:%d count:%d k:%d l1\n",curStar,count,k);
						break;
					}
			}
		}
		for(i=0;i<N;i++){
			if(star[i][3] == 0){
				flag=1;
				break;
			}
		}
		printf("Case #%d: ",T1);
		if(flag==1)
			printf("Too Bad\n");
		else
			printf("%d\n",count);
		for(i=0;i<N;i++)
			free(star[i]);
		free(star);
	}
}
