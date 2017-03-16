#include <bits/stdc++.h>

using namespace std;

const int A = 200, N = 2005;
const string digits[] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
const char letters[] = {'X', 'S', 'V', 'Z', 'F', 'W', 'G', 'O', 'H', 'N'};
const int dig[] = {6, 7, 5, 0, 4, 2, 8, 1, 3, 9};

int cnt[A];
char word[N];

void test() {
    for (int i = 'A'; i <= 'Z'; i++) {
        cnt[i] = 0;
    }
    scanf("%s", &word[1]);
    int l = strlen(word + 1);
    for (int i = 1; i <= l; i++) {
        cnt[word[i]]++;
    }

    vector<int> ans;
    for (int i = 0; i < 10; i++) {
        while (cnt[letters[i]] > 0) {
            ans.push_back(dig[i]);
            for (int j = 0; j < digits[dig[i]].length(); j++) {
                cnt[digits[dig[i]][j]]--;
            }
        }
    }
    sort(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); i++) {
        printf("%d", ans[i]);
    }
    printf("\n");
}

int main() {

    int tests;
    scanf("%d", &tests);
    for (int t = 1; t <= tests; t++) {
        printf("Case #%d: ", t);
        test();
    }

    return 0;
}