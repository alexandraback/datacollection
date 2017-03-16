#include<cstdio>
#include<cstring>
int main(){
	int T,t=0;
	int R,C,M,tmp;
	int x,y;
	char map[60][60];
	bool f=true;
	scanf("%d",&T);
	while(++t<=T){
		f=true;
		memset(map,'*',sizeof(map));
		tmp=1;
		scanf("%d%d%d",&R,&C,&M);
		if(R>1)
			tmp*=2;
		if(C>1)
			tmp*=2;
		int q=R*C-M;
		//printf("%d %d %d\n",R,C,M);
		printf("Case #%d:\n",t);
		if(q==1){
			
		}
		else if(R*C-M < tmp || ((R==2 || C==2)&&q%2==1)){
			printf("Impossible\n");
			continue;
		}
		else if(tmp==4 && q<15){
			if(q<9 && q%2==1){
				printf("Impossible\n");
				continue;
			}
			else if(q==8 && (R>=4 || C>=4)){
				if(R>=4)
					for(int i=1 ; i<=4 ; i++)
						for(int j=1 ; j<=2 ; j++)
							map[j][i]='.';				
				else if(C>=4)
					for(int i=1 ; i<=2 ; i++)
						for(int j=1 ; j<=4 ; j++)
							map[j][i]='.';
				map[0][0]='c';
				f=false;
				
			}
			else if(q==13){
				if(R>=5 || C>=5){
					if(R>=5){
						for(int i=1 ; i<=5 ; i++)
							for(int j=1 ; j<=2 ; j++)
								map[j][i]='.';
						for(int i=1 ; i<=3 ; i++)
							map[3][i]='.';
						f=false;
					}
					else if(C>=5){
						for(int i=1 ; i<=2 ; i++)
							for(int j=1 ; j<=5 ; j++)
								map[j][i]='.';
						for(int i=1 ; i<=3 ; i++)
							map[i][3]='.';
						f=false;
					}
					map[0][0]='c';
				}
			}

		}
		if(f){
			tmp=R*C-M-1;
			x=y=2;
			while(tmp){
				if(tmp==1 && R>2 && C>2){
					if(x<=C){
						map[x][1]=map[x][2]='.';
						map[x-1][(R<(y-1)?R:(y-1))]='*';
						tmp--;
					}
				}
				else
					for(int i=1 ; i<y && i<=R && tmp>0 && x<=C ; i++){
						tmp--;
						map[x][i]='.';
					}
				if(tmp==1 && R>2 && C>2){
					if(y<=R){
						map[1][y]=map[2][y]='.';
						map[(x<C?x:C)][y-1]='*';
						tmp--;
					}
				}
				else
					for(int i=1 ; i<=x && i<=C && tmp>0 && y<=R; i++){
						tmp--;
						map[i][y]='.';
					}
				x++;y++;
			}
		

		}
		map[1][1]='c';
		for(int i=1 ; i<=R ; i++){
			for(int j=1 ; j<=C ; j++){
				printf("%c",map[j][i]);
			}
			printf("\n");
		}		
	}
return 0;
}
