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

const int N = 200000 + 11;

int k,l,s;
string key;
string tar;

bool tag;
double init() {
	cin>>k>>l>>s;
		cin>>key;
		cin>>tar;
		int i,j,t;

		if(s < tar.length()) {
		//	printf("0.0\n");return;
			return 0;
		}
		int ed = tar.length();
		double z = 0;
		rep(i,tar.size()) {
			int tp = 0;
			rep(j,key.size()) {
				if (key[j] == tar[i]) tp++;
			}
			if(tp == 0) {
		//		printf("0.0\n");return;
				return 0;
			}
			z += log(tp*1.0);
		}
		tag = 1;
		z += log(s-ed+1);
		z -= l*log(k*1.0);
		double ans1 = exp(z);
		return ans1;
}

void work() {
	tag = 0;
	double ans1 = init();
	if(tag == 0) {
		puts("0.0");return;
	}

	int i,j;
	int st = l;
	for(i=1;i<l;i++) {
		int z = 0;
		for(j = 0;i + j < l;j ++) {
			if(tar[j] != tar[i+j]) {
				z = 1;
				break;
			}
		}
		if(z == 0) {
			st = i;break;
		}
	}

	double res = 1 + (int)((s - l)/(st));
	printf("%.9lf\n",res - ans1);




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

