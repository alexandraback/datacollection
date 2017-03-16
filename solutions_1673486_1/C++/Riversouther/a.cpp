#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;

double p[100005],a[100005];

int main(){
	int i,j,k,m,n,r,c,A,B;
	double t,ans;
	freopen("A-large.in","r",stdin);
	freopen("out.txt","w",stdout);
	
	scanf("%d",&r);
	for(c=1;c<=r;++c){
		scanf("%d%d",&A,&B);
		for(i=1;i<=A;++i)	scanf("%lf",&p[i]);
		a[0]=1;
		ans=B+1+1;
		for(i=1;i<=A;++i){
			a[i]=a[i-1]*p[i];
			t=(A-i)+(B-i)+1+(1-a[i])*(B+1);
			if(t<ans)	ans=t;
		}
		printf("Case #%d: %.6lf\n",c,ans);
	}
}
