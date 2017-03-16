//Author: Václav Volhejn (IAmWave)
#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <iomanip>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
typedef long long ll;

const bool distribute = true;

void solve(istream *in, ostream *out) {
    int k, l, s;
    *in >> k >> l >> s;
    string keys, target;
    *in >> keys >> target;
    int to = 1;
    rep(i, 0, s) to *= k;
    int sum = 0;
    int best = 0;
    rep(num, 0, to) {
        int x = num;
        string cur = "";
        rep(i, 0, s) {
            cur += keys[x % k];
            x /= k;
        }
        int occ = 0;
        rep(i, 0, s - l + 1) {
            bool ok = true;
            rep(j, 0, l) if(cur[j + i] != target[j]) ok = false;
            occ += ok;
        }
        sum += occ;
        best = max(best, occ);
    }
    double res = sum;
    res /= to;
    res = best - res;
    *out << res << endl;
}

int main() {
    ostream *out;
    istream *in = new ifstream(distribute ? "/home/vaclav/Downloads/B-small-attempt0.in" : "in.txt");
    out = distribute ? (new ofstream("out.txt")) : &cout;
    *out << setprecision(10);
    int cases;
    *in >> cases;
    rep(caseI, 0, cases) {
        *out << "Case #" << (caseI + 1) << ": ";
        solve(in, out);
    }
    return 0;
}
