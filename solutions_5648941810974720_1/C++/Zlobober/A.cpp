#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cassert>
#include <memory.h>
using namespace std;

const int N = 2050;
char buf[N];

int cnt[128];

const char* words[] = {
    "ZERO",
    "ONE",
    "TWO",
    "THREE",
    "FOUR",
    "FIVE",
    "SIX",
    "SEVEN",
    "EIGHT",
    "NINE",
};

char ans[N];
int apt = 0;

void extract(int d) {
    int l = strlen(words[d]);
    ans[apt++] = '0' + d;
    for (int i = 0; i < l; i++) {
        cnt[words[d][i]]--;
        assert(cnt[words[d][i]] >= 0);
    }
}

void solve(int cs) {
    memset(cnt, 0, sizeof(cnt));
    apt = 0;
    scanf("%s", buf);
    int l = strlen(buf);
    for (int i = 0; i < l; i++) {
        cnt[buf[i]]++;
    }
    while (cnt['Z'])
        extract(0);
    while (cnt['W'])
        extract(2);
    while (cnt['U'])
        extract(4);
    while (cnt['X'])
        extract(6);
    while (cnt['G'])
        extract(8);
    while (cnt['O'])
        extract(1);
    while (cnt['T'])
        extract(3);
    while (cnt['F'])
        extract(5);
    while (cnt['S'])
        extract(7);
    while (cnt['N'])
        extract(9);
    for (int i = 0; i < 128; i++)
        assert(cnt[i] == 0);
    ans[apt] = 0;
    sort(ans, ans + apt);
    printf("Case #%d: %s\n", cs, ans);
}

int main() {
    int T;
    scanf("%d ", &T);
    for (int i = 0; i < T; i++) {
        solve(i + 1);
    }
}
