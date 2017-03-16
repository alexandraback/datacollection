#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> PII;
typedef long long ll;
template<class T> T sqr(T x) {return x*x;}
#define pi acos(-1)
#define INF 100000000
#define debug(x) cerr<<#x"="<<(x)<<"\n";
#define foreach(it,v) for (__typeof((v).begin()) it=(v).begin();it!=(v).end();it++)

int main() {
	int i,te,tt;
	ll g,a,b,w;
	scanf("%d",&tt);
	for (te=1;te<=tt;te++) {
		scanf("%I64d/%I64d",&a,&b);
		g=__gcd(a,b);
		a/=g;
		b/=g;
		int flag=0;
		w=1;
		for (i=0;i<=40;i++) {
			if (w==b) flag=1;
			w*=2;
		}
		printf("Case #%d: ",te);
		if (flag) {
			int ans=100;
			for (i=0;i<=40;i++) {
				if (a>=b) {
					ans=i;
					break;
				}
				b/=2;
			}
			printf("%d\n",ans);
		}
		else puts("impossible");
	}
}
