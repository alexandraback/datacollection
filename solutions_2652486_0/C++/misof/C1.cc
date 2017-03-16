// another fine solution by misof
// #includes {{{
#include <algorithm>
#include <numeric>

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <stack>

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cassert>

#include <cmath>
#include <complex>
using namespace std;
// }}}

/////////////////// PRE-WRITTEN CODE FOLLOWS, LOOK DOWN FOR THE SOLUTION ////////////////////////////////

// pre-written code {{{
// }}}

/////////////////// CODE WRITTEN DURING THE COMPETITION FOLLOWS ////////////////////////////////

map< pair< vector<int>, int > , double > poc;

int main() {
    vector<int> A(3);
    for (A[0]=2; A[0]<=5; ++A[0])
    for (A[1]=2; A[1]<=5; ++A[1])
    for (A[2]=2; A[2]<=5; ++A[2]) {
        for (int s=0; s<8; ++s) {
            int p=1; for (int i=0; i<3; ++i) if (s & 1<<i) p*=A[i]; poc[ make_pair(A,p) ] += 1./8;
        }
    }
    int T; cin >> T;
    cout << "Case #1:" << endl;
    int R, N, M, K; cin >> R >> N >> M >> K;
    for (int r=0; r<R; ++r) {
        double best = -1;
        vector<int> ans;
        vector<int> products(K);
        for (int k=0; k<K; ++k) cin >> products[k];
        vector<int> A(3);
        for (A[0]=2; A[0]<=5; ++A[0])
        for (A[1]=2; A[1]<=5; ++A[1])
        for (A[2]=2; A[2]<=5; ++A[2]) {
            double like = 1;
            for (int k=0; k<K; ++k) like *= poc[ make_pair(A,products[k]) ];
            if (like > best) { best=like; ans=A; }
        }
        for (int a:ans) cout << a; cout << endl;
    }
}
// vim: fdm=marker:commentstring=\ \"\ %s:nowrap:autoread
