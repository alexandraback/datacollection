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
    int c, n, v;
    *in >> c >> n >> v;
    vector<int> input(n);
    rep(i, 0, n) *in >> input[i];

    rep(added, 0, min(6, v - n + 1)) {
        int to = 1;
        rep(i, 0, added) to *= v; // - n + 1 - i;

        rep(i, 0, to) {
            input.resize(n);
            int cur = i;
            bool ok = true;
            rep(i, 0, added) {
                int d = cur % v + 1;
                rep(j, 0, input.size()) if(d == input[j]) ok = false;
                input.push_back(d);
                cur /= v;
            }
            if(!ok) continue;
            bool dp[v + 1];
            rep(i, 0, v + 1) dp[i] = false;
            dp[0] = true;
            rep(i, 0, input.size()) per(j, 0, v + 1) if(dp[j] && (j + input[i]) <= v) dp[j + input[i]] = true;

            rep(i,0,v+1) if(!dp[i]) ok = false;
            if(ok){
                *out << added << endl;
                return;
            }
        }
    }
}

int main() {
    ostream *out;
    istream *in = new ifstream(distribute ? "/home/vaclav/Downloads/C-small-attempt0.in" : "in.txt");
    out = distribute ? (new ofstream("out.txt")) : &cout;
    int cases;
    *in >> cases;
    rep(caseI, 0, cases) {
        *out << "Case #" << (caseI + 1) << ": ";
        solve(in, out);
    }
    return 0;
}
