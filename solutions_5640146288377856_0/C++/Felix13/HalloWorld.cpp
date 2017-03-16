#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag,
		tree_order_statistics_node_update> ordered_tree;
typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;
typedef vector<int> VI;

#define FOR(i,a,b) for(int (i)=(a);i<(b);++(i))
#define RFOR(i,a,b) for(int (i)=(a)-1;(i)>=(b);--(i))
#define For(i,a,b) for(int (i)=(a);i<(b);++(i))
#define FoR(i,a,b) for(int (i)=(a)-1;(i)>=(b);--(i))
#define INF 1000000001
#define LINF 1000000000000000001ll
#define PB push_back
#define EPS 1e-7
#define X first
#define Y second
#define MP make_pair
#define ITER(itr,c) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
#define FILL(A,value) memset(A,value,sizeof(A))
#define ALL(V) V.begin(), V.end()


int main() {
	ios::sync_with_stdio(0);
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	int t,r,c,w;
	cin>>t;
	FOR(ttt,0,t){
		cin>>r>>c>>w;
		int ans=c/w;
		ans+=w;
		if(c%w==0)ans--;
		cout<<"Case #"<<ttt+1<<": "<<ans<<"\n";
	}
	return 0;
}

