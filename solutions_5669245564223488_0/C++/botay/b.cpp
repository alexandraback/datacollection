#include <algorithm>
#include <iostream>
#include <sstream>
#include <utility>
#include <cstdio>
#include <vector>
#include <string>
#include <cmath>
#include <set>
#include <map>
#include <cassert>

using namespace std;

typedef unsigned int ui32;

const int INF = (int)1e+9;
const double EPS = (double)1e-9;
const int MOD = (int)1e+9 + 7;

bool IsDull(const string& s) {
    for (size_t i = 1; i < s.length(); ++i)
        if (s[i] != s[0])
            return false;
    return true;
}

bool IsValid(const string& s) {
    for (char c = 'a'; c <= 'z'; ++c) {
        size_t ps = s.find(c);
        size_t pf = s.rfind(c);
        if (ps != pf) {
            assert(ps != string::npos && pf != string::npos);
            for (size_t j = ps; j <= pf; ++j) {
                if (s[j] != s[ps])
                    return false;
            }
        }
    }
    return true;
}

long long Fact(int k) {
    long long ret = 1;
    while (k > 1) {
        ret = ret * k % MOD;
        k -= 1;
    }
    return ret;
}

string ToString(const vector<string>& data) {
    stringstream io;
    io << "[";
    for (size_t i = 0; i < data.size(); ++i) {
        if (i > 0)
            io << ", ";
        io << data[i];
    }
    io << "]";
    return io.str();
}

int Solve(int testId) {
    int N;
    cin >> N;
    vector<string> cars(N);
    for (int i = 0; i < N; ++i) {
        cin >> cars[i];
    }
    for (int i = 0; i < N; ++i) {
        if (!IsValid(cars[i])) {
            cerr << "Car " << cars[i] << " is invalid" << endl;
            return 0;
        }
    }

    long long res = 1;
    cerr << "Start: " << res << " " << ToString(cars) << endl;

    for (char c = 'a'; c <= 'z'; ++c) {
        size_t dull = 0;
        vector<string> p;
        vector<string> newCars;
        for (size_t j = 0; j < cars.size(); ++j) {
            if (cars[j].find(c) != string::npos) {
                if (IsDull(cars[j])) {
                    dull += 1;
                } else {
                    p.push_back(cars[j]);
                }
            } else {
                newCars.push_back(cars[j]);
            }
        }
        cars = newCars;

        if (p.size() + dull == 0)
            continue;

        if (p.size() > 2u) {
            cerr << "Go 0 on " << c << " " << ToString(p) << endl;
            return 0;
        } else
        if (p.size() == 2u) {
            if (*p[0].rbegin() == c && p[1][0] == c) {
                cars.push_back(p[0] + p[1]);
            } else
            if (*p[1].rbegin() == c && p[0][0] == c) {
                cars.push_back(p[1] + p[0]);
            } else {
                cerr << "Go 0 on " << c << " " << ToString(p) << endl;
                return 0;
            }
        } else
        if (p.size() == 1u) {
            if (dull != 0 && p[0][0] != c && *p[0].rbegin() != c) {
                cerr << "Go 0 on " << c << " " << ToString(p) << endl;
                return 0;
            }
            cars.push_back(p[0]);
        } else {
            cars.push_back(string(1u, c));
        }

        res = res * Fact(dull) % MOD;

        //cerr << res << " " << ToString(cars) << endl;
    }

    res = res * Fact(cars.size()) % MOD;

    return res;
}

int main() {
    int testCnt;
    cin >> testCnt;
    for (int testId = 1; testId <= testCnt; ++testId) {
        printf("Case #%d: %d\n", testId, Solve(testId));
    }
    return 0;
}

