#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <ctime>
#include <utility>
using namespace std;

#define forn(i, n) for(int i = 0; i < n; i++)

bool isPalyndrome(long long x) {
    string s = "";
    while (x) {
        s += char('0' + (x % 10));
        x /= 10;
    }
    forn (i, s.length()) {
        if (s[i] != s[s.length() - 1 - i]) {
            return false;
        }
    }
    return true;
}


int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    long long x[39] = {1, 4, 9, 121, 484, 10201, 12321, 14641, 40804, 44944, 1002001, 1234321, 4008004, 100020001, 102030201, 104060401, 121242121, 123454321, 125686521, 400080004, 404090404, 10000200001, 10221412201, 12102420121, 12345654321, 40000800004, 1000002000001, 1002003002001, 1004006004001, 1020304030201, 1022325232201, 1024348434201, 1210024200121, 1212225222121, 1214428244121, 1232346432321, 1234567654321, 4000008000004, 4004009004004};
    int t;
    cin >> t;
    for (int test = 1; test <= t; test++) {
        long long a, b;
        int ans = 0;
        cin >> a >> b;
        forn (i, 39) {
            if (x[i] >= a  &&  x[i] <= b) {
                ans++;
            }
        }
        cout << "Case #" << test << ": " << ans << endl;
    }
	return 0;
}
