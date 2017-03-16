#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
ll m,t;
int i,j,k,n,tests,tc,a[61][61];
int main(){
	for (tc=1,scanf("%d",&tests);tests--;tc++){
		fprintf(stderr,"* %d\n",tc);
		scanf("%d%lld",&n,&m);
		printf("Case #%d: ",tc);
		if (m>(ll)1<<(n-2)){
			puts("IMPOSSIBLE");continue;
		}
		puts("POSSIBLE");
		memset(a,0,sizeof(a));
		for (i=2;i<n;i++)
		 for (j=i+1;j<=n;j++) a[i][j]=1;
		for (i=2;i<=n;i++){
			t=(ll)1<<(max(0,n-i-1));
			if (m>=t) a[1][i]=1,m-=t;
		}
		for (i=1;i<=n;i++){
			for (j=1;j<=n;j++) printf("%d",a[i][j]);
			puts("");
		}
	}
	return 0;
}
