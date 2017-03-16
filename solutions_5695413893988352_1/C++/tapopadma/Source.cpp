// Headers 
#include<bits/stdc++.h>
using namespace std;
// Global declarations
typedef long long int ll;
typedef vector<int> vi;
typedef vector<char> vc;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;
const int mod = 1e9 + 7;
const int INF = 1 << 29;
// Macros
#define mp make_pair
#define el putchar('\n')
#define sp putchar(' ')
#define Fill(a,val) memset(a,val,sizeof a)
#define all(a) a.begin(),a.end()
#ifndef ONLINE_JUDGE
#define tr(a, it) for (decltype(a.begin()) it = a.begin(); it != a.end(); ++it)
#else 
#define tr(a, it) for (typeof(a.begin()) it = a.begin(); it != a.end(); ++it)
#endif
#define in(n) scanf("%d",&n)
#define inl(n) scanf("%lld",&n)
#define out(n) printf("%d",n);
#define outl(n) printf("%lld",n);


int main(){
	freopen("ip.in", "r", stdin);
	freopen("op.out", "w", stdout);
	int t;
	in(t);
	int cs = 1;
	while (t--){
		string C, J;
		cin >> C >> J;
		int n = C.length();
		int pos = 0;
		bool gr = false, sm = false, eq = false;
		for (int i = 0; i < n; ++i){
			if (C[i] != '?' and J[i] != '?'){
				if (C[i] > J[i]){
					gr = true; pos = i + 1; break;
				}
				else if (C[i] == J[i]){
					eq = true; pos = i + 1; break;
				}
				else {
					sm = true; pos = i + 1; break;
				}
			}
			else if (C[i] != '?')J[i] = C[i];
			else if (J[i] != '?') C[i] = J[i];
			else if (C[i] == '?' and J[i] == '?')C[i] = J[i] = '0';
		}
		if (eq){
			for (int i = pos; i < n; ++i){
				if (C[i] == '?' and J[i] == '?')C[i] = J[i] = '0';
				else if (C[i] != '?') J[i] = C[i];
				else if (J[i] != '?') C[i] = J[i];
			}
		}
		else if (gr){
			for (int i = pos; i < n; ++i){
				if (C[i] == '?')C[i] = '0';
				if (J[i] == '?')J[i] = '9';
			}
		}
		else if (sm){
			for (int i = pos; i < n; ++i){
				if (C[i] == '?')C[i] = '9';
				if (J[i] == '?')J[i] = '0';
			}
		}
		printf("Case #%d: ", cs++);
		cout << C << ' ' << J; el;
	}
	return 0;
}