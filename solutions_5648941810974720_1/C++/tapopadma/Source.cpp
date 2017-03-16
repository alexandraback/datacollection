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
		string s;
		cin >> s;
		int n = s.length();
		map<char, int>mm;
		for (int i = 0; i < n; ++i){
			++mm[s[i]];
		}
		int cnt[10] = { 0 };
		Fill(cnt, 0);

		cnt[0] = mm['Z'];
		mm['Z'] = 0;
		mm['E'] -= cnt[0];
		mm['R'] -= cnt[0];
		mm['O'] -= cnt[0];

		cnt[6] = mm['X'];
		mm['X'] = 0;
		mm['S'] -= cnt[6];
		mm['I'] -= cnt[6];

		cnt[2] = mm['W'];
		mm['W'] = 0;
		mm['T'] -= cnt[2];
		mm['O'] -= cnt[2];

		cnt[4] = mm['U'];
		mm['U'] = 0;
		mm['F'] -= cnt[4];
		mm['O'] -= cnt[4];
		mm['R'] -= cnt[4];

		cnt[8] = mm['G'];
		mm['G'] = 0;
		mm['E'] -= cnt[8];
		mm['I'] -= cnt[8];
		mm['H'] -= cnt[8];
		mm['T'] -= cnt[8];

		cnt[1] = mm['O'];
		mm['O'] = 0;
		mm['N'] -= cnt[1];
		mm['E'] -= cnt[1];

		cnt[5] = mm['F'];
		mm['F'] = 0;
		mm['I'] -= cnt[5];
		mm['V'] -= cnt[5];
		mm['E'] -= cnt[5];

		cnt[7] = mm['V'];
		mm['V'] = 0;
		mm['S'] -= cnt[7];
		mm['E'] -= cnt[7];
		mm['E'] -= cnt[7];
		mm['N'] -= cnt[7];

		cnt[3] = mm['T'];
		mm['T'] = 0;
		mm['H'] -= cnt[3];
		mm['R'] -= cnt[3];
		mm['E'] -= cnt[3];
		mm['E'] -= cnt[3];

		cnt[9] = mm['I'];

		printf("Case #%d: ",cs++);
		for (int i = 0; i < 10; ++i){
			while (cnt[i]--){
				cout << i;
			}
		}
		el;
	}
}