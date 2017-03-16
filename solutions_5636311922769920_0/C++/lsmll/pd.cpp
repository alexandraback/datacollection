#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
ll w;
int lim,i,j,k,n,m,tests,tc,t;
int main(){
	for (tc=1,scanf("%d",&tests);tests--;tc++){
		scanf("%d%d%d",&n,&m,&lim);
		fprintf(stderr,"%d\n",tc);printf("Case #%d: ",tc);
		if (lim*m<n){
			puts("IMPOSSIBLE");continue;
		}
		t=(n-1)/m+1;
		for (i=1;i<=t;i++){
			for (w=0,j=1;j<=m;j++)
			 w=w*(ll)n+min(n-1,(i-1)*m+j-1);
			printf("%lld%c",w+1,(i==t)?'\n':' ');
		}
	}
	return 0;
}
