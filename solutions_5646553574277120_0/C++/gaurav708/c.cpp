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

int t,c,d,v;
int den[10];
bool cpos[35],npos[35];

int main() {
	gi(t);
	rep(z,t) {
		printf("Case #%d: ", z+1);
		gi(c); gi(d); gi(v);
		v++;
		rep(i,d) gi(den[i]);
		fill(cpos,cpos+35,false);
		cpos[0]=true;
		rep(i,d) {
			rep(j,v) npos[j]=cpos[j];
			rep(j,v-den[i])
				if(cpos[j]==true)
					npos[j+den[i]]=true;
			rep(j,v) cpos[j]=npos[j];
		}
		int ans=0;
		rep(i,v) {
			if(cpos[i]) continue;
			rep(j,v) npos[j]=cpos[j];
			rep(j,v-i)
				if(cpos[j]==true)
					npos[j+i]=true;
			rep(j,v) cpos[j]=npos[j];
			ans++;
		}
		printf("%d\n", ans);
	}
	return 0;
}