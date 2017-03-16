// CPPFLAGS=-std=gnu++11 -O3

#include <vector>
#include <set>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <queue>
#include <map>
#include <cmath>
#include <unordered_map>
#include <unordered_set>
#include <functional>
#include <cstdlib>
#include <string>
#include <cstdint>

#define D(x) 

using namespace std;

map<pair<int64_t,int64_t>, int64_t> memo;

int64_t solve(int64_t A, int64_t B, int64_t K, string indent) {
    D(cerr << indent << "solve(" << A << "," << B << "," << K << ")" << endl);
    if (A <= 0 || B <= 0 || K <= 0) {
        return 0;
    }

    auto p = make_pair(A,B);
    if (memo.find(p) != memo.end()) {
        return memo[p];
    }

    int64_t limit = max(max(A-1,B-1),K-1);
    int64_t max_bit = 1;
    while (limit >>= 1) {
        max_bit <<= 1;
    }
    int64_t block = max_bit;
    int64_t K_;
    if (K == max_bit<<1) {
        K_ = max_bit;
    } else {
        K_ = K & (max_bit - 1);
    }
    D(cerr << indent << "block=" << block << " max_bit=" << max_bit << " K_=" << K_ << endl);

    int64_t A1, A2, B1, B2;
    if (A >= block) {
        A1 = block;
        A2 = A-block;
    } else {
        A1 = A;
        A2 = 0;
    }
    if (B >= block) {
        B1 = block;
        B2 = B-block;
    } else {
        B1 = B;
        B2 = 0;
    }

    int64_t result = 0;
    if (K == K_) {
        result += solve(A1, B1, K_, indent+"\t");
        result += solve(A1, B2, K_, indent+"\t");
        result += solve(A2, B1, K_, indent+"\t");
    } else {
        result += A1*B1;
        result += A1*B2;
        result += A2*B1;
        result += solve(A2, B2, K_, indent+"\t");
    }

    
    D(cerr << indent << "solve(" << A << "," << B << "," << K << ")=" << result << endl);
    memo[p] = result;
    return result;
}

int main() {
    int numCases;
    cin >> numCases;

    for (int T = 1; T <= numCases; T++) {
        int64_t A, B, K;
        cin >> A >> B >> K;

        memo.clear();
        int64_t total = solve(A,B,K,"\t");

        cout << "Case #" << T << ": ";
        cout << total;
        cout << endl;
    }
}
