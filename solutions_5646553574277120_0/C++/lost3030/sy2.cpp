#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const double pi = acos(-1.0);
const double eps = 1e-8;
//const ll INF=(_I64_MAX)/2;
//#pragma comment(linker, "/STACK:102400000,102400000")
const int inf = 0x3f3f3f3f;
#define maxx(a) memset(a, 0x3f, sizeof(a))
#define minn(a) memset(a, 0xC0, sizeof(a))
#define zero(a) memset(a, 0, sizeof(a))
#define FILL(a,b) memset(a, b, sizeof(a))
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)
#define srep(i,n) for(i = 1;i <= n;i ++)
#define MP make_pair
#define fi first
#define se second
typedef pair <int, int> PII;
typedef pair <ll , ll > PX ;

const int N = 30 + 11;
int C,D,V;
int a[N];

vector<int> x;
bool f[N];

bool g[N];
bool jud() {
	FILL(g,0);
	g[0]=1;
	int i,j;
	rep(i,x.size()) {
		for(j=V;j>=0;j--) {
			if(g[j]) {
				if(j+x[i] <= V) {
					g[j+x[i]] = 1;
				}
			}
		}
	}
	srep(i,V) {
		if(!g[i]) return 0;
	}
	return 1;
}

vector<int> rest;
int sy;
void dfs(int st,int dp) {
	if(sy < dp+1) return;
	for(int i = st;i < rest.size();i ++) {
		x.push_back(rest[i]);
		if(jud()) {
			sy = min(sy,dp+1);
		}
		else{
			dfs(i+1,dp+1);
		}
		x.pop_back();
	}
}

void work() {
	cin>>C>>D>>V;
	int i,j;
	x.clear();
	FILL(f,0);
	rep(i,D) {
		cin>>a[i];
		f[a[i]] = 1;
		x.push_back(a[i]);
	}

	if(jud()) {
		puts("0");return;
	}

	rest.clear();
	srep(i,V) if(!f[i]) rest.push_back(i);
	sy = rest.size();
	dfs(0,0);

	cout<<sy<<endl;
}

int main() {
#ifdef LOCAL
    freopen( "in.txt", "r" , stdin);
 freopen ("out.txt","w",stdout );
#endif
  //  init();

    //getprime(N-1);
    int cas = 1;
    int t;
    cin>>t;
    while(t--) {
    	printf("Case #%d: ",cas++);
    	work();
    }

    return 0;
}

