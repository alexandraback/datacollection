#include <algorithm>
#include <bitset>
#include <cassert>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

#define ALL(x) (x).begin(), (x).end()
#define EACH(itr,c) for(__typeof((c).begin()) itr=(c).begin(); itr!=(c).end(); itr++)  
#define FOR(i,b,e) for (int i=(int)(b); i<(int)(e); i++)
#define MP(x,y) make_pair(x,y)
#define REP(i,n) for(int i=0; i<(int)(n); i++)

int N;
double A[1000], B[1000];

void solve() {
    cin >> N;
    REP (i, N) cin >> A[i];
    REP (i, N) cin >> B[i];

    sort(A, A+N);
    sort(B, B+N);

    int p, q;
    p = q = 0;
    int ret = 0;
    while (p < N) {
        if (A[p] > B[q]) {
            ++ret;
            ++p;
            ++q;
        } else {
            ++p;
        }
    }
    cout << ret << " ";

    p = q = 0;
    ret = 0;
    while (q < N) {
        if (B[q] > A[p]) {
            ++ret;
            ++p;
            ++q;
        } else {
            ++q;
        }
    }
    cout << N-ret << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    
    int T;
    cin >> T;

    REP (i, T) {
        cerr << "Solving Case #" << (i+1) << "..." << endl;
        cout << "Case #" << (i+1) << ": "; 
        solve();
    }

    return 0;
}
