#include <cstdio>
using namespace std;
int T,n,s,p,tot,a,b,c;
int main(){
//	freopen("B.in","r",stdin);
//	freopen("B.out","w",stdout);
	scanf("%d",&T);
	for (int t=1;t<=T;t++){
		int ans=0;
		scanf("%d%d%d",&n,&s,&p);
		for (int i=1;i<=n;i++){
			scanf("%d",&tot);
			if (tot>=p*3-2) ans++;
			else
				if (tot>=p*3-4 && p>1 && s) {s--; ans++;}
		}
		printf("Case #%d: ",t);
		printf("%d\n",ans);
	}
	return 0;
}
