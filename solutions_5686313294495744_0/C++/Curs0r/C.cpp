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
typedef tree<int, int, greater<int>, rb_tree_tag, tree_order_statistics_node_update > rb_tree;
#define ALL(X) (X).begin(),(X).end()
#define PQ std::priority_queue
#define HEAP __gnu_pbds::priority_queue
#define X first
#define Y second
#define lson(X) ((X)<<1)
#define rson(X) ((X)<<1|1)

int a[1000], b[1000];
int c1[1000], c2[1000];
int main()
{
#ifdef LOCAL
	   freopen("C-small-attempt0.in","r",stdin);
	   freopen("C-small-attempt0.out","w",stdout);
#endif
	ios::sync_with_stdio(false);
	int t,cs=1;
	cin>>t;
	while(t--) {
		int n;
		cin>>n;
		unordered_map<string, int> mp1, mp2;
		int cc1=0,cc2=0;
		REP(i,n) {
			string s1,s2;
			cin>>s1>>s2;
			if(mp1.count(s1)) {
				a[i] = mp1[s1];
			}else a[i] = mp1[s1] = cc1++;
			if(mp2.count(s2)) {
				b[i] = mp2[s2];
			}else b[i] = mp2[s2] = cc2++;
		}
		int mn = n+1;
		REP(i,1<<n) {
			REP(j,n) c1[j] = c2[j] = 0;
			REP(j,n) {
				if(i>>j&1) c1[a[j]]++, c2[b[j]]++;
			}
			int f = 0;
			REP(j,cc1) if(c1[j] == 0) f = 1;
			REP(j,cc2) if(c2[j] == 0) f = 1;
			if(!f) mn = min(mn, (int)__builtin_popcount(i));
		}
		cout<<"Case #"<<cs++<<": "<<n-mn<<endl;
	}
	return 0;
}


