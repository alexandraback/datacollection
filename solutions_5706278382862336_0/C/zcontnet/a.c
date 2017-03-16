#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<string>
#include<queue>
#include<map>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;

long long gcd(long long a,long long b) {
	if(b==0) return a;
	return gcd(b,a%b);
}

int main() {
	freopen("1.in","r",stdin);
	freopen("ans.txt","w",stdout);
	
	int T,tc;
	scanf("%d",&T);
	for(tc=1;tc<=T;tc++) {
		long long P,Q;
		scanf("%lld/%lld",&P,&Q);
		long long g=gcd(P,Q);
		P/=g,Q/=g;
		int i=0;
		long long t=Q;
		while(t%2==0) t/=2;
		if(t!=1) {
			printf("Case #%d: impossible\n",tc);
		} else {
			for(i=1;i<=40;i++) {
				if(P*2>=Q) {
					long long a=P*2-Q,b=Q;
					long long g=gcd(a,b);
					a/=g,b/=g;
					if(b<=(1LL<<(40-i))) {
						printf("Case #%d: %d\n",tc,i);
					} else 
						printf("Case #%d: impossible\n",tc);
					break;
				}
				P*=2;
			}
		}
	}
}


