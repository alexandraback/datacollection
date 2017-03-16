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

char inv(char a) {
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
	return inv(calc(a, inv(b)));
    }
    if (a == 'j') {
	if (b == 'i') return 'r';
	if (b == 'k') return 'i';
	return inv(calc(a, inv(b)));
    }
    if (a == 'k') {
	if (b == 'i') return 'j';
	if (b == 'j') return 'p';
	return inv(calc(a, inv(b)));
    }
    return inv(calc(inv(a), b));
}

bool check(vector<vector<char> >& memo, int len) {
   for (int i = 1; i < len-1; i++) {
       if (memo[0][i] == 'i') {
	   for (int j = i+1; j < len; j++) {
	       if (memo[i][j] == 'j' && memo[j][len] == 'k')
		   return true;
	   }
       }
   }
   return false;
}

string solve() {
    int l, x;
    cin >> l >> x;
    string s;
    cin >> s;
    stringstream ss;
    for (int i = 0; i < x; i++)
	ss << s;
    s = ss.str();
    int len = s.size();
    vector<vector<char> > memo(len+1, vector<char>(len+1));
    //char memo[len+1][len+1];
    for (int i = 0; i < len; i++) {
	char v = '1';
	for (int j = i+1; j <= len; j++) {
	    v = calc(v, s[j-1]);
	    memo[i][j] = v;	    
	}
    }
    return (check(memo, len) ? yes : no);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(15);

    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
	cout << "Case #" << i << ": " << solve() << endl;
    }
}
