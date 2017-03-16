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

const bool distribute = false;

void solve(istream *in) {
    ofstream out("out.txt");
    int cases;
    *in >> cases;
    rep(i, 0, cases) {
        out << "Case #" << (i + 1) << ": ";

        int n;
        string input;
        *in >> n >> input;
        int cur = 0;
        int added = 0;
        rep(i, 0, n+1) {
            if(cur < i) {
                added += i - cur;
                cur = i;
            }
            cur += (input[i]-'0');
        }
        out << added << endl;
    }
}

int main() {
    istream *in;
    in = &cin;
    if (!distribute) in = new ifstream("in.txt");
    solve(in);
    return 0;
}
