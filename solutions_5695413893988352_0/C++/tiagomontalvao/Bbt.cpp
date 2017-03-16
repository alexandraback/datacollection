#include <bits/stdc++.h>
using namespace std;

#define INF 0X3F3F3F3F
#define INFL 0x3F3F3F3F3F3F3F3FLL
#define MOD 1000000007
#define st first
#define nd second
#define pb push_back
#define mp make_pair
#define sz(X) int((X).size())
#define all(X) (X).begin(), (X).end()
#define rall(X) (X).rbegin(), (X).rend()
#define pow2(X) ((X)*(X))

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;
typedef vector<ll> vll;
typedef pair<int,int> pii;
typedef vector<pii> vpii;

int mini = INF;
string ans1, ans2;

void bt(string& s, int i = 0) {
	if (i == sz(s)) {
		int a = 0;
		for (int i = 0; i < sz(s)/2; i++)
			a = 10*a + s[i]-'0';
		int b = 0;
		for (int i = 0; i < sz(s)/2; i++)
			b = 10*b + s[sz(s)/2+i]-'0';
		// cout << a << ' ' << b << endl;
		if (abs(a-b) < mini) {
			ans1 = s.substr(0,sz(s)/2);
			ans2 = s.substr(sz(s)/2,sz(s)/2);
			mini = abs(a-b);
		}
		return;
	}
	if (s[i] != '?') {
		bt(s, i+1);
		return;
	}
	for (int j = 0; j < 10; j++) {
		s[i] = '0' + j;
		bt(s, i+1);
		s[i] = '?';
	}
}

int main(int argc, char const *argv[]) {
	int n;
	scanf("%d", &n);
	for (int t = 1; t <= n; t++) {
		int maior = 0;
		string s1, s2;
		cin >> s1 >> s2;
		string s3 = s1 + s2;
		mini = INF;
		bt(s3);
		cout << "Case #" << t << ": ";
		cout << ans1 << ' ' << ans2 << endl;
		// cout << s1.substr(0, sz(s1)) << ' ' << s2.substr(0, sz(s2)-1) << endl;
	}
	return 0;
}