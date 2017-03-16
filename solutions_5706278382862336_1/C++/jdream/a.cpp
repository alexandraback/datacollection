#include<cstdio>
#include<cstring>
#define LL long long
using namespace std;
LL x,y,z,y1;
int T,TT,tot;
LL gcd(LL x,LL y){
	if(y==0)return x;
	return gcd(y,x%y);
}
int main(){
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	scanf("%d",&TT);
	for(T=1;T<=TT;T++){
		scanf("%I64d/%I64d",&x,&y);
		printf("Case #%d: ",T);
		z=gcd(x,y);x/=z;y/=z;
		for(y1=y;y1>1;y1>>=1)
			if(y1&1)break;
		if(y1>1){
			puts("impossible");
			continue;
		}
		tot=0;
		for(z=2;z<=y;z*=2){
			tot++;
			if(y/z<=x){
				printf("%d\n",tot);
				break;
			}
		}
	}
}