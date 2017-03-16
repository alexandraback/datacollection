#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
ll tmp;
int tests,ans,tc,a[21],i,j,k,n,m;
void work(ll x){
	tmp=x;
	for (;x;x/=10)
	 if (!a[x%10]) a[x%10]=1,m++;
}
int main(){
	for (tc=1,scanf("%d",&tests);tests--;tc++){
		fprintf(stderr,"%d\n",tc);
		scanf("%d",&n);
		if (!n){
			printf("Case #%d: INSOMNIA\n",tc);continue;
		}
		memset(a,0,sizeof(a));m=0;
		for (i=1;m<10;i++) work((ll)i*(ll)n);
		printf("Case #%d: %lld\n",tc,tmp);
	}
	return 0;
}
