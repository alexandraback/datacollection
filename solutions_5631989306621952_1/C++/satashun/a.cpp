#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef vector<int> vi;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define rep(i,n) rep2(i,0,n)
#define rep2(i,m,n) for(int i=m;i<(n);i++)
#define ALL(c) (c).begin(),(c).end()

int TC;
string s;

void hd(string &a, char c)
{
    string b;
    b.resize(a.size() + 1);

    b[0] = c;
    rep(i, a.size()) b[i + 1] = a[i];
    a = b;
}

int main() {
    scanf("%d", &TC);

    for (int tc = 1; tc <= TC; ++tc) {
	printf("Case #%d: ", tc);

	cin >> s;
	string t;

	rep(i, s.size()) {
	    if (i == 0) t.pb(s[i]);
	    else {
		if (s[i] > t[0]) {
		    hd(t, s[i]);
		} else if (s[i] < t[0]) {
		    t.pb(s[i]);
		} else {
		    bool f = true;
		    rep(j, t.size()) if (t[j] < s[i]) {
			hd(t, s[i]);
			f = false;
			break;
		    }
		    if (f) t.pb(s[i]);
		}
	    }
	}
	cout << t << endl;
    }

    return 0;
}
