#include <iostream>
#include <cstdio>
#include <cassert>
#include <ctime>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <sstream>

using namespace std;

template <typename T> T sqr(T x) { return x * x; }
template <typename T> T abs(T x) { return x < 0? -x : x; }
template <typename T> T gcd(T a, T b) { return b? gcd(b, a % b) : a; }
#define foreach(a, b) for(typeof((b).begin()) a = (b).begin(); a != (b).end(); ++a)

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

int main(int argc, char **argv)
{
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        cout << "Case #" << t << ": ";
        ull p, q;
        string s;
        cin >> s;
        s[s.find('/')] = ' ';
        istringstream sin(s);
        sin >> p >> q;
        ull g = gcd(p, q);
        p /= g;
        q /= g;
        if ((q & (q - 1)) != 0) {
            cout << "impossible";
        } else {
            int ans = 0;
            while (q > p) {
                ans += 1;
                q /= 2;
            }
            cout << ans;
        }
        cout << endl;
    }
    fprintf(stderr, "Time execute: %.3lf sec\n", clock() / (double)CLOCKS_PER_SEC);
    return 0;
}
