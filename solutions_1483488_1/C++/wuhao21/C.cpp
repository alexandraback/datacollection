#include <cstdio>
#include <cstring>
using namespace std;
int ans=0,T,l,r;
int num[10];
int main(){
//	freopen("C.in","r",stdin);
//	freopen("C.out","w",stdout);
	scanf("%d",&T);
	for (int t=1;t<=T;t++){
		scanf("%d%d",&l,&r);
		int p=1;
		ans=0;
		while (l>=p*10)
			p*=10;
		for (int i=l;i<=r;i++){
			if (i>p*10) p*=10;
			int cnt=0;
            for (int j=10;j<=p;j*=10){
				int tmp=(i%j)*(p/j*10)+i/j,ff=0;
				for (int x=1;x<=cnt;x++) if (tmp==num[x]) ff=1;
				if (tmp>i && tmp<=r && ff==0){
					ans++;
					cnt++,num[cnt]=tmp;
				}
			}
		}
		printf("Case #%d: ",t);
		printf("%d\n",ans);
	}
	return 0;
}
