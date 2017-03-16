#include<cstdio>
#include<bitset>
#include<algorithm>
using namespace std;

long long gcd(long long a, long long b){return b?gcd(b,a%b):a;}

typedef long long ll;

int main(){
	freopen("A-small-attempt0.in","r",stdin);
	freopen("small.txt","w",stdout);
	int T;
	scanf("%d",&T);
	for(int tc=1; tc<=T;tc++){
		printf("Case #%d: ", tc);
		ll p,q;
		char c;

		scanf("%lld%c%lld", &p, &c, &q);

		ll g = gcd(p,q);

		p/=g; q/=g;

		bitset<40> P(p), Q(q);

		if(Q.count() > 1)
			printf("impossible\n");
		else{
			int l=0;
			for(int i=0; i<40; i++)
				if(Q.test(i))
					l = max(l, i);

			int ans=1;
			while(1){
				if(P.test(l-ans)){
					printf("%d\n",ans);
					break;
				}
				else ans++;
			}
		}
	}
}