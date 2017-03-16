#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
typedef pair<int,int> pii;

#define forup(i,a,b) for(int i=(a); i<(b); ++i)
#define fordn(i,a,b) for(int i=(a); i>(b); --i)
#define rep(i,a) for(int i=0; i<(a); ++i)

#define gi(x) scanf("%d ",&x)
#define gl(x) scanf("%lld",&x)
#define gd(x) scanf("%lf",&x)
#define gs(x) scanf(" %s",x)

#define fs first
#define sc second

#define pb push_back
#define mp make_pair

const int inf=numeric_limits<int>::max();
const LL linf=numeric_limits<LL>::max();

int t,r,c,w;

int main() {
	gi(t);
	rep(z,t) {
		printf("Case #%d: ", z+1);
		gi(r); gi(c); gi(w);
		if(w==1) printf("%d\n", r*c);
		else if(w==c) printf("%d\n", r+c-1);
		else {
			int ans = (c/w)*r + (w-1) + (c%w==0 ? 0 : 1);
			printf("%d\n", ans);
		}
	}
	return 0;
}