#define _CRT_SECURE_NO_WARNINGS

#pragma comment(linker, "/STACK:16777216")
#include <cmath>
#include <math.h>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <iostream>
#include <queue>
#include <string>
#include <sstream>
#include <time.h>
#include <iomanip>
#include <cstdio>

using namespace std;


vector<int> solve(vector<vector<int>> &a, int n) {
    vector<int> r(3000, 0);
    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < a[i].size(); j++) r[a[i][j]]++;
    }
    vector<int> ans;
    for (int i = 0; i < 3000; i++) {
        if (r[i] % 2 == 1) ans.push_back(i);
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int tests;
    cin >> tests;
    for (int test = 0; test < tests; test++) {
        int n;
        cin >> n;
        vector<vector<int>> a;
        a.resize(n * 2 - 1);
        for (int i = 0; i < n * 2 - 1; i++) {
            for (int j = 0; j < n; j++) {
                int x;
                cin >> x;
                a[i].push_back(x);
            }
        }
        vector<int> ans = solve(a, n);
        cout << "Case #" << test + 1 << ": ";
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
}























/*

*/












