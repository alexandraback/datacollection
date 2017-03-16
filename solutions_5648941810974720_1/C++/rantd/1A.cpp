#include <bits/stdc++.h>
using namespace std;

#define REPU(i, a, b) for (int i = (a); i < (b); ++i)
#define REPD(i, a, b) for (int i = (a); i > (b); --i)
#define FOREACH(it, a) for (auto it = a.begin(); it != a.end(); ++it)
#define MEM(a, x) memset(a, x, sizeof(a))
#define ALL(a) a.begin(), a.end()
#define UNIQUE(a) a.erase(unique(ALL(a)), a.end())

typedef long long ll;
const int MOD = 1000000007;

template<class T, class U> inline T tmin(T a, U b) { return (a < b) ? a : b; }
template<class T, class U> inline T tmax(T a, U b) { return (a > b) ? a : b; }
template<class T, class U> inline void amax(T &a, U b) { if (b > a) a = b; }
template<class T, class U> inline void amin(T &a, U b) { if (b < a) a = b; }
template<class T> inline T tabs(T a) { return (a > 0) ? a : -a; }
template<class T> T gcd(T a, T b) { while (b != 0) { T c = a; a = b; b = c % b; } return a; }

const int N = 150;
int f[N];

int main(int argc, char *argv[]) {
	ios_base::sync_with_stdio(false);
	
	int nTest; string s;

	cin >> nTest;
	REPU(it, 1, nTest + 1) {
		cin >> s;
		MEM(f, 0);
		REPU(i, 0, s.size()) f[s[i]]++;
		string ans = "";
		REPU(i, 0, f['Z']) ans += '0';
		f['E'] -= f['Z'];
		f['R'] -= f['Z'];
		f['O'] -= f['Z'];
		f['Z'] = 0;
		REPU(i, 0, f['W']) ans += '2';
		f['T'] -= f['W'];
		f['O'] -= f['W'];
		f['W'] = 0;
		REPU(i, 0, f['U']) ans += '4';
		f['F'] -= f['U'];
		f['O'] -= f['U'];
		f['R'] -= f['U'];
		f['U'] = 0;
		REPU(i, 0, f['R']) ans += '3';
		f['T'] -= f['R'];
		f['H'] -= f['R'];
		f['E'] -= 2 * f['R'];
		f['R'] = 0;
		REPU(i, 0, f['X']) ans += '6';
		f['S'] -= f['X'];
		f['I'] -= f['X'];
		f['X'] = 0;
		REPU(i, 0, f['S']) ans += '7';
		f['E'] -= 2 * f['S'];
		f['V'] -= f['S'];
		f['N'] -= f['S'];
		f['S'] = 0;
		REPU(i, 0, f['G']) ans += '8';
		f['E'] -= f['G'];
		f['I'] -= f['G'];
		f['H'] -= f['G'];
		f['T'] -= f['G'];
		f['G'] = 0;
		REPU(i, 0, f['F']) ans += '5';
		f['I'] -= f['F'];
		f['V'] -= f['F'];
		f['E'] -= f['F'];
		f['F'] = 0;
		REPU(i, 0, f['O']) ans += '1';
		f['N'] -= f['O'];
		f['E'] -= f['O'];
		f['O'] = 0;
		REPU(i, 0, f['I']) ans += '9';
		sort(ALL(ans));
		printf("Case #%d: %s\n", it, ans.c_str());
	}
	
	return 0;
}
