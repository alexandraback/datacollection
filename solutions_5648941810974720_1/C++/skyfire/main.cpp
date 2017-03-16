#include <bits/stdc++.h>

using namespace std;

string digits[10] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};

int ans[10];
int cnt[26];

void sub(int dig) {

    for (char c: digits[dig])
        cnt[c - 'A'] -= ans[dig];
}

void solve(int n, char* s) 
{
    memset(ans, 0, sizeof ans);
    memset(cnt, 0, sizeof cnt);
    
    for (int i = 0; i < n; ++i)
        ++cnt[s[i]-'A'];
    
    ans[0] = cnt['Z' - 'A'];
    ans[6] = cnt['X' - 'A'];
    ans[2] = cnt['W' - 'A'];
    ans[4] = cnt['U' - 'A'];
    ans[8] = cnt['G' - 'A'];

    sub(0);
    sub(2);
    sub(4);
    sub(6);
    sub(8);

    ans[7] = cnt['S' - 'A'];
    ans[3] = cnt['H' - 'A'];
    ans[5] = cnt['F' - 'A'];

    sub(7);
    sub(3);
    sub(5);

    ans[1] = cnt['O' - 'A'];
    ans[9] = cnt['I' - 'A'];

    for (int i = 0; i < 10; ++i)
        for (int j = 0; j < ans[i]; ++j)
            printf("%d", i);
}

int main()
{
    //freopen("sample.in", "r", stdin);
    //freopen("A-small-attempt0.in", "r", stdin);
    freopen("A-large.in", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n_tests;
    scanf("%d", &n_tests);

    for (int test_id = 1; test_id <= n_tests; ++test_id)
    {
        char s[2222];
        scanf("%s", s);
                
        printf("Case #%d: ", test_id);

        solve(strlen(s), s);

        printf("\n");
    }

    return 0;
}
