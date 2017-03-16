#include <cstdio>
#include <iostream>

#define mp make_pair
#define pb push_back

#define REP(i, n) for(int i = 0; i < (n); ++i)
#define REP2(i, s, n) for (int i = (s); i < (n); ++i)

#define ABS(x) ((x) > 0 ? (x) : (-(x)))

using namespace std;
typedef long long ll;

ll min_diff = -1;
string min_c;
string min_j;

ll eval(const string &X)
{
    ll s = 0;
    REP(i, X.length()) {
        s = s * 10 + (X[i]-'0');
    }
    return s;
}

void go(string& C, string &J, int curi, int curj, int n)
{
    if (curi == n && curj == n) {
        ll c = eval(C);
        ll j = eval(J);
        ll diff = ABS(c-j);
        if (min_diff == -1 || diff < min_diff) {
            min_diff = diff;
            min_c = C;
            min_j = J;
        }
    }
    if (curi < n) {
        if (C[curi] == '?') {
            REP(i, 10) {
                C[curi] = i +'0';
                go(C, J, curi+1, curj, n);
            }
            C[curi] = '?';
        }
        else {
            go(C, J, curi+1, curj, n);
        }    
    }

    if (curj < n) {
        if (J[curj] == '?') {
            REP(i, 10) {
                J[curj] = i +'0';
                go(C, J, curi, curj+1, n);
            }
            J[curj] = '?';
        }
        else {
            go(C, J, curi, curj+1, n);
        }
    }
}

void solve()
{
    string C, J;
    cin >> C >> J;

    int n = C.length();

    min_diff = -1;
    go(C, J, 0, 0, n);

    cout << min_c << " " << min_j << endl;
}

int main()
{
	int t;
	cin >> t;
	for(int i = 1; i <= t; ++i) {
		cout << "Case #" << i << ": ";
		solve();
	}

	return 0;
}
