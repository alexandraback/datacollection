#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cassert>

#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>

using namespace std;

typedef long long int64;

int A, B, K;

inline int GetBit(const int mask, const int bit) {
    return (mask >> bit) & 1;
}

int main() {
    assert(freopen("input.txt", "r", stdin));
    assert(freopen("output.txt", "w", stdout));
    int testCount;
    cin >> testCount;
    for (int test = 1; test <= testCount; ++test) {
        cin >> A >> B >> K;
        K = min(min(A, B), K);
        int64 answer = 0;
        for (int aBit = 31; aBit >= 0; --aBit) {
            if (GetBit(A, aBit) == 0)
                continue;
            for (int bBit = 31; bBit >= 0; --bBit) {
                if (GetBit(B, bBit) == 0)
                    continue;
                for (int kBit = 31; kBit >= 0; --kBit) {
                    if (GetBit(K, kBit) == 0)
                        continue;
                    int64 now = 1;
                    for (int bit = 0; bit <= 31; ++bit) {
                        if (bit < kBit) {
                            if (bit < aBit && bit < bBit)
                                now *= 4;
                            else if (bit < aBit || bit < bBit)
                                now *= 2;
                        } else if (bit == kBit) {
                            int a = -1, b = -1;
                            if (bit == aBit)
                                a = 0;
                            if (bit > aBit)
                                a = GetBit(A, bit);
                            if (bit == bBit)
                                b = 0;
                            if (bit > bBit)
                                b = GetBit(B, bit);
                            if (a != -1 && b != -1) {
                                if ((a & b) != 0)
                                    now = 0;
                            } else if (a == -1 && b != -1) {
                                if (b == 0)
                                    now *= 2;
                            } else if (a != -1 && b == -1) {
                                if (a == 0)
                                    now *= 2;
                            } else if (a == -1 && b == -1) {
                                now *= 3;
                            }
                        } else if (bit > kBit) {
                            int a = -1, b = -1;
                            if (bit == aBit)
                                a = 0;
                            if (bit > aBit)
                                a = GetBit(A, bit);
                            if (bit == bBit)
                                b = 0;
                            if (bit > bBit)
                                b = GetBit(B, bit);
                            if (a != -1 && b != -1) {
                                if ((a & b) != GetBit(K, bit))
                                    now = 0;
                            } else if (a == -1 && b != -1) {
                                if (GetBit(K, bit) == 1) {
                                    if (b == 0)
                                        now = 0;
                                } else {
                                    if (b == 0)
                                        now *= 2;
                                }
                            } else if (a != -1 && b == -1) {
                                if (GetBit(K, bit) == 1) {
                                    if (a == 0)
                                        now = 0;
                                } else {
                                    if (a == 0)
                                        now *= 2;
                                }
                            } else if (a == -1 && b == -1) {
                                if (GetBit(K, bit) == 0)
                                    now *= 3;
                            }
                        }
                    }
                    answer += now;
                }
            }
        }
        cout << "Case #" << test << ": " << answer << "\n";
    }
    return 0;
}
