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

using namespace std;

typedef long long ll;

int main()
{
    int tests;
    cin >> tests;
    forn (it, tests) {
        string s;
        int n;
        cin >> n >> s;
        int sum = 0;
        int ans = 0;
        for (int i = 0; i < s.size(); i++) {
            ans = max(i - sum, ans);
            sum += s[i] - '0';
        }
        cout << "Case #" << it + 1 << ": " << ans << endl;
    }

    return 0;
} 
