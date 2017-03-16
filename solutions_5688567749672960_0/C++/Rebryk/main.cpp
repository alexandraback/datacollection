#include <iostream>
#include <stdio.h>
#include <vector>
#include <math.h>
#include <string>
#include <algorithm>
#include <string.h>
#include <stack>
#include <assert.h>
#include <cstdio>
#include <cstring>
#include <unordered_map>
#include <queue>

using namespace std;

int T;
int n;

long long get(long long x) {
    vector < int > a;
    while (x) {
        a.push_back(x % 10);
        x /= 10;
    }
    long long ans = 0;
    for (int i = 0; i < a.size(); ++i)
        ans = 10 * ans + a[i];
    return ans;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        cin >> n;
        unordered_map <long long, long long> d;
        d[1] = 1;
        queue <long long> q;
        q.push(1);
        while (q.size()) {
            long long x = q.front();
            long long _d = d[x];
            q.pop();
            if (x == n)
                break;
            if (d.count(x + 1) == 0) {
                d[x + 1] = _d + 1;
                q.push(x + 1);
            }
            long long y = get(x);
            if (d.count(y) == 0) {
                d[y] = _d + 1;
                q.push(y);
            }
        }
        cout << "Case #" << t << ": " << d[n] << endl;
    }
    return 0;
}