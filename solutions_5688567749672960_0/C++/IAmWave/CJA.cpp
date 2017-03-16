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
    ll n;
    *in >> n;
    ll dp[n + 1];
    rep(i, 0, n + 1) dp[i] = n+1;
    dp[1] = 1;
    rep(i, 1, n) {
        dp[i + 1] = min(dp[i + 1], dp[i] + 1);
        ll x = i;
        ll next = 0;
        while(x) {
            next = next * 10 + x % 10;
            x /= 10;
        }
        if(next<=n){
            dp[next] = min(dp[next], dp[i] + 1);
        }
    }
    *out << dp[n] << endl;
}

int main() {
    ostream *out;
    istream *in = new ifstream(distribute ? "/home/vaclav/Downloads/A-small-attempt1.in" : "in.txt");
    out = distribute ? (new ofstream("out.txt")) : &cout;
    int cases;
    *in >> cases;
    rep(caseI, 0, cases) {
        *out << "Case #" << (caseI + 1) << ": ";
        solve(in, out);
    }
    return 0;
}
