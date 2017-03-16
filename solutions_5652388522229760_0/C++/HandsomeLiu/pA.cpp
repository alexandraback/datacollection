#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;
const int ttl=(1<<10)-1;
int f(int n){
	int rst=0;
	while(n){
		rst|=(1<<(n%10));
		n/=10;
	}
	return rst;
}
int main(){
	freopen("inputA","r",stdin);
	freopen("outputA.out","w",stdout);
	int T;
	scanf("%d",&T);
	for(int t=1;t<=T;t++){
		int n;
		scanf("%d",&n);
		printf("Case #%d: ",t);
		if(n){
			int ans=n,stt=f(ans);
			while(stt!=ttl){
				ans+=n;
				stt|=f(ans);
			}
			printf("%d\n",ans);
		}
		else puts("INSOMNIA");
	}
}

