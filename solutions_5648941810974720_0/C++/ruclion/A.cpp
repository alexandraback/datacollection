#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>

using namespace std;

const int maxn = 200 + 100;

char a[maxn] = {'Z', 'W', 'X', 'S', 'V', 'U', 'R', 'O', 'T', 'I'};
string w[maxn] = {"ZERO", "TWO", "SIX", "SEVEN", "FIVE", "FOUR",  "THREE", "ONE",  "EIGHT", "NINE"};
int no[maxn] = {0, 2, 6, 7, 5, 4, 3, 1, 8, 9};
int num[maxn], ans[maxn];
string s;
void solve() {
    //cout << s << endl;
    memset(num, 0, sizeof(num));
    memset(ans, 0, sizeof(ans));
    for(int i = 0; i < s.length(); i++) {
        num[s[i]]++;
        //printf("%d\n", s[i]);
    }
    for(int i = 0; i < 10; i++) {
        char key = a[i];
        int t = num[key];
        ans[no[i]] += t;

        //("--  %d\n", t);
        for(int j = 0; j < w[i].length(); j++) {
            num[w[i][j]] -= t;
        }
    }
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < ans[i]; j++) {
            printf("%d", i);
        }
    }
    printf("\n");
}

int main() {
    freopen("A-small-attempt1.in", "r", stdin);
    //freopen("A.txt", "r", stdin);
    freopen("Aout.txt", "w", stdout);
    int t;
    scanf("%d", &t);
    for(int i = 1; i <= t; i++) {
        printf("Case #%d: ", i);
        cin >> s;
        solve();
    }
    return 0;
}

