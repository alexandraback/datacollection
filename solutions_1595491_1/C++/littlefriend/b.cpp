#include<cstdio>
int main(){
	int n,a,b,c,res,i,j,k;
//	freopen("b.in","r",stdin);
//	freopen("b.txt","w",stdout);
	scanf("%d",&n);
	for (i=1;i<=n;i++){
		printf("Case #%d: ",i);
		scanf("%d%d%d",&a,&b,&c);
		res=0;
		for (j=0;j<a;j++){
			scanf("%d",&k);
			if (k>=c*3-2) res++; else
				if (c>1 && k>=c*3-4 && b) {res++; b--;}
		}
		printf("%d\n",res);
	}
	return 0;
}
