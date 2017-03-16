#include <cstdio>
#include <algorithm>
#define fr(i,a,b) for(int i=a;i<b;i++)
#define rep(i,b) fr(i,0,b)

using namespace std;
#define N 1010
char g[100][100];
int teto(int a, int b){ return (a+b-1)/b; }

int main(){
	int cas;
	scanf("%d",&cas);
	fr(u,1,cas+1){
		int a,b,k;
		scanf("%d %d %d",&a,&b,&k);
		rep(i,a) rep(j,b) g[i][j]='*';
		rep(i,a) g[i][b]=0;
		
		int m = a*b - k;
		bool eh=false;
		if(m==1){
			g[0][0]='c';
			eh=true;
		}else if(min(a,b)==1){
			if(a==1) rep(i,m) g[0][i]='.';
			if(b==1) rep(i,m) g[i][0]='.';
			g[0][0]='c';
			eh=true;
		}else{		
			fr(i,2,b+1){
				if(2*i>m) break;
				fr(j,0,a-1){
					if(2*(i + j)>m) break;
					if(m - 2*(i + j) <=  j*(i-2)){						
						rep(z,i) g[0][z]=g[1][z]='.';
						rep(z,j) g[z+2][0]=g[z+2][1]='.';
						int sobra = m - 2*(i+j);
						int col=2;
						while(sobra){
							int gg=min(j,sobra);
							rep(z,gg) g[z+2][col]='.';
							sobra -= gg;
							col++;
						}						
						eh=true;
						break;
					}
				}
				if(eh) break;
			}
			g[0][0]='c';
		}
		printf("Case #%d:\n",u);
		if(!eh) printf("Impossible\n");
		else{
			rep(i,a) printf("%s\n",g[i]);
		}
	}
	
	return 0;
}

