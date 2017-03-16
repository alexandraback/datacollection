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
#define MAXN 2000000

using namespace std;

typedef long long ll;

int test, n;
ll d[MAXN];

bool isc(char c) {
    if (c != 'a' && c != 'o' && c != 'u' && c != 'e' && c != 'i') {
        return true;
    } else {
        return false;
    }
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> test;
    forn (it, test) {
        string s;
        cin >> s >> n;
        s = "#" + s;
        d[0] = 0;
        int last = -1, spree = 0;
        for (int i = 1; i < s.size(); i++) {
            d[i] = d[i - 1];
            if (isc(s[i])) {
                spree++;
                if (spree >= n) {
                    last = i - n + 1;
                }
            } else {
                spree = 0;
            }
            if (last != -1) {
                d[i] += last;
            }
        }
        printf("Case #%d: ", it + 1);
        cout << d[s.size() - 1] << endl;
    }

    return 0;
}
