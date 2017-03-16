#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <deque>
#include <sstream>
#include <iomanip>
using namespace std;
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef pair <int, int> PII;

int Tc, x, r, c;

int main() {
    cin >> Tc;
    rep (ri, Tc) {
        printf("Case #%d: ", ri + 1);
        cin >> x >> r >> c;
        if (r > c) swap(r, c);
        bool flag = true;
        if (r * c % x) flag = false;
        if (x > max(r, c)) flag = false;
        if ((x + 1) / 2 > min(r, c)) {
            flag = false;
        } 
        if (x >= 7) flag = false;
        if (x == 4 && r == 2) {
            flag = false;
        }
        if (x == 6 && r == 3) {
            flag = false;
        }
        puts(flag ? "GABRIEL" : "RICHARD");
    }
}

