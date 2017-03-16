#include <bits/stdc++.h>
#include <ext/hash_map>
#include <ext/hash_set>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/priority_queue.hpp>
using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;
#define XINF INT_MAX
#define INF 0x3F3F3F3F
#define MP(X,Y) make_pair(X,Y)
#define PB(X) push_back(X)
#define REP(X,N) for(int X=0;X<N;X++)
#define REP2(X,L,R) for(int X=L;X<=R;X++)
#define DEP(X,R,L) for(int X=R;X>=L;X--)
#define CLR(A,X) memset(A,X,sizeof(A))
#define IT iterator
#define RIT reverse_iterator
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> PII;
typedef vector<PII> VII;
typedef vector<int> VI;
typedef tree<int, null_type, greater<int>, rb_tree_tag, tree_order_statistics_node_update > rb_tree_set;
typedef tree<int, int, greater<int>, rb_tree_tag, tree_order_statistics_node_update > rb_tree;
#define PQ std::priority_queue
#define HEAP __gnu_pbds::priority_queue
#define X first
#define Y second
#define lson(X) ((X)<<1)
#define rson(X) ((X)<<1|1)

/*
int dp[30][30];
int dfs(int r,int c) {
	if(r%2==0&&c%3==0 || r%3==0&&c%2==0) return 2;
	int &d=dp[r][c];
	if(d) return d;
	if(r%2==0) {
		for(int j=c-3;j>=0;j-=3) {
			if(dfs(r,j)==2) return 2;
		}
	}
	if(r%3==0) {
		for(int j=c-2;j>=0;j-=2) {
			if(dfs(r,j)==2) return 2;
		}
	}
	if(c%2==0) {
		for(int j=r-3;j>=0;j-=3) {
			if(dfs(j,c)==2) return 2;
		}
	}
	if(c%3==0) {
		for(int j=r-2;j>=0;j-=2) {
			if(dfs(j,c)==2) return 2;
		}
	}
	return 1;
}
*/

int main()
{
	#ifdef LOCAL
		freopen("D-small-attempt1.in","r",stdin);
		freopen("D-small-attempt1.out","w",stdout);
	#endif
	ios::sync_with_stdio(false);
	int t,x,r,c,cs=1;
	cin>>t;
	while(t--) {
		cin>>x>>r>>c;
		int ric = 0;
		if(x==4) {
			ric = r+c!=8 && r+c!=7;
		}else if(x==1) {
			ric = 0;
		}else if(x==2) {
			ric = r*c%2;
		}else{ // x==3
			//ric = dfs(r,c)==1;
			ric = !(r==3 && c>=2 || c==3 && r>=2);
		}
		//cout<<x<<' '<<r<<' '<<c<<' '<<ric<<endl;
		cout<<"Case #"<<cs++<<": "<<(ric?"RICHARD":"GABRIEL")<<endl;
	}
	return 0;
}


