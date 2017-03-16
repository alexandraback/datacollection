#include<stdio.h>
#include<string.h>
#include<algorithm>
typedef long long LL;
LL getRev(char s[], int n) {
    LL ans = 0;
    for(int i = n - 1; i >= 0; i --) {
        ans = ans * 10 + s[i] - '0';
    }
    return ans;
}
LL getAns(LL N) {
    char s[20], ss[20];
    sprintf(s, "%lld", N);
    int n = strlen(s);
    LL ten[20];
    ten[0] = 1;
    for(int i = 1; i <= 14; i ++) {
        ten[i] = ten[i - 1] * 10;
    }
    LL cnt = 1;
    for(int i = 1; i < n; i ++) {
        cnt += ten[i / 2] - 1;
        cnt += ten[i - i / 2] - 1;
        if(i / 2 > 0) {
            ++ cnt;
        }
    }
    LL ans = N - ten[n - 1] + cnt;
    ss[0] = '1';
    for(int i = 1; i < n; i ++) {
        ss[i] = '0';
    }
    LL tmp = 0;
    LL j = 1;
    for(int i = n - 1; i > 0; i --, j *= 10) {
        ss[i] = s[n - i - 1];
        tmp += j * (ss[i] - '0');
        if(N < getRev(ss, n)) {
            break;
        }
        ans = std::min(ans, cnt + tmp + 1 + N - getRev(ss, n));
    }
    return ans;
}
int main() {
    //freopen("input.txt", "rb", stdin);
    freopen("A-small-attempt1.in", "rb", stdin);
    freopen("output.txt", "wb", stdout);
    int t;
    scanf("%d", &t);
    for(int tt = 1; tt <= t; tt ++) {
        LL N;
        scanf("%lld", &N);
        LL ans = getAns(N);
        if(N > 1) {
            ans = std::min(ans, getAns(N - 1) + 1);
        }
        printf("Case #%d: %lld\n", tt, ans);
    }
    return 0;
}
