#include <cstdio>

#define MAXN 1003

using namespace std;

char s[MAXN];

int T, N;
int shy_cnt[MAXN];

inline bool check(int x) {
    
    int clap = shy_cnt[0] + x;
    
    for (int i = 1; i < N; ++i) {
        if (clap < i) return false;
        clap += shy_cnt[i];
    }
    
    return true;

}

inline void solve(int t) {

    scanf("%d%s", &N, s); ++N;
    for (int i = 0; i < N; ++i)
        shy_cnt[i] = s[i] - '0';
   
    int sol = 0;
    while (!check(sol++));

    printf("Case #%d: %d\n", t, sol - 1);

}

int main(void) {

    scanf("%d", &T);
    for (int t = 0; t < T; ++t) solve(t + 1);

    return 0;

}
