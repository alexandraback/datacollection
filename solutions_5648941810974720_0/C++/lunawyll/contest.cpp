#include <bits/stdc++.h>

using namespace std;


void task();

int main() {
#ifdef LUNAWYLL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#else
//	 freopen("segmentupdate.in", "r", stdin);
//	 freopen("segmentupdate.out", "w", stdout);
#endif
	task();
#ifdef LUNAWYLL
	//cout << "\n============\n" <<(double)clock()/CLOCKS_PER_SEC;
#endif
	return 0;
}

#ifdef LUNAWYLL
#define dbg(x) cout << #x << " = " << (x) << endl;
#define dbg2(a, b) cout << #a << " = " << (a) << "; "<<\
#b << " = " << (b) << endl;
#define dbg3(a, b, c) cout << #a << " = " << (a) << "; "<<\
		#b << " = " << (b) << "; "<<\
#c << " = " << (c) << endl;
#else
#define dbg(...) (void(1));
#define dbg2(...) (void(1));
#define dbg3(...) (void(1));
#endif

typedef long long int llint;
typedef vector<int> vi;
typedef pair<int, int> pii;
#define ALL(v) ((v).begin()), ((v).end())

const int N = 3e3 + 10;
const llint MOD = (llint)1e9 + 7;
const int INF = 0x3f3f3f3f;
const llint LINF = (llint)8e18 + 100;
const int BUF_SIZE = (int)1e6 + 10;



void task(){
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i){
		string s;
		cin >> s;
		int a[255]{};
		int n = s.length();
		for (int i = 0; i < n; ++i){
			++a[s[i]];
		}
		int ans[10]{};
		while (a['Z'] > 0){
			ans[0]++;
			--a['Z'];--a['E'];--a['R'];--a['O'];
		}
		while (a['G'] > 0){
			ans[8]++;
			--a['E'];--a['I'];--a['G'];--a['H'];--a['T'];
		}
		while (a['X'] > 0){
			ans[6]++;
			--a['S'];--a['I'];--a['X'];
		}
		while (a['W'] > 0){
			ans[2]++;
			--a['T'];--a['W'];--a['O'];
		}
		while (a['U'] > 0){
			ans[4]++;
			--a['F'];--a['O'];--a['U'];--a['R'];
		}
		while (a['R'] > 0){
			ans[3]++;
			--a['T'];--a['H'];--a['R'];--a['E'];--a['E'];
		}
		while (a['O'] > 0){
			ans[1]++;
			--a['O'];--a['N'];--a['E'];
		}
		while (a['F'] > 0){
			ans[5]++;
			--a['F'];--a['I'];--a['V'];--a['E'];
		}
		while (a['S'] > 0){
			ans[7]++;
			--a['S'];--a['E'];--a['V'];--a['E'];--a['N'];
		}
		while (a['N'] > 0){
			ans[9]++;
			--a['N'];--a['I'];--a['N'];--a['E'];
		}
		string str;
		for (int i = 0; i < 10; ++i)
			str += string(ans[i], char(i + '0'));
		printf("Case #%d: %s\n", i + 1, str.c_str());
	}


}

