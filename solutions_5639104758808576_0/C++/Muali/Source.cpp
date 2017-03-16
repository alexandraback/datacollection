#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <vector>
#include <cassert>
#include <sstream>
#include <set>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define mp make_pair


void solve()               
{
    int mx;
    cin >> mx;
    string s;
    cin >> s;
    int count = 0;
    int ans = 0;
    for (int i = 0; i < s.size(); ++i)
    {
        if (i > count)
        {
            ans += i - count;
            count = i;
        }
        count += s[i] - '0';
    }
    cout << ans;
}                                                 


int main() {
	ios_base::sync_with_stdio(false);
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i)
    {
        cout << "Case #" << i + 1 << ": ";
        solve();
        cout << endl;
    }
}