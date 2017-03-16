/*
 * Author: Václav Volhejn (IAmWave)
 */
#include <cstdlib>
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
    int cases;
    *in >> cases;
    rep(caseI, 0, cases) {
        *out << "Case #" << (caseI + 1) << ": ";

        int x, r, c;
        *in >> x >> r >> c;
        if(((r * c) % x) || (x > 6)) {
            *out << "RICHARD" << endl;
            continue;
        }
        int minSize = (x + 1) / 2;
        if((min(r, c) < minSize) || (max(r, c) < x)) {
            *out << "RICHARD" << endl;
            continue;
        }
        if(min(r, c) == minSize) {
            if((x == 4) || (x == 6)) {
                *out << "RICHARD" << endl;
                continue;
            }
        }
        *out << "GABRIEL" << endl;
    }
}

int main() {
    ostream *out;
    istream *in = new ifstream("D-small-attempt0.in");
    out = &cout;
    if (distribute) out = new ofstream("out.txt");
    solve(in, out);
    return 0;
}
