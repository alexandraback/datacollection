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

int g(string s){
	int n = s.length();
	int ret = 0;
	for (int i = 0; i < n; ++i){
		ret = ret * 10 + s[i] - '0';
	}
	return ret;
}

void f(int n, string &ss, string C, string J, int &diff, int &ans1, int &ans2, string &s1, string &s2){
	if (n == 0){
		string a = C, b = J;
		int tot = 0;
		int n1 = C.length();
		for (int i = 0; i < n1; ++i){
			if (C[i] != '?')continue;
			a[i] = ss[tot++];
		}
		int n2 = J.length();
		for (int i = 0; i < n2; ++i){
			if (J[i] != '?')continue;
			b[i] = ss[tot++];
		}
		int ia = g(a);
		int ib = g(b);
		int df = abs(ia - ib);
		if (df < diff){
			diff = df;ans1 = ia;ans2 = ib;s1 = a;s2 = b;
		}
		else if (df == diff){
			if (ia < ans1){
				diff = df; ans1 = ia; ans2 = ib; s1 = a; s2 = b;
			}
			else if (ia == ans1){
				if (ib < ans2){
					diff = df; ans1 = ia; ans2 = ib; s1 = a; s2 = b;
				}
			}
		}
	}
	else{
		for (char d = '0'; d <= '9'; ++d){
			ss += d;
			f(n - 1, ss, C, J, diff, ans1, ans2, s1, s2);
			ss.erase(ss.end() - 1, ss.end());
		}
	}
}

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
		int cnt = 0;
		for (int i = 0; i < n; ++i){
			cnt += C[i] == '?';
		}
		int m = J.length();
		for (int i = 0; i < m; ++i){
			cnt += J[i] == '?';
		}
		printf("Case #%d: ", cs++);
		if (cnt == (n + m)){
			for (int i = 0; i < n; ++i)putchar('0'); sp;
			for (int i = 0; i < m; ++i)putchar('0'); el; continue;
		}
		int diff = INF;
		int ans1 = INF;
		int ans2 = INF;
		string ss;
		string s1, s2; ss.clear(); s1.clear(); s2.clear();
		f(cnt, ss, C, J, diff, ans1, ans2, s1, s2);
		cout << s1 << ' ' << s2; el;
	}
	return 0;
}