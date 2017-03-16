#include<iostream>
#include<stdio.h>
#include<vector>
#include<set>
#include<algorithm>
#include<deque>
#include<cmath>
#include<ctime>
#include<stack>

using namespace std;

int cnt[300];
int ans[10];

int main() {
    freopen("A-large (2).in", "r", stdin);
    freopen("output.txt", "w", stdout);
    int T;
    cin >> T;
    for (int t = 0; t < T; ++t) {
        cout << "Case #" << t + 1 << ": ";
        for (int i = 0; i < 300; ++i)
            cnt[i] = 0;
        for (int i = 0; i < 10; ++i)
            ans[i] = 0;
        string s;
        cin >> s;
        for (int i = 0; i < s.length(); ++i) {
           cnt[s[i]]++;
        }
        ans[0] = cnt['Z'];
        ans[2] = cnt['W'];
        ans[4] = cnt['U'];
        ans[6] = cnt['X'];
        ans[8] = cnt['G'];
        ans[3] = cnt['T'] - ans[2] - ans[8];
        ans[5] = cnt['F'] - ans[4];
        ans[7] = cnt['S'] - ans[6];
        ans[1] = cnt['O'] - ans[0] - ans[2] - ans[4];
        ans[9] = cnt['I'] - ans[5] - ans[6] - ans[8];
        for (int i = 0; i < 10; ++i)
            for (int j = 0; j < ans[i]; ++j) {
                cout << i;
            }
        cout << "\n";
    }
    return 0;
}