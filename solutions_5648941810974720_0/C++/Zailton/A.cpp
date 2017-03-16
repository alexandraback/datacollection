#include <bits/stdc++.h>

using namespace std;

#define FOR(i,a,b) for(int i = a; i < b; i++)
#define FORR(i,b) FOR(i, 0, b)
#define sz(e) (int)e.size()
#define CLR(x,v) memset (x, v, sizeof x)
#define pb push_back
#define all(e) e.begin(), e.end()

typedef long long ll;
typedef pair<int, int> ii;

const int MAXN = 2000006;
const int INF = 1000000000;

int f[30], aux[30];

string digits[] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
//02

char v1[] = {'Z', 'W' ,'U', 'F', 'V', 'X', 'O', 'R', 'T', 'E'};
char v2[] = {'0', '2', '4', '5', '7', '6', '1', '3', '8', '9'};

string solve () {
	string res = "";
	FORR (i, 10) {
		while (f[v1[i]-'A']>0) {
			FORR (j, sz(digits[v2[i]-'0'])) f[digits[v2[i]-'0'][j]-'A']--;
			//cout << f[v1[i]] << " " << v1[i] << "  "<< (v2[i]-'0') << endl;
			res += v2[i];
		}
	}
	sort (all(res));
	FORR (i, 30) if (f[i]) cout << "merda" << endl;
	return res;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
	int T;
	cin>>T;
	FORR (c, T) {
		cout << "Case #" << c+1 << ": ";
		string s; cin>>s;
		CLR (f, 0);
		FORR (i, sz(s)) f[s[i]-'A']++;
		cout << solve () << endl;
	}
    
}
