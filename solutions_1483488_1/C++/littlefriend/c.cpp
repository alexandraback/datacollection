#include<cstdio>
int pd[2000001];
int main(){
	int n,i,k,l,a,b,res,j,now;
//	freopen("c.in","r",stdin);
//	freopen("c.txt","w",stdout);
	scanf("%d",&n);
	for (i=1;i<=n;i++){
		scanf("%d%d",&a,&b);
		res=0;
		for (j=1;j<=2000000;j++) pd[j]=0;
		for (j=a;j<=b;j++){
			for (k=1;k<=j;k*=10);
			for (l=1;l<=j;l*=10){
				now=(j%l)*(k/l)+(j/l);
				if (now>j && now<=b && pd[now]!=j){
					pd[now]=j;
					res++;
				}
			}
		}
		printf("Case #%d: %d\n",i,res);
	}
	return 0;
}
