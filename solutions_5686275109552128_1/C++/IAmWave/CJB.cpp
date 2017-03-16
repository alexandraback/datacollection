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
        int n;
        *in >> n;
        int input[n];
        rep(i, 0, n) *in >> input[i];
        int largest = 0;
        rep(i, 0, n) largest = max(largest, input[i]);
        int best = 1000000;
        rep(top, 1, largest + 1) {
            int steps = 0;
            rep(i, 0, n) steps += (input[i] - 1) / top;
            best = min(best, steps + top);
        }
        *out << best << endl;
    }
}

int main() {
    ostream *out;
    istream *in = new ifstream("B-large.in");//ifstream("B-small-attempt0.in");
    out = &cout;
    if (distribute) out = new ofstream("out.txt");
    solve(in, out);
    return 0;
}
