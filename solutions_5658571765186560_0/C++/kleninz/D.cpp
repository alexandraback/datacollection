#include <set>
#include <map>
#include <cmath>
#include <stack>
#include <queue>
#include <string>
#include <cstdio>
#include <vector>
#include <utility>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#define INF 2e9
#define pb push_back
#define mp make_pair
#define forn(i,n) for (int i = 0; i < n; i++)

using namespace std;

typedef long long ll;

bool solve(int x, int r, int c) {
    if ((r * c) % x) {
        return true;
    }
    if (x > 4) {
        return true;
    }
    if (x <= 2) {
        return false;
    }
    if (x == 3) {
        return min(r, c) == 1;
    }
    if (x == 4) {
        if (min(r,c) < 3) {
            return true;
        } else {
            return false;
        }
    }
}

int main()
{
    int tests;
    cin >> tests;
    forn (it, tests) {
        int x, r, c;
        cin >> x >> r >> c;
        cout << "Case #" << it + 1 << ": " << (solve(x, r, c) ? "RICHARD" : "GABRIEL") << endl;
    }
    return 0;
} 
