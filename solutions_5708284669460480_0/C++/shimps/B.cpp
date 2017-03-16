#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cstdint>
#include <ctime>
#include <cmath>
#include <climits>
#include <cassert>

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <deque>
#include <set>
#include <map>
#include <bitset>
#include <tuple>
#include <iterator>
#include <functional>
#include <numeric>
#include <complex>
#include <utility>
#include <algorithm>
#include <stack>
#include <queue>
#include <list>
#include <regex>
using namespace std;

#include <gmpxx.h>

typedef long long ll;

#define FOR(i,a,b) for(auto i=(a);i<(b);i++)
#define FORE(i,a,b) for(auto i=(a);i<=(b);i++)
#define REVERSE(i,a,b) for(auto i=(a);i>=(b);i--)
#define REP(i,N) FOR(i,0,N)
#define ALL(A) A.begin(),A.end()
#define EACH(it,A) for(auto &it : A)

typedef map<char,double> prob_t;
typedef vector<int> mat_t;

prob_t build_prob(string &A) {
    prob_t P;
    EACH(c,A) P[c] = P[c] + 1;
    EACH(kv,P) kv.second /= A.size();
    return P;
}

mat_t build_mat(string &A) {
    mat_t K(A.size()+1,0);
    int cur = 0;
    FORE(i,2,A.size()) {
        while(cur && A[i-1] != A[cur]) cur = K[cur];
        if(A[i-1] == A[cur]) cur++;
        K[i] = cur;
    }
    return K;
}

long double dp[2][110][110]; // (chars entered, bananas earned, prefix matched)

void do_case(int case_number) {
    int K, L, S;
    cin >> K >> L >> S;
    string kb, wd;
    cin >> kb;
    cin >> wd;
    auto prob = build_prob(kb);
    //EACH(it,prob) cout << "(" << it.first << "," << it.second << ")" << ", "; cout << endl;
    auto mat = build_mat(wd);
    //FORE(i,1,L) cout << mat[i] << ", "; cout << endl;
    long double ma = 0;

    memset(dp,0,sizeof(dp));
    dp[0][0][0] = 1.0;
    int p = 0, q = 1;
    REP(it,S) {
        FOR(i,0,110) FOR(j,0,110) dp[q][i][j] = 0.0;
        FOR(i,0,110) FOR(j,0,L) {
            EACH(kv,prob) {
                char c = kv.first;
                double pr = kv.second;
                if(j == L-1 && wd[L-1] == c) {
                    if(dp[p][i][j]) ma = max(ma,(long double)i+1);
                    dp[q][i+1][mat[L]] += dp[p][i][j]*pr;
                } else {
                    int nj = j;
                    while(nj && c != wd[nj]) nj = mat[nj];
                    if(c == wd[nj]) nj++;
                    assert(nj != L);
                    dp[q][i][nj] += dp[p][i][j]*pr;
                }
            }
        }
        p=1-p;
        q=1-q;
    }
    long double res = 0;
    FOR(i,0,110) FOR(j,0,110) res += dp[p][i][j]*i;
    cout << "Case #" << case_number << ": " << fixed << setprecision(12) << ma-res << endl;
}

int main(int argc, char** argv) {
    if(argc > 1) {
        auto fname_in = string(argv[1]) + ".in";
        auto fname_out = string(argv[1]) + ".out";
        freopen(fname_in.c_str(), "r", stdin);
        freopen(fname_out.c_str(), "w", stdout);
    }
    int T, te = 1;
    cin >> T;
    while(T--) {
        do_case(te);
        te++;
    }
    return 0;
}
