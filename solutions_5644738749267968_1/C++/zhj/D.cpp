#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
using namespace std;
int T,tim,n,i;
double a[1200],b[1200];
int work(double a[],double b[]){
	int i,j=n;
	for(i=n;i>=1;--i){
		while(j && a[i]<b[j])j--;
		if(!j)break;
		j--;
	}
	return n-i;
}
int main(){
	freopen("D.in","r",stdin);
	freopen("D.out","w",stdout);
	for(scanf("%d",&T);T--;){
		tim++;
		scanf("%d",&n);
		for(i=1;i<=n;++i)scanf("%lf",&a[i]);
		for(i=1;i<=n;++i)scanf("%lf",&b[i]);
		sort(a+1,a+n+1);
		sort(b+1,b+n+1);
		printf("Case #%d: %d %d\n",tim,work(a,b),n-work(b,a));
	}
}
		
