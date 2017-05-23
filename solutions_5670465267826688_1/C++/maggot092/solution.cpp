#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>

#define hmap unordered_map
#define hset unordered_set
#define ll long long
#define mkveci mkvec<int>
#define vpri vpr<int>
#define forn(i, n) for (int i = 0; i < (n); ++i)
#define ford(i, n) for (int i = (n) - 1; i >= 0; --i)

using namespace std;


template<class T>
istream& operator >> (istream& in, vector<T>& v) {
    for (size_t i = 0; i < v.size(); ++i) {
        in >> v[i];
    }
    return in;
}

template<class T>
ostream& operator << (ostream& out, const vector<T>& v) {
    for (size_t i = 0; i < v.size(); ++i) {
        out << v[i];
    }
    return out;
}

template<class T>
vector<T> mkvec(int n) {
    return vector<T>(n);
}

template<class T>
vector<vector<T> > mkvec(int n, int m) {
    return vector<vector<T> >(n, vector<T>(m));
}

template<class T>
vector<vector<vector<T> > > mkvec(int n, int m, int k) {
    return vector<vector<vector<T> > >(n, vector<vector<T> >(m, vector<T>(k)));
}

template<class T>
class vpr {
  public:
    vpr(const vector<T>& v, const string& sep)
        : vec1(v)
        , sep1(sep) {
    }

    const vector<T>& vec1;
    const string& sep1;

};

template<class T>
ostream& operator << (ostream& out, const vpr<T>& pr) {
    for (int i = 0; i < pr.vec1.size(); ++i) {
        if (i > 0) {
            out << pr.sep1;
        }
        out << pr.vec1[i];
    }
    return out;
}

void solve();

void runTests() {
    int t;
    cin >> t;
    forn(i, t) {
        cout << "Case #" << i+1 << ": ";
        solve();
        cout << endl;
    }
}

bool isNeg(char c) {
    return c == 'I' || c == 'J' || c == 'K' || c == '-';
}

char minu(char c) {
    if (c == 'i') {
        return 'I';
    }
    if (c == 'I') {
        return 'i';
    }
    if (c == 'j') {
        return 'J';
    }
    if (c == 'J') {
        return 'j';
    }
    if (c == 'k') {
        return 'K';
    }
    if (c == 'K') {
        return 'k';
    }
    if (c == '1') {
        return '-';
    }
    if (c == '-') {
        return '1';
    }
}

char prod(char a, char b) {
    bool neg = false;
    if (isNeg(a)) {
        a = minu(a);
        neg = !neg;
    }
    if (isNeg(b)) {
        b = minu(b);
        neg = !neg;
    }
    if (a == '1') {
        if (neg) {
            return minu(b);
        }
        return b;
    }
    if (b == '1') {
        if (neg) {
            return minu(a);
        }
        return a;
    }
    char res = '0';
    if (a == b) {
        res = '-';
    }
    if (a == 'i' && b == 'j') {
        res = 'k';
    }
    if (a == 'i' && b == 'k') {
        res = 'J';
    }
    if (a == 'j' && b == 'i') {
        res = 'K';
    }
    if (a == 'j' && b == 'k') {
        res = 'i';
    }
    if (a == 'k' && b == 'i') {
        res = 'j';
    }
    if (a == 'k' && b == 'j') {
        res = 'I';
    }
    if (neg) {
        res = minu(res);
    }
    return res;
}

char pow(char a, ll p) {
    if (p == 0) {
        return '1';
    }
    char res = pow(a, p/2);
    res = prod(res, res);
    if (p % 2) {
        res = prod(res, a);
    }
    return res;
}


void solve() {
    int n;
    ll x;
    cin >> n >> x;
    string s;
    cin >> s;
    char res = '1';
    forn(i, n) {
        res = prod(res, s[i]);
    }
    res = pow(res, x);
    if (res != '-') {
        cout << "NO";
        return;
    }
    int leni = 0;
    char ii = '1';
    forn(a, 4 * n) {
        ii = prod(ii, s[a % n]);
        if (ii == 'i') {
            leni = a + 1;
            break;
        }
    }
    if (leni == 0) {
        cout << "NO";
        return;
    }
    int lenk = 0;
    char kk = '1';
    ford(a, 4 * n) {
        kk = prod(s[a % n], kk);
        ++lenk;
        if (kk == 'k') {
            break;
        }
    }
    if (kk != 'k') {
        cout << "NO";
        return;
    }
    if (leni + lenk > n * x) {
        cout << "NO";
        return;
    }
    cout << "YES";
}

int main() {
    runTests();
    //sove();
    return 0;
}
