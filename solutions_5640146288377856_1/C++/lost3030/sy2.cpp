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
int dp[100][100];
void work() {
	int r,c,w;
	cin>>r>>c>>w;
	if(r > c) swap(r,c);

	int ans;
	if(r == 1) ans = dp[w][c];
	else {
		ans = (r-1) * c + dp[w][c];
		if(w <= r)
			ans = min(ans, (c-1)*r + dp[w][r]);
	}


	cout<<ans<<endl;


}

int main() {
#ifdef LOCAL
    freopen( "in.txt", "r" , stdin);
 freopen ("out.txt","w",stdout );
#endif
  //  init();

    int i,j;
    rep(i,11) dp[i][i] = i;
    rep(i,11) dp[1][i] = i;
    dp[2][3] = dp[2][4] = 3;
    for(i = 5;i < 11;i ++) dp[2][i] = 1 + dp[2][i-2];

    for(i = 4;i <= 6;i ++) dp[3][i] = 4;
    for(i = 7;i <= 11;i ++) dp[3][i] = 1+ dp[3][i-3];

    for(i = 5;i <= 8;i ++) dp[4][i] = 5;
    for(i = 9;i <= 11;i ++) dp[4][i] = 1+ dp[4][i-4];

    for(i = 5;i <= 10;i ++) {
    	for(j = i+1;j < 11;j ++) dp[i][j] = i+1;
    }

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

