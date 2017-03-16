#include<cstdio>
#include<algorithm>
#include<functional>
using namespace std;
int T,n,s,p,a[105],r,q,ac;
int main(){
	scanf("%d",&T);
	for (int o=1; o<=T; o++){
		scanf("%d%d%d",&n,&s,&p);
		for (int i=1; i<=n; i++)
		    scanf("%d",&a[i]);
		sort(a+1,a+n+1,greater<int>());
		ac=0;
		for (int i=1; i<=n; i++){
			r=a[i]%3; q=a[i]/3;
			if (q>=p) ++ac;
			else if (q+1==p&&r>0) ++ac;
			else if (r!=1){
				 if (r==0&&a[i]&&q+1>=p&&s) ++ac,--s;
				 else if (r==2&&q+2>=p&&s) ++ac,--s;
			}
		}
		printf("Case #%d: %d\n",o,ac);
	}
	return 0;
}
