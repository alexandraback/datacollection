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

#define FOR(i,a,b) for(auto i=(a);i<(b);i++)
#define ALL(A) A.begin(),A.end()
#define EACH(it,A) for(auto const &it : A)

void do_case(int case_number) {
    int N; cin >> N;
    vector<int> A(N);
    FOR(i,0,N) cin >> A[i];
    int res = INT_MAX;
    FOR(max_pancakes,1,1001) {
        int time_taken = accumulate(ALL(A),0,
            [=](int x, int p) ->  int{return x + (p-1)/max_pancakes;});
        res = min(res,time_taken+max_pancakes);
    }
    cout << "Case #" << case_number << ": " << res << endl;
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
