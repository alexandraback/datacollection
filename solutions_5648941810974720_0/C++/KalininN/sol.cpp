#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair 
#define sz(x) ((int)(x).size ())
#define re return
#define pb push_back
#define y0 y123423
#define y1 y2345
#define j0 j234
#define j1 j345
#define all(x) (x).begin(), (x).end()
#define sqrt(x) sqrt (abs(x))
#define makeunique(x) sort (all (x)), (x).resize (unique (x) - (x).begin())

typedef pair <int, int> ii;
typedef vector <int> vi;
typedef vector <ii> vii;
typedef vector <vi> vvi;
typedef long long ll;
typedef unsigned long long ull;
typedef long long ll;
typedef unsigned int uint;
typedef vector <string> vs;
typedef long double ld;
typedef double D;

template <class T> T abs (T x) { re x > 0 ? x : -x; }
template <class T> T  gcd (T a, T b) { re a ? gcd (b % a, a) : b; } 
template <class T> int sgn (T x) { re x > 0 ? 1 : (x < 0 ? -1 : 0); }
template <class T> T sqr (T x) { re x * x; }

const ld pi  = acos ((ld)(-1.0));

int n;
int m;
int cnt[300];
int ans[20];
char s[5005];

void dec(string t, int x)
{
	for (auto c : t) cnt[c] -= x;
}

int main ()
{
	int NT;
	scanf("%d", &NT);
	for (int T = 0; T < NT; T++)
	{
		scanf("%s", &s);
		int len = strlen(s);
		for (int i = 'A'; i <= 'Z'; i++) cnt[i] = 0;
		for (int i = 0; i < len; i++) cnt[s[i]]++;
		ans[2] = cnt['W'];
		dec("TWO", ans[2]);
		ans[0] = cnt['Z'];
		dec("ZERO", ans[0]);
		ans[8] = cnt['G'];
		dec("EIGHT", ans[8]);
		ans[6] = cnt['X'];
		dec("SIX", ans[6]);
		ans[7] = cnt['S'];
		dec("SEVEN", ans[7]);
		//for (int i = 'A'; i <= 'Z'; i++) cout << (char)i << ' ' << cnt[i] << ' ';
		//cout << endl;
		ans[5] = cnt['V'];
		dec("FIVE", ans[5]);
		//for (int i = 'A'; i <= 'Z'; i++) cout << (char)i << ' ' << cnt[i] << ' ';
		//cout << endl;
		ans[9] = cnt['I'];
		dec("NINE", ans[9]);
		//for (int i = 'A'; i <= 'Z'; i++) cout << (char)i << ' ' << cnt[i] << ' ';
		//cout << endl;
		ans[4] = cnt['U'];
		dec("FOUR", ans[4]);
		ans[3] = cnt['R'];
		dec("THREE", ans[3]);
		ans[1] = cnt['O'];
		dec("ONE", ans[1]);
		string answer = "";
		for (int i =0; i <= 9; i++)
		{
			for (int k = 0; k < ans[i]; k++) answer += '0' + i;
		}
		printf("Case #%d: %s\n", T + 1, answer.c_str());
		fprintf(stderr, "%d / %d cases done!\n", T + 1, NT);
		//for (int i = 'A'; i <= 'Z'; i++) cout << (char)i << ' ' << cnt[i] << ' ';
		//cout << endl;
		for (int i = 'A'; i <= 'Z'; i++) assert(cnt[i] == 0);
	}
	
	return 0;
}
