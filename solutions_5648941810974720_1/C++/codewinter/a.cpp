#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <string>
using namespace std;

string s[10] =  {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
void dec(int cnt[], int val, int idx) {
    for (int i = 0; i < s[idx].length(); i++) 
        cnt[s[idx][i] - 'A'] -= val;
}

void solve(int cas) {
    char str[20010];
    scanf("%s", str);
    int cnt[26];
    int a[10];
    memset(a, 0, sizeof(a));
    memset(cnt, 0, sizeof(cnt));
    int len = strlen(str);
    for (int i = 0; i < len; i++) cnt[str[i] - 'A']++;
    a[0] = cnt[25];
    dec(cnt, a[0], 0);
    a[6] = cnt['X' - 'A'];
    dec(cnt, a[6], 6);
    a[7] = cnt['S' - 'A'];
    dec(cnt, a[7], 7);
    a[5] = cnt['V'- 'A'];
    dec(cnt, a[5], 5);
    a[4] = cnt['F' - 'A'];
    dec(cnt, a[4], 4);
    a[3] = cnt['R' - 'A'];
    dec(cnt, a[3], 3);
    a[8] = cnt['G' - 'A'];
    dec(cnt, a[8], 8);
    a[2] = cnt['T' - 'A'];
    dec(cnt,a[2], 2);
    a[1] = cnt['O' - 'A'];
    dec(cnt, a[1], 1);
    a[9] = cnt['I' - 'A']; 
    printf("Case #%d: ", cas);
    for (int i = 0; i < 10; i++)
        while(a[i]--) printf("%d", i);
    printf("\n");
}


int main()
{
    freopen("A-large.in", "r", stdin);
    freopen("A-large.out", "w", stdout);
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        solve(i);
    }
    return 0;
}


