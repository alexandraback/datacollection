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
#define REVERSE(i,a,b) for(auto i=(a);i>=(b);i--)
#define REP(i,N) FOR(i,0,N)
#define ALL(A) A.begin(),A.end()
#define EACH(it,A) for(auto const &it : A)

int res(int R, int C, int W) {
    if(W == 1) return R*C;
    if(W == C) return R + C-1;
    if(C < W+W) return R + W;
    if(C == W+W) return R+R+W-1;
    return res(R,C-W,W)+R;
}

void do_case(int case_number) {
    int R, C, W;
    cin >> R >> C >> W;
    cout << "Case #" << case_number << ": " << res(R,C,W) << endl;
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
