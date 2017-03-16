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
#define EACH(it,A) for(auto it=A.begin();it<A.end();it++)

void do_case(int case_number) {
    int S; cin >> S;
    string _A; cin >> _A;
    auto myC2I = [](char c)->int{return c-'0';};
    vector<int> A(S+1); transform(ALL(_A),A.begin(),myC2I);
    FOR(i,1,S+1) A[i] += A[i-1];
    FOR(i,0,S+1) A[i] = i+1 - A[i];
    auto res = max(0,*max_element(ALL(A)));
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
