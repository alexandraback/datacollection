#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
#include<queue>
#include<set>
#include<vector>
#include<cmath>
#include<iostream>
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
typedef long long ll;
typedef pair<int,int> PII;
const double eps = 1e-7;
const double PI = acos(-1.0);
const int oo = 1<<29;

const int N = 101111;

int main()
{
	freopen("a.in","r",stdin);
	freopen("a.ou","w",stdout);

	int T; scanf("%d",&T);
	for(int ka=1;ka<=T;ka++) {
		ll r,t;
		cin>>r>>t;
		ll lo=1,hi=min(1000000000ll,t/2/r);
		ll ans = -1;
		while(lo<=hi) {
			ll m=lo+(hi-lo)/2;
			ll s=m*r*2;
			s+=2*m*(m+1)-m*3;
			if(s<=t) {
				ans=m;
				lo=m+1;
			} else {
				hi=m-1;
			}
		}
		if(ans<0) while(1);
		cout<<"Case #"<<ka<<": "<<ans<<endl;
	}

	return 0;
}
