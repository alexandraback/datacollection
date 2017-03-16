//Author: Václav Volhejn (IAmWave)
#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <set>
#include <map>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
typedef long long ll;

const bool distribute = true;

void solve(istream *in, ostream *out) {
    int w, h, l;
    *in >> h >> w >> l;
    int res = 0;
    res += (h - 1) * (w / l);
    int best = 0;
    int cur = 0;
    for(int rem = w; rem >= l; rem -= l) {
        if(rem == l) best = max(best, cur + l);
        else {
            best = max(best, cur + l + 1);
        }
        cur++;
    }
    res += best;
    *out << res << endl;
}

int main() {
    ostream *out;
    istream *in = new ifstream(distribute ? "/home/vaclav/Downloads/A-large.in" : "in.txt");
    out = distribute ? (new ofstream("out.txt")) : &cout;
    int cases;
    *in >> cases;
    rep(caseI, 0, cases) {
        *out << "Case #" << (caseI + 1) << ": ";
        solve(in, out);
    }
    return 0;
}
