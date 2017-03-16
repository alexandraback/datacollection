#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cmath>
#include <string>
#include <cstring>
#include <cstdio>
#include <cassert>
using namespace std;

void openFiles() {
#ifndef ONLINE_JUDGE
    //freopen("test.in", "rt", stdin);
    freopen("B-small-attempt0.in", "rt", stdin);
    freopen("B-small-attempt0.out", "wt", stdout);
    //freopen("B-large.in", "rt", stdin);
    //freopen("test.out", "wt", stdout);
#endif
}

char buffer[10] = {0};
int mx = 0;
int recur(int n, int iter, const string& dict, const string& word) {
    if (iter == n) {
        int r = 0;
        for (int i = 0; i <= n - word.size(); i++) {
            bool ok = true;
            for (int j = 0; j < word.size() && ok; j++) {
                if (word[j] != buffer[i + j]) ok = false;
            }
            if (ok) r++;
        }
        mx = max(mx, r);
        return r;
    } else {
        int o = 0;
        for (int i = 0; i < dict.size(); i++) {
            buffer[iter] = dict[i];
            o += recur(n, iter + 1, dict, word);
        }
        return o;
    }
}

void solve() {
	int k, l, s; scanf("%d %d %d ", &k, &l, &s);
    string keyboard, word;
    cin >> keyboard;
    cin >> word;
    mx = 0; 
    double r = recur(s, 0, keyboard, word);
    for (int i = 0; i < s; i++) {
        r /= keyboard.size();
    }
    printf("%.8lf\n", mx - r);
}

int main() {
    openFiles();
    int n; scanf("%d ", &n);
    for (int i = 0; i < n; i++) {
        printf("Case #%d: ", i + 1);
        solve();
    }
    return 0;
}
