#include <iostream>
#include <map>
#include <vector>
#include <cstdio>
#include <set>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;

void kaka(string word, vector<int>& count) {
    for(int i = 0; i < word.size(); i++)
        count[word[i] - 'A']--;
}

void sol(vector<int>& count, char target, string word, vector<int>& ans, int x) {
    while(count[target - 'A'] > 0) {
        ans.push_back(x);
        kaka(string(word), count);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    string line;
    int t;
    cin >> t;
    for(int cas = 1; cas <= t; cas++) {
        cin >> line;
        vector<int> count(26, 0);
        for(int i = 0; i < line.size(); i++) {
            count[line[i] - 'A']++;
        }
        vector<int> ans;
        sol(count, 'Z', string("ZERO"), ans, 0);
        sol(count, 'W', "TWO", ans, 2);
        sol(count, 'X', "SIX", ans, 6);
        sol(count, 'S', "SEVEN", ans, 7);
        sol(count, 'V', "FIVE", ans, 5);
        sol(count, 'G', "EIGHT", ans, 8);
        sol(count, 'H', "THREE", ans, 3);
        sol(count, 'F', "FOUR", ans, 4);
        sol(count, 'O', "ONE", ans, 1);
        sol(count, 'N', "NINE", ans, 9);

        sort(ans.begin(), ans.end());
        cout << "Case #" << cas << ": ";
        for(int i = 0; i < ans.size(); i++)
            cout << ans[i];
        cout << "\n";
    }
}
