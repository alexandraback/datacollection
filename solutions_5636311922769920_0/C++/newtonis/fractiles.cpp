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
void ShowVec(vector <int> vs){
	cout << "{";
	for (int x = 0;x < vs.size();x++){
		cout << vs[x] ;
		if (x != vs.size()-1){
			cout << ",";
		}
	}
	cout << "}\n";
}
int T;
long long k , c , s;
vector <long long> ans;

int main(){
	freopen("input.in","r",stdin);
	freopen("output.out","w+",stdout);

	cin >> T;
	for (int x = 1;x <= T;x++){
		cin >> k >> c >> s;
		ans.clear();
		//if (x != 28){ continue; }

		//cout << "("<<k<<","<<c<<","<<s<<")\n";
		long long w = 0; //actual code used
		long long d = 0;
		long long code = 0;
		vector <int> vs;

		vector <ll> pw;
		ll v = 1;
		for (int i = 0;i < c;i++){
			pw.push_back(v);
			v *= k;
		}
		while (1){
			//cout << ' ' << d << ' ' << w << ' \n'

			code += w * pw[c-d-1]; //pow(k , c-d-1);
			vs.push_back(w);
			d ++;
			if (d == c){
				d = 0;
				//ShowVec(vs);
				vs.clear();
				ans . pb(code);
				code = 0;
				if (w == k-1){
					break;
				}
			}
			w = min(w + 1 , k-1);
		}
		if (ans.size() > s){
			cout << "Case #"<<x<<": IMPOSSIBLE\n";
		}else{
			cout << "Case #"<<x<<": ";
			for (int i = 0;i < ans.size();i++){
				cout << ans[i] + 1 << ' ';
			}
			cout << '\n';
		}
	}

}