#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<queue>
#include<cmath>
#define LL long long
using namespace std;
struct abc{int x,y,z;} e[10000];
int T,a,b,c,d,n,ans,f[10000],g[10000],h[5][100][100];
void bcd(int x,int y){
	if (x>n){
		if (y>ans){
			ans=y;
			for (int i=1;i<=n;i++) g[i]=f[i];
		}
	}else{
		if (y+(n+1-x)<=ans) return;
		if (h[1][e[x].x][e[x].y]<d && h[2][e[x].x][e[x].z]<d && h[3][e[x].y][e[x].z]<d){
			h[1][e[x].x][e[x].y]++;
			h[2][e[x].x][e[x].z]++;
			h[3][e[x].y][e[x].z]++;
			f[x]=1;
			bcd(x+1,y+1);
			f[x]=0;
			h[1][e[x].x][e[x].y]--;
			h[2][e[x].x][e[x].z]--;
			h[3][e[x].y][e[x].z]--;
		}
		bcd(x+1,y);
	}
}
int main(){
	scanf("%d",&T);
	for (int I=1;I<=T;I++){
		scanf("%d%d%d%d",&a,&b,&c,&d);
		printf("Case #%d: ",I);
		n=0;
			for (int i=1;i<=a;i++)
				for (int j=1;j<=b;j++)
					for (int k=1;k<=c;k++){
						e[++n].x=i;
						e[n].y=j;
						e[n].z=k;
					}
			ans=0;
			bcd(1,0);
			printf("%d\n",ans);
			for (int i=1;i<=n;i++)
				if (g[i]) printf("%d %d %d\n",e[i].x,e[i].y,e[i].z);	
	}
    return 0;
}

