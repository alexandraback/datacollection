#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define Fit(i,c) for (__typeof__((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define inf 1000000005
#define all(a) (a).begin(), (a).end()
#define ms(a,x) memset(a, x, sizeof(a))
#define mod 100000000
#define sz(a) ((int)(a).size())

template<class T> int getbit(T s, int i) { return (s >> i) & 1; }
template<class T> T onbit(T s, int i) { return s | (T(1) << i); }
template<class T> T offbit(T s, int i) { return s & (~(T(1) << i)); }
template<class T> int cntbit(T s) { return __builtin_popcount(s);}
#define Rep(i,n) for(int i = 0; i < (n); ++i)
#define Repd(i,n) for(int i = (n)-1; i >= 0; --i)
#define For(i,a,b) for(int i = (a); i <= (b); ++i)
#define Ford(i,a,b) for(int i = (a); i >= (b); --i)

typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
#define eps 1e-9
typedef pair<int, int> II;
template<class T> T gcd(T a, T b){ T r; while (b != 0) { r = a % b; a = b; b = r; } return a;}
template<class T> T lcm(T a, T b) { return a / gcd(a, b) * b; }
#define PI 2 * acos(0)

#define maxn 1000005

int test;
ll n, x;
string s, str;
int nex[5][5];
int a[maxn];

int cal(char ch){
	if(ch == 'i') return 2;
	if(ch == 'j') return 3;
	return 4;
}

void solve(int itest){

	cin >> n >> x >> str;
	s = "";
	Rep(run, 8) s += str;
	Rep(i, n * 8) a[i + 1] = cal(s[i]);

	int run = 1, RR = 1;
	For(i, 1, n){
		int c = nex[abs(run)][a[i]];
		if(run < 0) run = -c;
		else run = c;
	}
	RR = run;
	run = 1;
	int first2 = -1, first4 = -1;
	For(i, 1, n * 8){
		int c = nex[abs(run)][a[i]];
		if(run < 0) run = -c;
		else run = c;
		if(run == 2 && first2 == -1){
			first2 = i;
		}
		if(run == 4 && first2 != -1 && first4 == -1){
			first4 = i;
		}
	}

	string res;
	bool ok = false;
	if(RR == -1 && x % 2 == 1) ok = true;
	if(RR != 1 && RR != -1 && x % 4 == 2) ok = true;

	if(ok && first4 != -1 && first4 <= n * x) res = "YES";
	else res = "NO";

	cout << "Case #" << itest << ": " << res << endl;
}

int main(){
	freopen("in.txt", "r",stdin);
	freopen("out.txt", "w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    nex[1][1] = 1; nex[1][2] = 2; nex[1][3] = 3; nex[1][4] = 4;
    nex[2][1] = 2; nex[2][2] = -1; nex[2][3] = 4; nex[2][4] = -3;
    nex[3][1] = 3; nex[3][2] = -4; nex[3][3] = -1; nex[3][4] = 2;
    nex[4][1] = 4; nex[4][2] = 3; nex[4][3] = -2; nex[4][4] = -1;

    cin >> test;

    Rep(run, test){
    	solve(run + 1);
    }

    return 0;
}
