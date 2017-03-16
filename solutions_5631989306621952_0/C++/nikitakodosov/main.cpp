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

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    for (int test = 0; test < n; test++) {
        string s;
        cin >> s;
        string ans = "";
        ans += s[0];
        for (int i = 1; i < s.size(); i++) {
            if (ans + s[i] > s[i] + ans) {
                ans = ans + s[i];
            }
            else {
                ans = s[i] + ans;
            }
        }
        cout << "Case #" << test + 1 << ": " << ans << endl;
    }
}























/*

*/












