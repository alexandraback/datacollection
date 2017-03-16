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

int T;
int n , j;
long long dvq[12];

long long GetBase(long long a,int b){
	long long ans = 0;
	long long it = log( a ) / log( b ) + 1;
	long long m = 1;
	while (it -- ){
		ans += a % b * m;
		m *= 10;
		a /= b;
	}
	
	return ans;
}

long long GetInt(long long n,long long b){
	long long ans = 0;
	long long q = 1;
	while (n > 0){
		ans += (n % 10) * q;
		n /= 10;
		q *= b;
	}
	return ans;

}
long long EnhInt(long long n,long long b){ // get interpretation of base2(n) in base b
	//cout << n << ' ' << b << '\n';

	long long ans = 0;
	long long q = 1;
	//int i = 0;
	while (n > 0){
		ans += (n % 2) * q;
		n /= 2;
		q *= b;
		//cout << q << '\n';
		//i++;
		//if (i > 500){ return 0;}
	}

	return ans;
}
long long GetD(long long value){

	for (ll d = 2;d <= 100;d++){
		if (value % d == 0){ //divisor!!
			return d;
		}
	}
	return -1;
}
void ShowBinary(long long n){
	long long v[100];
	int i = 0;
	while (n > 0){
		v[i++] = n % 2;
		n /= 2;
	}
	for (int j = i-1;j >= 0;j--){
		cout << v[j];
	}
	cout << ' ';
}
int main(){
	#ifndef ONLINE_JUDGE
	TST = 1;
	#endif
	freopen("input.in","r",stdin);
	freopen("output.out","w+",stdout);
	// read input
	cin >> T;
	cin >> n >> j;
	//ll v = EnhInt(2147483671 , 4);
	//cout << v << '\n';
	//return 0;
	//return 0;
	//ll d = GetD(v);
	//return 0;
	// solution
	long long pw = 2; //we need 2^n 
	for (int x = 0;x < n-2;x++){
		pw *= 2; 
	}

	cout << "Case #1:\n";
	long long a = 0; //actual number
	bool solved = false;
	while (not solved){

		bool bad = 0;
		long long Q = a * 2 + 1 + pw;
		//cout << Q << '\n';
		//ShowBinary(Q);
		//if (a == 11){ break; }
		for (long long b = 2;b <= 10;b++){
			//cout << "kill="<<Q << ' ' << b << '\n';
			//if (b == 4){ break; }
			long long value = EnhInt(Q , b);
			long long dv = GetD(value);

			dvq[b] = dv;
			if (dv == -1){
				bad = 1;
				break;
			}
		}

		if (not bad){
			j --;
			ShowBinary( Q );
			for (int x = 2;x <= 10;x++){
				cout << dvq[x] << ' ' ;
			}
			cout << '\n';
			if (j == 0){ solved = 1; }
		}
		a ++ ;
		//return 0;
	}
}