#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
int i,j,k,l,n,m,a[1200],ans,res,tim,T,A;
int main(){
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	for(scanf("%d",&T);T--;){
		tim++;
		scanf("%d%d",&A,&n);
		for(i=1;i<=n;++i)scanf("%d",&a[i]);
		sort(a+1,a+n+1);
		ans=100000;
		res=0;
		if(A==1)ans=n;
		else{
			for(i=1;i<=n;++i){
				if(A<=a[i]){
					ans=min(ans,res+(n-i+1));
					A+=A-1;
					res++;
					i--;
				}else A+=a[i];
			}
			ans=min(ans,res);
		}
		printf("Case #%d: %d\n",tim,ans);
	}
}
