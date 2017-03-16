#include <cstdio>
#define MAX 50
const int dx[8]={-1,-1,-1,0,0,1,1,1},dy[8]={-1,0,1,-1,1,-1,0,1};
int max(int x,int y){
	return x>y?x:y;
}
int min(int x,int y){
	return x<y?x:y;
}
int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int t,ti,i,j,k,s,e;
	int R,C,M,RR,CC,MM;
	int cell[MAX][MAX];

	scanf("%d",&t);
	for(ti=1;ti<=t;ti++){
		for(i=0;i<MAX;i++)
			for(j=0;j<MAX;j++)
				cell[i][j]=0;

		scanf("%d%d%d",&R,&C,&M);
		RR=R;
		CC=C;
		MM=M;
		
		while(M){
			if(RR<CC){
				if(RR<=M){
					for(i=0;i<RR;i++){
						cell[i][CC-1]=-1;
					}
					M-=RR;
					CC--;
				}else{
					s=RR-M;
					for(i=s;i<RR;i++){
						cell[i][CC-1]=-1;
					}
					if(s==1){
						cell[1][CC-1]=0;
						cell[RR-1][CC-2]=-1;
					}
					break;
				}
			}else{
				if(CC<=M){
					for(i=0;i<CC;i++){
						cell[RR-1][i]=-1;
					}
					M-=CC;
					RR--;
				}else{
					s=CC-M;
					for(i=s;i<CC;i++){
						cell[RR-1][i]=-1;
					}
					if(s==1){
						cell[RR-1][1]=0;
						cell[RR-2][CC-1]=-1;
					}
					break;
				}
			}
		}

		for(i=0;i<R;i++){
			for(j=0;j<C;j++){
				if(cell[i][j]!=-1){
					for(k=0;k<8;k++){
						int nx=i+dx[k];
						int ny=j+dy[k];
						if(nx<0 || nx>=R || ny<0 || ny>=C) continue;
						if(cell[nx][ny]==-1){
							cell[i][j]++;
						}
					}
				}
			}
		}

		bool impossible=false;
		for(i=0;i<R;i++){
			for(j=0;j<C;j++){
				if(cell[i][j]>0){
					for(k=0;k<8;k++){
						int nx=i+dx[k];
						int ny=j+dy[k];
						if(nx<0 || nx>=R || ny<0 || ny>=C) continue;
						if(cell[nx][ny]==0) break;
					}
					if(k==8){
						impossible=true;
					}
				}
			}
		}

		printf("Case #%d:\n",ti);
		if(R*C!=MM+1 && impossible){
			printf("Impossible\n");
		}else{
			for(i=0;i<R;i++)
			{
				for(j=0;j<C;j++)
					printf("%c",(i==0 && j==0) ? 'c' : (cell[i][j]==-1?'*':'.'));
					//printf("%3d",cell[i][j]);
				printf("\n");
			}
		}
	}
}