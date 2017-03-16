#include <iostream>
#include <cstdio>
#include <sstream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <cmath>
#include <ctime>
#include <utility>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>


using namespace std;

typedef long long LL;
template<class T> inline T Abs(const T& x) { return x < 0 ? -x : x; }
template<class T> inline T Sqr(const T& x) { return x * x; }


int mul[5][5] = {
{0, 0, 0, 0, 0},
{0, 1, 2, 3, 4},
{0, 2, -1, 4, -3},
{0, 3, -4, -1, 2},
{0, 4, 3, -2, -1}
};


inline int Mul(int x, int y) {
    int sign = 1;
    if ((x < 0) != (y < 0)) {
        sign = -1;
    }
    x = Abs(x);
    y = Abs(y);
    return sign * mul[x][y];
}


void Solution() {
    LL l, x;
    cin >> l >> x;
    string str;
    cin >> str;
    vector<int> v(l);
    for (int i = 0; i < l; ++i) {
        if (str[i] == 'i') {
            v[i] = 2;
        } else if (str[i] == 'j') {
            v[i] = 3;
        } else if (str[i] == 'k') {
            v[i] = 4;
        }
    }
    int total = 1;
    for (int i = 0; i < l; ++i) {
        total = Mul(total, v[i]);
    }
    int ttotal = 1;
    for (int i = 1; i <= x % 4; ++i) {
        ttotal = Mul(ttotal, total);
    }
    if (ttotal != -1) {
        cout << "NO" << endl;
        return;
    }

    LL leftMost = l * x;
    LL rightMost = -1;
    {
        int cur = 1;
        for (int i = 0; i < l; ++i) {
            cur = Mul(cur, v[i]);
            int ccur = cur;
            for (int j = 0; j < 10; ++j) {
                if (ccur == 2 && leftMost > i + j * l) {
                    leftMost = i + j * l;
                }
                ccur = Mul(total, ccur);
            }
        }
    }
    {
        int cur = 1;
        for (int i = 0; i < l; ++i) {
            cur = Mul(v[l - 1 - i], cur);
            int ccur = cur;
            for (int j = 0; j < 10; ++j) {
                if (ccur == 4 && rightMost < l * x - 1 - i - l * j) {
                    rightMost = l * x - 1 - i - l * j;
                }
                ccur = Mul(ccur, total);
            }
        }
    }
    if (leftMost < rightMost) {
        cout << "YES" << endl;
        return;
    }
    cout << "NO" << endl;
}


int main() {
    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        cout << "Case #" << i + 1 << ": ";
        Solution();
    }

    return 0;
}


