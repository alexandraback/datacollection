#include<cstdio>
int x[1111],y[1111],f[1111];
int main(){
	int t,i,ans,res,j,n,mxn,pos;
	bool pd;
//	freopen("b.in","r",stdin);
//	freopen("b.out","w",stdout);
	scanf("%d",&t);
	for (i=1;i<=t;i++){
		scanf("%d",&n);
		ans=res=0;
		for (j=1;j<=n;j++){
			scanf("%d%d",x+j,y+j);
			f[j]=0;
		}
		while (res!=2*n){
			mxn=0,pos=0,pd=false;
			for (j=1;j<=n;j++){
				if (f[j]!=2 && res>=y[j]) {pd=true; break;}
				if (f[j]==0 && res>=x[j] && y[j]>=mxn) {pos=j; mxn=y[j];}
			}
			if (pd){
				res+=2-f[j];
				f[j]=2;
			} else
			if (pos){
				res++;
				f[pos]=1;
			} else break;
			ans++;
		}
		printf("Case #%d: ",i);
		if (res==2*n) printf("%d\n",ans); else printf("Too Bad\n");
	}
	return 0;
}
