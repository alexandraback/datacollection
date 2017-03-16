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

int t;
long long n;
bool H[10];

int main(){
	freopen("input.in","r",stdin);
	freopen("output.out","w+",stdout);

	clock_t begin = clock();

	// read input
	cin >> t;
	for (int x = 1;x <= t;x++){
		cin >> n;
		//if (x != 3){ continue; }
		if (n == 0){
			cout << "Case #"<<x<<": "<<"INSOMNIA" << '\n';
			continue;
		}
		memset(H , 0 ,10);

		long long v = 0;
		int q = 10;
		long long it = 0;

		while (q > 0 and v < LLONG_MAX - n - 5 and it/2 < 10e7){
			v += n;
			//cout << q << ' ' << v << '\n';
			long long c = v;
			while (c > 0){
				//cout << "c="<<c % 10 << '\n';
				if (not H[c%10]){
					H[c%10] = 1;
					q --;
				}
				c /= 10;
			}
			it ++;
		}
		if (q == 0){
			cout << "Case #"<<x<<": "<<v << '\n';
		}else{
			cout << "Case #"<<x<<": INSONMIA" << '\n';
		}
	}

	clock_t end = clock();
  	double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
  	//cout << elapsed_secs << '\n';
}