#include <iostream>
#include <cstdio>
#include <iomanip>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>

typedef long long int ll;
const int MAXN = 100003;

using namespace std;

string digits[10] = {
        "ZERO",
        "ONE",
        "TWO",
        "THREE",
        "FOUR",
        "FIVE",
        "SIX",
        "SEVEN",
        "EIGHT",
        "NINE"
};
int order[10] = {0, 2, 6, 7, 8, 5, 4, 1, 3, 9};
int a[30];
int cnt[10];
bool visited[3000];
int ans[10];

int main() {
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("output.txt", "w", stdout);
    string s;
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        cin >> s;
        for (int i = 0; i < 10; ++i) ans[i] = 0;
        for (int i = 0; i < 30; ++i) a[i] = 0;
        for(int i = 0; i < (int)s.size(); ++i)
            a[(int)s[i] - (int)'A'] += 1;
        for (int i = 0; i < 10; ++i) {
            string cur = digits[order[i]];
            for (int j = 0; j < (int)cur.size(); ++j) {
                cnt[j] = a[cur[j] - 'A'];
            }
            int minx = 3000;
            for (int j = 0; j < (int)cur.size(); ++j)
                if (cnt[j] < minx)
                    minx = cnt[j];
            for (int j = 0; j < (int)cur.size(); ++j)
                a[cur[j] - 'A'] -= minx;
            ans[order[i]] += minx;
        }
        string res = "";
        for (int i =0; i < 10; ++i) {
            while (ans[i]) {
                --ans[i];
                res += (char)(i + '0');
            }
        }
        cout << "Case #" << t << ": " << res << '\n';
    }
    return 0;
}