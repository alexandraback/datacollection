
// compile this with a compiler supporting C++11
// link also the gmp library using the linker flags -lgmp -lgmpxx

//#define USE_DEBUG
#define USE_BIGINT

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <cstdio>
#include <algorithm>
#include <numeric>
#include <cassert>
#include <random>
#include <cstdint>
#include <sstream>
#ifdef USE_BIGINT
  #include <gmpxx.h>
#endif

using namespace std;

#ifdef USE_DEBUG
  #define DBG
#else
  #define DBG if (0)
#endif

#ifdef USE_BIGINT
//typedef long long int int64;
//typedef long int64;
typedef mpz_class BigInt;
//typedef uint64_t BigInt;
#endif

int B;
BigInt M;
#define BRIDGE(i, j)        (bridges[(i) * B + (j)])

int countWays(const vector<int> &bridges) {
    queue<int> Q;
    Q.push(0);
    int count = 0;
    while (!Q.empty()) {
        int cur = Q.front();
        if (cur == B-1)
            ++count;
        for (int i = 0; i < B; ++i) {
            if (BRIDGE(cur, i))
                Q.push(i);
        }
        Q.pop();
    }
    return count;
}

int main(int argc, char **argv) {
    //cout.unsetf(ios::floatfield);
    cout.precision(10);

#if 1
    #define IN cin
#else
    ifstream IN("A-small-practice.in");
    if (!IN) {
        cerr << "Can't open input file\n";
        exit(1);
    }
#endif

    int T;
    IN >> T;
    for (int tc = 0; tc < T; ++tc) {
        IN >> B >> M;
        cerr << "B = " << B << ", M = " << M << "\n";

        vector<int> bridges(B * B);
        bridges.assign(B * B, 0);

        bool possible = false;
        BigInt curCount = 0;

        BRIDGE(0, B-1) = 1;
        curCount = 1;

        bool found = true;
        while (curCount < M && found == true) {
            found = false;
            /*queue<int> Q;
            Q.push(0);
            while (!Q.empty()) {
                int cur = Q.front();
                if (BRIDGE(cur, B-1) == 0) {
                    BRIDGE(cur, B-1) = 1;
                    --needed;
                } else {

                }
                if (cur == B-1)
                    ++count;
                for (int i = 0; i < B; ++i) {
                    if (BRIDGE(cur, i))
                        Q.push(i);
                }
                Q.pop();
            }
            return count;*/

            DBG { cerr << "Before:\n";
            for (int i = 0; i < B; ++i) {
                for (int j = 0; j < B; ++j) {
                    if (j > 0)
                        cout << " ";
                    cout << BRIDGE(i, j);
                }
                cout << std::endl;
            } }

            /*queue<int> Q;
            Q.push(0);
            while (!Q.empty()) {
                int cur = Q.front();
                if (BRIDGE(cur, B-1) == 0) {

                } else {
                    bool found2 = false;
                    for (int i = cur+1; i < B-1; ++i) {
                        if (BRIDGE(cur, i) == 0) {
                            BRIDGE(cur, i) = 1;
                        }
                    }
                }
            }*/

            for (int i = 0; i < B-1; ++i) {
                if (BRIDGE(i, B-1) == 0) {
                    BRIDGE(0, i) = 1;
                    DBG { cerr << "B -> " << 0 << ", " << i << "\n"; }
                    BRIDGE(i, B-1) = 1;
                    DBG { cerr << "B -> " << i << ", " << B-1 << "\n"; }
                    found = true;
                    ++curCount;
                    break;
                }
            }
            if (found == false) {
                //for (int i = 0; i < B-1; ++i) {
                //    for (int j = i+1; j < B; ++j) {
                for (int j = B-1; j >= 1; --j) {
                    for (int i = j-1; i >= 0; --i) {
                        if (BRIDGE(i, j) == 0) {
                            BRIDGE(i, j) = 1;
                            DBG { cerr << "B -> " << i << ", " << j << "\n"; }


/*#if 1
                            int count = countWays(bridges);
                            if (count != M-needed) {
                                cerr << "ERROR! count = " << count << ", count2 = " << M-needed << "\n";
                                //exit(1);
                                BRIDGE(i, j) = 0;
                            } else
#endif
                            {
                                found = true;
                                --needed;
                                break;
                            }*/

                            int count = countWays(bridges);
                            curCount = count;
                            found = true;
                            break;
                        }
                    }
                    if (found)
                        break;
                }
            }

            DBG { cerr << "After:\n";
            for (int i = 0; i < B; ++i) {
                for (int j = 0; j < B; ++j) {
                    if (j > 0)
                        cerr << " ";
                    cerr << BRIDGE(i, j);
                }
                cerr << std::endl;
            } }
        }
        if (curCount == M) {
            possible = true;
        }

        cout << "Case #" << (tc + 1) << ": ";
        if (possible) {
            cout << "POSSIBLE\n";
            for (int i = 0; i < B; ++i) {
                for (int j = 0; j < B; ++j) {
                    if (j > 0)
                        cout << " ";
                    cout << BRIDGE(i, j);
                }
                cout << std::endl;
            }
        } else {
            cout << "IMPOSSIBLE\n";
        }
    }
    return 0;
}

