#include <iostream>
#include <set>
#include <cstdio>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstdio>

#define maxn 3010
#define inf 1000000000

using namespace std;

 void solve() {
     string s;
     vector<char> input(256);
     cin >> s;
     for (auto &ch : s) {
        input[ch]++;
     }

     vector<string> words = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
     vector<int> ap(256, 0);
     for (int i = 0; i < 10; ++i) {
        for (auto &ch : words[i]) {
            ap[ch]++;
        }
     }
     vector<int> nr(10, 0);
     vector<char> key(10);
     for (int i = 0; i < 10; ++i) {
        int wh;
        for (wh = 0; wh < words.size(); ++wh) {
            if (key[wh])
                continue;

            vector<int> m(256, 0);
            for (auto &ch : words[wh]) {
                m[ch]++;
            }

            for (auto &ch : words[wh]) {
                if (m[ch] == ap[ch]) {
                    key[wh] = ch;
                    break;
                }
            }

            if (key[wh]) {
                nr[wh] = input[key[wh]] / m[key[wh]];

                for (auto &ch : words[wh]) {
                    ap[ch]--;
                    input[ch] -= nr[wh];
                }


                break;
            }
        }
     }

     for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < nr[i]; ++j) {
            cout << i;
        }
     }
 }

int main()
{
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
    int test;
    cin >> test;

    for (int k = 1; k <= test; ++k) {
        cout << "Case #" << k << ": ";
        solve();
        cout << "\n";
    }
}
