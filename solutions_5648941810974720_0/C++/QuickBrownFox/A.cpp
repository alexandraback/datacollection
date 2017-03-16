#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define gc getchar
int getint() { unsigned int c; int x = 0; while (((c = gc()) - '0') >= 10) { if (c == '-') return -getint(); if (!~c) exit(0); } do { x = (x << 3) + (x << 1) + (c - '0'); } while (((c = gc()) - '0') < 10); return x; }
int getstr(char *s) { int c, n = 0; while ((c = gc()) <= ' ') { if (!~c) exit(0); } do { s[n++] = c; } while ((c = gc()) > ' ' ); s[n] = 0; return n; }
template<class T> inline bool chmin(T &a, T b) { return a > b ? a = b, 1 : 0; }
template<class T> inline bool chmax(T &a, T b) { return a < b ? a = b, 1 : 0; }

void print_case(int test_case) { printf("Case #%d: ", test_case); }

vector<string> cs = {
    "ZERO", // ok
    "ONE",  //
    "TWO", // ok
    "THREE", //
    "FOUR", // ok
    "FIVE", // ok
    "SIX",  // ok
    "SEVEN", // ok
    "EIGHT", // ok
    "NINE"   //
};

char in[1 << 15];

int cnt[999];
int res[10];

void solve_case() {
    int i, j;
    int n = getstr(in);
    for (i = 'A'; i <= 'Z'; ++i) cnt[i] = 0;
    for (i = 0; i < n; ++i) {
        cnt[in[i]]++;
    }
    memset(res, 0, sizeof(res));
    while (cnt['Z']) {
        cnt['Z']--;
        cnt['E']--;
        cnt['R']--;
        cnt['O']--;
        res[0]++;
    }
    while (cnt['W']) {
        cnt['T']--;
        cnt['W']--;
        cnt['O']--;
        res[2]++;
    }
    while (cnt['X']) {
        cnt['S']--;
        cnt['I']--;
        cnt['X']--;
        res[6]++;
    }
    while (cnt['G']) {
        cnt['E']--;
        cnt['I']--;
        cnt['G']--;
        cnt['H']--;
        cnt['T']--;
        res[8]++;
    }
    while (cnt['S']) {
        cnt['S']--;
        cnt['E']--;
        cnt['V']--;
        cnt['E']--;
        cnt['N']--;
        res[7]++;
    }
    while (cnt['V']) {
        cnt['F']--;
        cnt['I']--;
        cnt['V']--;
        cnt['E']--;
        res[5]++;
    }
    while (cnt['F']) {
        cnt['F']--;
        cnt['O']--;
        cnt['U']--;
        cnt['R']--;
        res[4]++;
    }
    while (cnt['O']) {
        cnt['O']--;
        cnt['N']--;
        cnt['E']--;
        res[1]++;
    }
    while (cnt['H']) {
        cnt['T']--;
        cnt['H']--;
        cnt['R']--;
        cnt['E']--;
        cnt['E']--;
        res[3]++;
    }
    while (cnt['N']) {
        cnt['N']--;
        cnt['I']--;
        cnt['N']--;
        cnt['E']--;
        res[9]++;
    }

    for (int i = 'A'; i <= 'Z'; ++i) if (cnt[i]) {
        cout << (char)(i + 'A') << " " << cnt[i] << endl;
    }

    for (i = 0; i < 10; ++i) {
        for (j = 0; j < res[i]; j++) putchar(i + '0');
    }
    puts("");
    return;
}



int main () {
    int test_count, test_case = getint();
    for (test_count = 0; test_count < test_case; test_count++) {
        print_case(test_count + 1);
        solve_case();
    }
    return 0;
}
