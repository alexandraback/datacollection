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
    ll c, n, v;
    *in >> c >> n >> v;
    vector<ll> input(n);
    rep(i, 0, n) *in >> input[i];
    sort(input.begin(), input.end());
    input.push_back(v + 1);
    ll block = 0;
    int x = 0;
    int res = 0;
    while(block < v) {
        while(block + 1 >= input[x]) {
            if(input[x] > block) { //presne
                block = (block + 1) * (c + 1) - 1;
                //cout << "a";
            } else {
                block = input[x] * c + block;
                //block = max(block, input[x] * c + (input[x] - 1));
            }
            //cout << block << " ";
            x++;
            if(block >= v) break;
        }

        if(block < v) {
            res++;
            block = (block + 1) * (c + 1) - 1;
        }
        //cout << block << endl;

    }
    *out << res << endl;
}

int main() {
    ostream *out;
    istream *in = new ifstream(distribute ? "/home/vaclav/Downloads/C-large.in" : "in.txt");
    out = distribute ? (new ofstream("out.txt")) : &cout;
    int cases;
    *in >> cases;
    rep(caseI, 0, cases) {
        *out << "Case #" << (caseI + 1) << ": ";
        solve(in, out);
    }
    return 0;
}
