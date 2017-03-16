#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <limits>
#include <algorithm>
#include <ctime>
#include <cstring>

using namespace std;

int cs = 0;
string a, b;
int n;

string to_string(int a, int len) {
    char s[100];
    sprintf(s, "%d", a);
    string ans(s);
    int diff = len - ans.length();
    return string(diff, '0') + ans;
}

bool same(const string &a, const string &b) {
    for (int i = 0; i < a.length(); ++i) {
        if (a[i] != b[i] && a[i] != '?' && b[i] != '?') {
            return false;
        }
    }
    return true;
}

int main() {
    freopen("B-small-attempt1.in", "r", stdin);
    freopen("B-small-attempt1.out", "w", stdout);
    int t;
    cin>>t;
    while (t--) {
        cin>>a>>b;
        n = a.length();
        int m = 1;
        for (int i = 0; i < n; ++i)
            m *= 10;
        int res1 = 10000, res2 = 10000, mindis = 10000;
        for (int i = 0; i < m; ++i) {
            string ta = to_string(i, n);
            if (!same(ta, a))
                continue;
            for (int j = 0; j < m; ++j) {
                if (abs(i - j) > mindis) continue;
                string tb = to_string(j, n);
                //cout<<ta<<" "<<tb<<endl;
                if (same(tb, b)) {
                    if (abs(i - j) < mindis) {
                        mindis = abs(i - j);
                        res1 = i;
                        res2 = j;
                    } else if (abs(i - j) == mindis) {
                        if (i < res1 || (i == res1 && j < res2)) {
                            mindis = abs(i - j);
                            res1 = i;
                            res2 = j;
                        }
                    }
                }
            }
        }

        printf("Case #%d: ",++cs);
        cout<<to_string(res1, n)<<" "<<to_string(res2, n)<<endl;
    }
    return 0;
}
