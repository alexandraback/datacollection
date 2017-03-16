#include <bits/stdc++.h>

using namespace std;

#define len(x) ((int)(x).size())
#define pb push_back
#define mp make_pair
#define debug(x) cerr << #x << " is " << x << endl;
#if ( ( _WIN32 || __WIN32__ ) && __cplusplus < 201103L)
    #define lld "%I64d"
#else
    #define lld "%lld"
#endif

typedef long long ll;
typedef pair <int,int> pi;

const long double EPS = 1e-10;
const ll MOD = 1e9 + 7;
const ll INF = 1e18;
const long double PI = 3.1415926535897932384626433832795028841;

bool TST = 0;
ll powmod(ll a,ll b) {ll res=1;a%=MOD;for(;b;b>>=1){if(b&1)res=res*a%MOD;a=a*a%MOD;}return res;}
void Show(int *QQ,int N){ if (not TST){ return; } for (int x = 0;x < N;x++){ cout << QQ[x]; if (x != N-1){ cout << ','; } } cout << '\n'; }
void ShowLL(ll *QQ,int N){ if (not TST){ return; } for (int x = 0;x < N;x++){ cout << QQ[x]; if (x != N-1){ cout << ','; } } cout << '\n'; }

int n;
char D[1000];

int main(){
	freopen("input.in","r",stdin);
	freopen("output.out","w+",stdout);
	
	// read input
	cin >> n;
	for (int x = 1;x <= n;x++){
		cin >> D;
		int ld = strlen(D);
		int c = 0;
		for (int y = 0;y < ld-1;y++){
			if (D[y] != D[y+1]){
				c ++;
			}
		}
		if (D[ld-1] == '-'){
			c ++;
		}
		cout << "Case #"<<x<<": " << c << '\n';
	}
	// solution
}