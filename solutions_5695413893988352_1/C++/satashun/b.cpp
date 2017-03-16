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
int l;
string s, t;
ll ret, p, q;

inline void upd_answer(ll df, ll u, ll v)
{
    df = abs(df);
    if (ret < df) return;

    if (ret > df) {
	ret = df, p = u, q = v;
	return;
    }

    if (u < p) {
	p = u, q = v;
	return;
    }

    if (v < q) {
	q = v;
    }
}

void search(int i, ll df, ll u, ll v)
{
    if (i == l) {
	upd_answer(df, u, v);
	return;
    }

    bool f1 = s[i] == '?', f2 = t[i] == '?';
    int n1 = s[i] - '0', n2 = t[i] - '0';

    if (!f1 && !f2) {
	search(i + 1, df * 10 + n1 - n2, u * 10 + n1, v * 10 + n2);
	return;
    }

    if (!f2) { //decide s[i]
	if (df > 0) {
	    search(i + 1, df * 10 + 0 - n2, u * 10,     v * 10 + n2);
	    return;
	}

	if (df < 0) {
	    search(i + 1, df * 10 + 9 - n2, u * 10 + 9, v * 10 + n2);
	    return;	    
	}

	//df = 0;
	//
	if (n2 - 1 >= 0) {
	    search(i + 1, df * 10 - 1, u * 10 + n2 - 1, v * 10 + n2);
	}

	if (n2 + 1 < 10) {
	    search(i + 1, df * 10 + 1, u * 10 + n2 + 1, v * 10 + n2);
	}

	search(i + 1, df * 10, u * 10 + n2, v * 10 + n2); //n2, n2
	return;

    } else if (!f1) { //decide t[i]

	if (df > 0) {
	    search(i + 1, df * 10 + n1 - 9, u * 10 + n1, v * 10 + 9);
	    return;
	}

	if (df < 0) {
	    search(i + 1, df * 10 + n1 - 0, u * 10 + n1, v * 10 + 0);
	    return;	    
	}

	//df = 0;
	//
	if (n1 - 1 >= 0) {
	    search(i + 1, df * 10 + 1, u * 10 + n1, v * 10 + n1 - 1);
	}

	if (n1 + 1 < 10) {
	    search(i + 1, df * 10 - 1, u * 10 + n1, v * 10 + n1 + 1);
	}

	search(i + 1, df * 10, u * 10 + n1, v * 10 + n1); //n1, n1
	return;
    } else {

	if (df > 0) {
	    search(i + 1, df * 10 - 9, u * 10 + 0, v * 10 + 9);
	    return;
	}

	if (df < 0) {
	    search(i + 1, df * 10 + 9, u * 10 + 9, v * 10 + 0);
	    return;	    
	}

	search(i + 1, df * 10 + 1, u * 10 + 1, v * 10 + 0);
	search(i + 1, df * 10 - 1, u * 10 + 0, v * 10 + 1);
	search(i + 1, df * 10, u * 10 + 0, v * 10 + 0);
    }
}

int main() {
    scanf("%d", &TC);

    for (int tc = 1; tc <= TC; ++tc) {
	printf("Case #%d: ", tc);

	cin >> s >> t;
	l = s.size();

	ret = LLONG_MAX;
	search(0, 0LL, 0LL, 0LL);

	cout << setfill('0') << setw(l) << right << p;
	cout << " ";
	cout << setfill('0') << setw(l) << right << q;
	cout << endl;
    }

    return 0;
}
