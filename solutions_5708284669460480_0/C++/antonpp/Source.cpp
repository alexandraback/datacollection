#include <iostream>
#include <cstdio>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <cmath>
#include <stdlib.h>

using namespace std;

int k, l, s;
int maxans;
int avrans;
int ans;
string keyboard, target;

void g(const string& str) {
    if (str.length() == s) {
        int d = 0;
        ans++;
        for (int i = 0; i < s; ++i) {
            if (str.substr(i, target.length()) == target) {
                ++d;
            }
        }
        maxans = max(maxans, d);
        avrans += d;
        return;
    }
    for (int i = 0; i < keyboard.length(); ++i) {
        g(str + keyboard[i]);
    }
}

double f(int k, int l, int s) {
    maxans = 0;
    avrans = 0;
    ans = 0;
    g("");
    return (double) maxans - ((double) avrans / (double) ans);
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        
        cin >> k >> l >> s;
        
        cin >> keyboard >> target;
        printf("Case #%d: %.7lf\n", i, f(k, l, s));
    }
    return 0;
}
