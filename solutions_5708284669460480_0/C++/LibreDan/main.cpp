#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define fs first
#define sc second
#define mp make_pair
#define eb emplace_back

#define next _next
#define prev _prev
#define hash _hash
#define rank _rank
#define all(s) s.begin(), s.end()

#ifdef DEBUG
#define dout(x) cerr << x
#else
#define dout(x)
#endif

typedef long long ll;
typedef long double ld;

const int INF = 1e9;
const ll lINF = 1e18;
const double EPS = 1e-12;

#define PROBLEM "C"

template <class T>
void mout(T b, T e) {
#ifdef DEBUG
    for (T i = b; i != e; i++) {
        cout << *i << ' ';
    }
    cout << endl;
#endif
}

const int N = 105;

string s, t;
double d[N][N][N];
int b[N][N];
map<char, double> p;
int k, l, n;
double ans = 0;
double mx_res = 0;

vector<int> pr_f(string s) {
	int n = (int) s.length();
	vector<int> pi (n);
	for (int i = 1; i < n; ++i) {
		int j = pi[i - 1];
		while (j > 0 && s[i] != s[j])
			j = pi[j - 1];
		if (s[i] == s[j])  ++j;
		pi[i] = j;
	}
	return pi;
}

int kmp(string s, string t) {
    string m = s + "#" + t;
    vector <int> pr = pr_f(m);
    int res =  0;
    for (auto j : pr) {
        if (j == s.length()) {
            ++res;
        }
    }
    return res;
}

void gen(int h = 0, string g = "", double pr = 1.0) {
//    cout << g << endl;
    if (h == n) {
        double res = kmp(t, g);
        mx_res = max(mx_res, res);
        ans += pr * res;
//        cout << res << endl;
        return;
    }
    for (auto i : p) {
        gen(h + 1, g + i.first, pr * i.second);
    }
}

int main()
{
#ifdef DEBUG
	assert(freopen(PROBLEM".in", "r", stdin) != NULL);
	assert(freopen(PROBLEM".out", "w", stdout));
#else
//	assert(freopen(PROBLEM".in", "r", stdin) != NULL);
//	assert(freopen(PROBLEM".out", "w", stdout));
#endif

    int ts;
    cin >> ts;
    for (int tt = 1; tt <= ts; ++tt) {
        scanf(" %d%d%d", &k, &l, &n);
        cin >> s >> t;
        p.clear();
        for (int i = 0; i < k; ++i) {
            p[s[i]] += 1;
        }
        for (auto & j : p) {
            j.second /= double(k);
        }
        mx_res = 0;
        ans = 0;
        gen();
        printf("Case #%d: %.10f\n", tt, mx_res - ans);
    }
	return 0;
}


