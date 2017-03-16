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


const int MAXN = 55;

template <typename T>
string toStr(T x) {
    stringstream ss;
    ss << x;
    return ss.str();
}


int h, w;
LD D;
inline
bool isInt(double x) {
    if (x < 0) {
        x = -x;
    }
    return fabs(x - (int)(x + EPS)) < EPS;
}

inline
int getInt(double x) {
    int sign = x < 0 ? -1 : 1;
    if (x < 0) {
        x = -x;
    }
    int res = int(x + EPS / 2);
    return res * sign;
}

inline
int gcd(int a, int b) {
    while (b) {
        int t = a % b;
        a = b;
        b = t;
    }
    return a;
}

inline
pii getStd(const pii& v) {
    int d = gcd(v.first, v.second);
    if (d < 0) {
        d = -d;
    }
    return pii(v.first / d, v.second / d);
}

inline
bool isCorner(const pdd& point) {
    return isInt(point.first) && isInt(point.second);
}


inline
void xInverse(pdd& dir) {
    dir.first *= -1;
}

inline
void yInverse(pdd& dir) {
    dir.second *= -1;
}

inline
pdd operator+ (const pdd& lhs, const pdd& rhs) {
    return pdd(lhs.first + rhs.first, lhs.second + rhs.second);
}

inline
pdd operator- (const pdd& lhs, const pdd& rhs) {
    return pdd(lhs.first - rhs.first, lhs.second - rhs.second);
}

inline
pdd operator* (const pdd& lhs, LD scalar) {
    return pdd(lhs.first * scalar, lhs.second * scalar);
}


inline
LD innerProd(const pdd& lhs, const pdd& rhs) {
    return lhs.first * rhs.first + lhs.second * rhs.second;
}

inline
LD getNorm(const pdd& v) {
    LD lenSqr = innerProd(v, v);
    LD res = sqrt(lenSqr);
    return res;
}

template <typename T> 
inline
T sqr(T x) {
    return x * x;
}

inline
LD getDist(const pdd& lhs, const pdd& rhs) {
    return sqrt(sqr(lhs.first - rhs.first) + sqr(lhs.second - rhs.second));
}


inline
bool isPointOnSegment(const pdd& point, const pdd& A, const pdd& B) {
    return fabs(getDist(A, point) + getDist(point, B) - getDist(A, B)) < EPS;
}


struct Line {
    LD A, B, C;
    Line(){}
    Line(LD A, LD B, LD C) 
        : A(A)
        , B(B)
        , C(C)
    {}
};

inline
LD substitudeInLine(const pdd& point, const Line& line) {
    return line.A * point.first + line.B * point.second + line.C;
}

inline
LD isPointOnLine(const pdd& point, const Line& line) {
    LD val = substitudeInLine(point, line);
    return fabs(val) < EPS;
}

inline
Line getLine(const pdd& lhs, const pdd& rhs) {
    Line res;
    res.A = lhs.second - rhs.second;
    res.B = rhs.first - lhs.first;
    res.C = lhs.first * rhs.second - lhs.second * rhs.first;
    assert(isPointOnLine(lhs, res));
    assert(isPointOnLine(rhs, res));
    return res;
}

inline
LD getDet(LD a, LD b, LD c, LD d) {
    return a * d - b * c;
}

inline
bool intersect(const Line& first, const Line& second, pdd& intersection) {
    LD det = getDet(first.A, first.B, second.A, second.B);
    if (fabs(det) < EPS) {
        return false;
    }
    LD x = getDet(-first.C, first.B, -second.C, second.B) / det;
    LD y = getDet(first.A, -first.C, second.A, -second.C) / det;
    intersection = pdd(x, y);
    assert(isPointOnLine(intersection, first));
    assert(isPointOnLine(intersection, second));
    return true;
}

inline
LD getNextTime(const pdd& curPos, const pdd& curDirection) {
    pdd nextPoint = curPos + curDirection * 2.0 * EPS;
    int xCell = getInt(nextPoint.first);
    int yCell = getInt(nextPoint.second);
    vector<pdd> pointInClockwise;
    pointInClockwise.push_back(pdd(xCell, yCell));
    pointInClockwise.push_back(pdd(xCell, yCell + 1));
    pointInClockwise.push_back(pdd(xCell + 1, yCell + 1));
    pointInClockwise.push_back(pdd(xCell + 1, yCell));
    LD minTime = numeric_limits<LD>::max();
    Line curLine = getLine(curPos, curPos + curDirection);
    for (int i = 0; i < 4; ++i) {
        pdd A = pointInClockwise[i];
        pdd B = pointInClockwise[(i + 1) % 4];
        Line AB = getLine(A, B);
        pdd intersection;
        if (intersect(curLine, AB, intersection)) {
            if (isPointOnSegment(intersection, curPos, curPos + curDirection * MAXN)) {
                if (innerProd(intersection - curPos, curDirection) > -EPS) {
                    LD t = getDist(intersection, curPos) / getNorm(curDirection);
                    if (t > EPS) {
                        assert(t > 1000.0 * EPS);
                        minTime = min(minTime, t);
                    }
                }
            }
        }
    }
    assert(minTime != numeric_limits<LD>::max());
    return minTime;
}

inline
string solve() {
    cin >> h >> w >> D;
    vector<string> field(h);
    for (int i = 0; i < h; ++i) {
        cin >> field[i];
    }
    set<pii> directionsSet;
    for (int dx = -2.0 * D - EPS; dx <= 2.0 * D + EPS; ++dx) {
        for (int dy = -2.0 * D - EPS; dy <= 2.0 * D + EPS; ++dy) {
            if (dx == 0 && dy == 0 || sqr(dx) + sqr(dy) > sqr(D) + EPS) {
                continue;
            }
            pii v = getStd(pii(dx, dy));
            directionsSet.insert(v);
        }
    }
    vector<pii> directions(all(directionsSet));
    int xStart = -1, yStart = -1;
    for (int i = 0; i < h && xStart == -1; ++i) {
        for (int j = 0; j < w; ++j) {
            if (field[i][j] == 'X') {
                xStart = i;
                yStart = j;
                break;
            }
        }
    }
    assert(xStart != -1 && yStart != -1);
    pdd startPoint(1.0 * xStart + 0.5, 1.0 * yStart + 0.5);
    int res = 0;
    for (int dirID = 0; dirID < directions.size(); ++dirID) {
        pdd curDirection(directions[dirID].first, directions[dirID].second);
        pdd curPos = startPoint;
        LD remainLen = D;
        bool ok = false;
        /*if (dirID == 746) {
            cerr <<"it" << endl;
        }*/
        while (remainLen > -EPS) {
            LD nextTime = getNextTime(curPos, curDirection);
            pdd nextPos = curPos + curDirection * nextTime;
            if (isPointOnSegment(startPoint, curPos, nextPos) && remainLen < D - EPS) {
                LD toCenter = getDist(curPos, nextPos) / 2;
                if (toCenter < remainLen + EPS) {
                    ok = true;
                    break;
                }
            }
            LD len = getDist(curPos, nextPos);
            remainLen -= len;
            if (remainLen < -EPS) {
                break;
            }
            if (fabs(nextPos.first) < EPS ||
                fabs(nextPos.first - h) < EPS ||
                fabs(nextPos.second) < EPS ||
                fabs(nextPos.second - w) < EPS) {
                    break;
            }
            bool isXInt = isInt(nextPos.first);
            bool isYInt = isInt(nextPos.second);
            assert(isXInt || isYInt);
            int nextX = getInt(nextPos.first + 5.0 * EPS * curDirection.first);
            int anotherX = getInt(nextPos.first - 5.0 * EPS * curDirection.first);
            int nextY = getInt(nextPos.second + 5.0 * EPS * curDirection.second);
            int anotherY = getInt(nextPos.second - 5.0 * EPS * curDirection.second);
            if (field[nextX][nextY] != '#') {
                curPos = nextPos;
                continue;
            }
            if (!isCorner(nextPos)) {
                if (isXInt) {
                    xInverse(curDirection);
                }
                else {
                    yInverse(curDirection);
                }
                curPos = nextPos;
                continue;
            }
            bool needReflectY = (field[anotherX][nextY] == '#');
            bool needReflectX = (field[nextX][anotherY] == '#');
            if (!needReflectX && !needReflectY) {
                break;
            }
            if (needReflectX) {
                xInverse(curDirection);
            }
            if (needReflectY) {
                yInverse(curDirection);
            }
            curPos = nextPos;
        }
        /*if (ok) {
            cerr << directions[dirID].first << " " << directions[dirID].second << endl;
        }*/
        res += ok;
    }
    return toStr(res);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    double t = clock();
    int T;
    cin >> T;
    string endline;
    getline(cin, endline);
    for (int test = 1; test <= T; ++test) {
        string res = solve();
        fprintf(stdout, "Case #%d: %s\n", test, res.c_str());
        fprintf(stderr, "Case #%d: %s\n", test, res.c_str());
    }
    cerr << (clock() - t) / CLOCKS_PER_SEC << endl;
    return 0;
}