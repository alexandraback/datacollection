#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cmath>
using namespace std;
int i,j,a[1200],T,t,p,n,x,y,tim;
double g[6100],s[3100][3100];
int main(){
	freopen("B.in","r",stdin);
	freopen("B.out","w",stdout);
	for(i=1;i<=750;++i)a[i]=1+(i-1)*4;
	for(i=1;i<=5000;++i)g[i]=g[i-1]+log2(i);
	for(i=1;i<=3089;++i){
		s[i][0]=pow(2,-i);
		for(j=1;j<=i;++j)s[i][j]=s[i][j-1]+
			pow(2,g[i]-g[j]-g[i-j]-i);
	}
	for(scanf("%d",&T);T--;){
		tim++;
		scanf("%d%d%d",&n,&x,&y);
		x=abs(x);
		printf("Case #%d: ",tim);
		t=(x+y)/2+1;
		if(t>750){
			printf("0.0\n");
			continue;
		}
		for(i=1;i<t;++i)n-=a[i];
		p=y+1;
		if(x==0){
			if(n<a[t])printf("0.0\n");
			else printf("1.0\n");
		}else
		if(n<p)printf("0.0\n");
		else if(n>=(a[t]-1)/2+p)printf("1.0\n");
		else printf("%.8lf\n",1.0-s[n][p-1]);
	}
//	system("pause");
}
