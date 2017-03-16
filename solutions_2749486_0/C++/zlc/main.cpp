//T-shirt is honor for programmers!
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <map>
#include <set>
#include <cmath>
#include <algorithm>
#include <sstream>
#define inf 1000000007
#define N 505
#define eps 1e-8
#define M 505
#define For(i,a,b) for(int i=(a);i<(b);i++)
#define Pi acos(-1.0)
using namespace std;

string calc(int x, int y, int z) {
    int op = z;
    string s = "";
    int c = 0;
    int t;
    for (int i = 1;; i++) {
        if (c == y) {
            return s;
        }
        if (x != i) {
            if (z > 0) {
                c += i;
                s += 'a';
            } else {
                c -= i;
                s += 'b';
            }
            z *= -1;
        } else {
            s += 'c';
            if (z > 0) {
                t = c + i;
            } else
                t = c - i;
            if (t == y)
                return "";
        }

    }
}

string work(int x, int y) {
    string s;
    s = "";
    int yy;
    if (x < 0)
        yy = -x;
    else
        yy = x;
    s = calc(yy, y, 1);
    if (s == "") {
        s = calc(yy, y, -1);
    }

    string ans = "";

    For(i, 0, s.size()) {
        if (s[i] == 'a') {
            ans += 'N';
        } else if (s[i] == 'b') {
            ans += 'S';
        } else {
            if (x > 0) {
                ans += 'E';
            } else if (x < 0) {
                ans += 'W';
            }
        }
    }
    return ans;
}

int main(int argc, char** argv) {
    int T;
    freopen("123.txt", "r", stdin);
     freopen("222.txt","w",stdout);
    scanf("%d", &T);
    int cs = 0;
    int x, y;
    while (T--) {
        cs++;
        cin >> x >> y;
        string ans = "";
        if (abs(x) > abs(y)) {
            ans = work(y, x);

            For(i, 0, ans.size()) {
                if (ans[i] == 'N') {
                    ans[i] = 'E';
                } else if (ans[i] == 'E') {
                    ans[i] = 'N';
                } else if (ans[i] == 'W') {
                    ans[i] = 'S';
                } else if (ans[i] == 'S') {
                    ans[i] = 'W';
                }
            }
        } else {
            ans = work(x, y);
        }
        cout << "Case #" << cs << ": " << ans << endl;
    }
    return 0;
}

