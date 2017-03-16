#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <cctype>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <bitset>
#include <algorithm>
#include <numeric>
#include <complex>
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
#define fi first
#define se second
#define rep(i, n) for (int i = 0, _##i = (n); i < _##i; ++i)
 
string str;
int n;
 
bool iscons(char c) {
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') return 0;
    else return 1;
}
 
void nval() {
    long long ans = 0;
    int len = str.length();
    int lp = 0, rp = -1;
    int streak = 0, sta = 0, end = 0;
    while (lp < len) {
        while (streak < n) {
            rp++;
            if (rp == len) break;
            if (iscons(str[rp])) {
                streak++;
                end = rp;
            }
            else {
                streak = 0;
                end = rp;
            }
        }
        if (rp == len) break;
        ans += (len - rp);
        lp++;
        if (rp - lp < n-1) {
            streak--;
        }
    }
    cout << ans << "\n";
}
 
int main() {
  freopen("consonants.in","r",stdin); freopen("consonants.out","w",stdout);
    int t;
    cin >> t;
    rep(z, t) {
        cout << "Case #" << z+1 << ": ";
        // scan in data and call function        
        cin >> str >> n;
        nval();
    }
}