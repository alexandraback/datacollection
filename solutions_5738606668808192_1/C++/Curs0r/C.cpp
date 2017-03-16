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
#define __DATASET__ "C-large"

#define MAXN 1000000
int vis[MAXN]={1,1}, phi[MAXN];
int prime[MAXN], n_prime;
void Eular() {
	n_prime=0;
	phi[1]=1;
	for(int i = 2; i < MAXN; i++) {
		if(!vis[i]) {
			prime[n_prime++] = i;
			phi[i] = i-1;
		}
		for(int j = 0; j < n_prime && i * prime[j] < MAXN; j++) {
			vis[i * prime[j]] = 1;
			if(i % prime[j] == 0) {
				phi[i * prime[j]] = phi[i] * prime[j];
				break;
			}else
				phi[i * prime[j]] = phi[i] * phi[prime[j]];
		}
	}
}

string toBin(ll n) {
    string s;
    do{
        s = s + char('0'+n%2);
        n /= 2;
    }while(n);
    reverse(s.begin(), s.end());
    return s;
}

int gao(ll n, int b) {
    for(int i = 0; i < 100; i++) {
        int p = prime[i];
        int r = 0;
        ll x = n;
        int t = 1;
        while(x) {
            if(x%2) r = (r+t)%p;
            t = t*b%p;
            x/=2;
        }
        if(r == 0) return p;
    }
    return -1;
}

int main()
{
#ifdef LOCAL
    freopen(__DATASET__ ".in","r",stdin);
    freopen(__DATASET__ ".out","w",stdout);
#endif // LOCAL
    Eular();
    ios::sync_with_stdio(false);
    int t,cs=1;
    cin>>t;
    while(t--) {
        int n,c;
        cin>>n>>c;
        cout<<"Case #"<<cs++<<":"<<endl;
        ll s = (1LL<<(n-1)) + 1;
        while(c) {
            int f = 0;
            VI v;
            REP2(i,2,10) {
                int r = gao(s, i);
                v.PB(r);
                if(r == -1) f = 1;
            }
            if(!f) {
                cout<<toBin(s);
                REP(i,v.size()) {
                    cout<<' '<<v[i];
                }
                cout<<endl;
                c--;
            }
            s+=2;
        }
    }
    return 0;
}

