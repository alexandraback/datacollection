#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int n,m,k;
int x[10],y[10];
int mx[8]={0,1,1,1,0,-1,-1,-1};
int my[8]={0,1,0,-1,-1,-1,0,1};
int ans;
void dfs(int sx,int sy,int d,int sum){
	int i;
	int ax,bx,ay,by,dx,dy;
	int area;
	ax=0;ay=0;
	bx=0;by=0;
	for (i=1;i<d;i++){
		ax=max(ax,x[i]);
		ay=max(ay,y[i]);
		bx=min(bx,x[i]);
		by=min(by,y[i]);
	}
	dx=ax-bx;
	dy=ay-by;
	if (dx<dy) swap(dx,dy);
	if (dx>=n||dy>=m) return;
	if (d==8){
		if (!(x[7]==0&&y[7]<=0)) return;
		sum+=(-1*y[7]-1);
		area=0;
		x[8]=y[8]=0;
		for (i=0;i<8;i++) area+=(x[i+1]*y[i]-x[i]*y[i+1]);
		//if (x[1]==1 && y[1]==1 && x[2]==2 && y[2]==1 && x[3]==3&&y[3]==0
		//	&&x[4]==3&&y[4]==0&&x[5]==2&&y[5]==-1&&x[6]==1&&y[6]==-1&&x[7]==0&&y[7]==0)
		//	printf("%d %d %d\n",area,sum,k);
		if (area==0) return;
		int dd=area+2+sum;
		dd/=2;
		if (dd>=k){
			ans=min(ans,sum);
		//	if (sum==5){
		//		for (i=0;i<8;i++) printf("(%d,%d)",x[i],y[i]);
		//		printf("\n");
	//		}
		}
		return;
	}
	for (i=0;i<n;i++){
		x[d]=x[d-1]+i*mx[d];
		y[d]=y[d-1]+i*my[d];
		dfs(x[d],y[d],d+1,sum+i);
	}
}
int main(){
    freopen("a.in","r",stdin);
    freopen("a.out","w",stdout);
	int ca,cc=0;
	scanf("%d",&ca);
	while (ca--){
		scanf("%d%d%d",&n,&m,&k);
		if (n<m) swap(n,m);
		x[0]=0;
		y[0]=0;
		ans=k;
		dfs(0,0,1,1);
		printf("Case #%d: %d\n",++cc,ans);
	}
	return 0;
}
