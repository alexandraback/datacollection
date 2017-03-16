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
    int n;
    *in >> n;
    vector<ll> angles;
    vector<ll> speeds;

    rep(i, 0, n) {
        int angle, x;
        ll s;
        *in >> angle >> x >> s;
        rep(i, 0, x) {
            angles.push_back(angle);
            speeds.push_back(s);
            s++;
        }
    }
    if(speeds[0] == speeds[1]) {
        *out << 0 << endl;
        return;
    }
    if(speeds[0] < speeds[1]) { //0 je vyssi - pomalejsi
        swap(speeds[0], speeds[1]);
        swap(angles[0], angles[1]);
    }
    ll time = speeds[0] * (360 - angles[0]);
    ll b = time / speeds[1] + angles[1];
    ll rot = b / 360ll;
    cout << rot << endl;
    if(rot < 2) *out << 0 << endl;
    else *out << 1 << endl;
}

int main() {
    ostream *out;
    istream *in = new ifstream(distribute ? "/home/vaclav/Downloads/C-small-1-attempt1.in" : "in.txt");
    out = distribute ? (new ofstream("out.txt")) : &cout;
    int cases;
    *in >> cases;
    rep(caseI, 0, cases) {
        *out << "Case #" << (caseI + 1) << ": ";
        solve(in, out);
    }
    return 0;
}
