#include <cstdio>
#include <cmath>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <stack>
#include <map>
#include <queue>
#include <string>
#include <list>
#include <set>
#include <unordered_map>
#include <cstring>
#include <ctime>
#include <bitset>
#include <cassert>
using namespace std;

#define INF 2100000000

string a[15] = { "ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
//string a[15] = { "ONE", "THREE", "FIVE", "SEVEN", "NINE"};

int main() {
    freopen("/Users/tianyi/Desktop/input.txt", "r", stdin);
    freopen("/Users/tianyi/Desktop/output.txt", "w", stdout);
    int tc; scanf("%d", &tc);
    for (int tcn = 1; tcn <= tc; tcn++) {
        int cnt[30] = {0};
        int ans[15] = {0};
        string s; cin >> s;
        for (int i = 0; i < s.size(); i++) {
            cnt[s[i]-'A']++;
        }
        
//        for (int i = 0; i <= 25; i++) {
//            printf("%c - %d, ", 'A'+i, cnt[i]);
//        }
//        printf("\n");
        
        // Filter different digits
        // 0
        ans[0] += cnt[25];
        for (int i = 0; i < a[0].size(); i++) {
            cnt[a[0][i]-'A'] -= ans[0];
        }
        
        // 2
        ans[2] += cnt[22];
        for (int i = 0; i < a[2].size(); i++) {
            cnt[a[2][i]-'A'] -= ans[2];
        }
        
        // 4
        ans[4] += cnt[20];
        for (int i = 0; i < a[4].size(); i++) {
            cnt[a[4][i]-'A'] -= ans[4];
        }
        
        // 6
        ans[6] += cnt[23];
        for (int i = 0; i < a[6].size(); i++) {
            cnt[a[6][i]-'A'] -= ans[6];
        }
        
        // 8
        ans[8] += cnt[6];
        for (int i = 0; i < a[8].size(); i++) {
            cnt[a[8][i]-'A'] -= ans[8];
        }
        
        // 1
        ans[1] += cnt[14];
        for (int i = 0; i < a[1].size(); i++) {
            cnt[a[1][i]-'A'] -= ans[1];
        }
        
        // 3
        ans[3] += cnt[7];
        for (int i = 0; i < a[3].size(); i++) {
            cnt[a[3][i]-'A'] -= ans[3];
        }
        
        // 5
        ans[5] += cnt[5];
        for (int i = 0; i < a[5].size(); i++) {
            cnt[a[5][i]-'A'] -= ans[5];
        }
        
        // 7
        ans[7] += cnt[18];
        for (int i = 0; i < a[7].size(); i++) {
            cnt[a[7][i]-'A'] -= ans[7];
        }
        
        // 9
        ans[9] += cnt[8];
        for (int i = 0; i < a[9].size(); i++) {
            cnt[a[9][i]-'A'] -= ans[9];
        }
        
        
        // Print answer
        printf("Case #%d: ", tcn);
        for (int i = 0; i <= 9; i++) {
            for (int j = 0; j < ans[i]; j++) printf("%d", i);
        }
        printf("\n");
    }
    return 0;
}