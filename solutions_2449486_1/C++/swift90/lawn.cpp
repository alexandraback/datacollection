#include<cstdio>
#include<cstring>
const int dx[]={-1,0,1,0};
const int dy[]={0,-1,0,1};
int N,M;
int nr[110][110];
int vecin[5];
void solve(int test){
	int sol=1;
	for(int i=1;i<=N && sol;++i){
		for(int j=1;j<=M && sol;++j){
			vecin[0]=vecin[1]=vecin[2]=vecin[3]=1;
			for(int k=0;k<4;++k){
				for(int x=i,y=j;(1<=x && x<=N) && (1<=y && y<=M);x+=dx[k],y+=dy[k])
					if(nr[x][y]>nr[i][j])
						vecin[k]=0;
			}
			if(!(vecin[0] && vecin[2]) && !(vecin[1] && vecin[3]))
				sol=0;
		}
	}
	if(sol)
		printf("Case #%d: YES\n",test);
	else
		printf("Case #%d: NO\n",test);
}
int main(){
	freopen("lawn.in","r",stdin);
	freopen("lawn.out","w",stdout);
	int T;
	scanf("%d",&T);
	for(int test=1;test<=T;++test){
		memset(nr,0,sizeof(nr));
		scanf("%d%d",&N,&M);
		for(int i=1;i<=N;++i){
			for(int j=1;j<=M;++j)
				scanf("%d",&nr[i][j]);
		}
		solve(test);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
