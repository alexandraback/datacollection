#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/STACK:64000000")
#define _USE_MATH_DEFINES
#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <math.h>
#include <set>
#include <map>
#include <cassert>
#include <queue>
#include <deque>
#include <stack>
#include <sstream>
#include <cstring>
#include <string>
#include <functional>
#include <numeric>
#include <bitset>
#include <cassert>
#include <complex>

using namespace std;

#define MP make_pair
#define all(v) (v).begin(), (v).end()
#define debug(x) cerr << #x << ": " << x << endl;

const int INF = ((1 << 30) - 1);
const long long LLINF = (((1LL << 60) - 1LL));
const double EPS = 1e-9;
const double PI = 3.14159265358979323846;  

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef long double LD;
typedef pair<LD, LD> pdd;
typedef pair<ll, ll> pll;


template <typename T>
string toStr(T x) {
    stringstream ss;
    ss << x;
    return ss.str();
}

string strFromDouble(LD x) {
    char str[50];
    sprintf(str, "%0.18lf", x);
    return string(str);
}

int h, n, m;

bool in(int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < m;
}

string solve() {
    cin >> h >> n >> m;
    vector<vector<int> > ceilHeight(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> ceilHeight[i][j];
        }
    }
    vector<vector<int> > floorHeight(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> floorHeight[i][j];
        }
    }
    set<pair<LD, pii> > marks;
    map<pii, LD> dist;
    pii start(0, 0);
    dist[start] = 0;
    marks.insert(pair<LD, pii>(dist[start], start));
    while (!marks.empty()) {
        int x = marks.begin()->second.first;
        int y = marks.begin()->second.second;
        marks.erase(marks.begin());
        for (int dx = -1; dx <= 1; ++dx) {
            for (int dy = -1; dy <= 1; ++dy) {
                if (abs(dx) + abs(dy) == 1 && in(x + dx, y + dy)) {
                    // to small
                    if (ceilHeight[x + dx][y + dy] - floorHeight[x + dx][y + dy] < 50) {
                        continue;
                    }
                    // to small 
                    if (ceilHeight[x + dx][y + dy] - floorHeight[x][y] < 50) {
                        continue;
                    }
                    // can't go
                    if (ceilHeight[x][y] - floorHeight[x + dx][y + dy] < 50) {
                        continue;
                    }
                    /*if (x == 0 && y == 1 && x + dx == 0 && y + dy == 2) {
                        cerr << "it" << endl;
                    }*/
                    pii cur(x, y);
                    pii to(x + dx, y + dy);
                    LD curWaterLevel = h - dist[cur] * 10 - floorHeight[x][y];
                    LD maxWatelLevel = ceilHeight[x + dx][y + dy] - floorHeight[x][y] - 50;
                    LD candidateTime;
                    if (curWaterLevel < maxWatelLevel + EPS) {
                        LD spentTime = 0;
                        if (dist[cur] < EPS) {
                            spentTime = 0;
                        }
                        else {
                            if (curWaterLevel > 20 - EPS) {
                                spentTime = 1.0;
                            }
                            else {
                                spentTime = 10.0;
                            }
                        }
                        candidateTime = dist[cur] + spentTime;
                    }
                    else {
                        LD waitTime = (curWaterLevel - maxWatelLevel) / 10.0; // speed per second
                        LD spentTime = 0;
                        if (maxWatelLevel > 20 - EPS) {
                            spentTime = 1.0;
                        }
                        else {
                            //cerr << "drug" << endl;
                            spentTime = 10.0;
                        }
                        candidateTime = dist[cur] + waitTime + spentTime;
                    }
                    if (!dist.count(to) || dist[to] > candidateTime + EPS) {
                        marks.erase(pair<LD, pii>(dist[to], to));
                        dist[to] = candidateTime;
                        marks.insert(pair<LD, pii>(dist[to], to));
                    }
                }
            }
        }
    }
    pii target(n - 1, m - 1);
    assert(dist.count(target));
    LD res = dist[target];
    return strFromDouble(res);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int T;
    cin >> T;
    string endline;
    getline(cin, endline);
    for (int test = 1; test <= T; ++test) {
        string res = solve();
        fprintf(stdout, "Case #%d: %s\n", test, res.c_str());
        fprintf(stderr, "Case #%d: %s\n", test, res.c_str());
    }
    return 0;
}