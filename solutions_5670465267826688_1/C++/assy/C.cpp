#include <algorithm>
#include <iostream>
#include <cstdio>
#include <map>
#include <numeric>
#include <cmath>
#include <set>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <complex>
#include <string.h>
#include <unordered_set>
#include <unordered_map>
#include <iomanip>
using namespace std;

#define endl '\n'
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define uniq(v) (v).erase(unique((v).begin(), (v).end()), (v).end())

typedef long long ll;
typedef pair<int, int> P;
typedef unsigned int uint;
typedef unsigned long long ull;
struct pairhash {
public:
    template<typename T, typename U>
    size_t operator()(const pair<T, U> &x) const {
	size_t seed = hash<T>()(x.first);
	return hash<U>()(x.second) + 0x9e3779b9 + (seed<<6) + (seed>>2);
    }
};

const int inf = 1000000009;
const double eps = 1e-8;
const string yes = "YES", no = "NO";

char alpha[8] = {'1', 'i', 'j', 'k', '-', 'p', 'q', 'r'};
char ope[256][256];

char rev(char a) {
    switch(a) {
    case '1': return '-';
    case '-': return '1';
    case 'i': return 'p';
    case 'p': return 'i';
    case 'j': return 'q';
    case 'q': return 'j';
    case 'k': return 'r';
    case 'r': return 'k';
    }
    return '1';
}

char calc(char a, char b) {
    if (a == '1') return b;
    if (b == '1') return a;
    if (a == b) return '-';
    if (a == 'i') {
	if (b == 'j') return 'k';
	if (b == 'k') return 'q';
	return rev(calc(a, rev(b)));
    }
    if (a == 'j') {
	if (b == 'i') return 'r';
	if (b == 'k') return 'i';
	return rev(calc(a, rev(b)));
    }
    if (a == 'k') {
	if (b == 'i') return 'j';
	if (b == 'j') return 'p';
	return rev(calc(a, rev(b)));
    }
    return rev(calc(rev(a), b));
}

bool check1(vector<vector<char> >& memo, int len, ll x) {
    char all[4];
    all[0] = '1';
    all[1] = memo[0][len];
    all[2] = ope[memo[0][len]][memo[0][len]];
    all[3] = ope[all[2]][memo[0][len]];
    for (int i = 0; i < len; i++) {
	for (int p = 0; p < min(4LL, x); p++) {
	    if (ope[all[p]][memo[0][i]] == 'i') {
		for (int j = i; j <= len; j++) {
		    if (memo[i][j] == 'j' && ope[memo[j][len]][all[(x-1-p)%4]] == 'k')
			return true;
		}
	    }
	}
    }
    return false;
}

bool check2(vector<vector<char> >& memo, int len, ll x) {
    char all[4];
    all[0] = '1';
    all[1] = memo[0][len];
    all[2] = ope[memo[0][len]][memo[0][len]];
    all[3] = ope[all[2]][memo[0][len]];
    for (int i = 0; i <= len; i++) {
	for (int p = 0; p < min(4LL, x-1); p++) {
	    if (ope[all[p]][memo[0][i]] == 'i') {
		for (int j = 0; j <= len; j++) {
		    for (int q = 0; q < min(4LL, x-1-p); q++) {
			if (ope[ope[memo[i][len]][all[q]]][memo[0][j]] == 'j' && ope[memo[j][len]][all[(x-2-p-q)%4]] == 'k')
			    return true;
		    }
		}
	    }
	}
    }
    return false;
}

string solve() {
    ll l, x;
    cin >> l >> x;
    string s;
    cin >> s;
    
    int len = s.size();
    vector<vector<char> > memo(len+1, vector<char>(len+1));
    for (int i = 0; i <= len; i++) {
	char v = '1';
	memo[i][i] = '1';
	for (int j = i+1; j <= len; j++) {
	    v = ope[v][s[j-1]];
	    memo[i][j] = v;
	}
    }
    int n = x % 4;
    char last = '1';
    for (int i = 0; i < n; i++) last = ope[last][memo[0][len]];
    if (last != '-') return no;

    if (check1(memo, len, x)) return yes;
    
    return (x > 1 && check2(memo, len, x) ? yes : no);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(15);

    int t;
    cin >> t;

    for (int i = 0; i < 8; i++)
	for (int j = 0; j < 8; j++)
	    ope[alpha[i]][alpha[j]] = calc(alpha[i], alpha[j]);
    
    for (int i = 1; i <= t; i++) {
	cerr << i << endl;
	cout << "Case #" << i << ": " << solve() << endl;
    }
}
