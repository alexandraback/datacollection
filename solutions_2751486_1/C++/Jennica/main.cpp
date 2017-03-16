#include<cstdio>
#include<cstring>
char s[1000010];
int ll[1000010];

int min(int a, int b) {
    return a < b ? a : b;
}

int max(int a, int b) {
    return a > b ? a : b;
}

int main() {
      freopen("AAAAA.in","r",stdin);
      freopen("AAAAA.out","w",stdout);
    int i, T, t, l, n, j, e;
    long long cnt, len;
    scanf("%d", &T);
    for (t = 1; t <= T; ++t) {
        scanf("%s%d", s + 1, &n);
        len = strlen(s + 1);
        for (i = len; i; --i) {
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
                l = i;
                if (len - i >= n)
                    ll[i] = i + n - 1;
                else
                    ll[i] = len;
                break;
            }
        }
        for (--i; i >= 0; --i) {
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
                if (l - i - 1 >= n)
                    ll[i] = i + n - 1;
                else
                    ll[i] = ll[l];
                l = i;
            }
        }
        cnt = 0;
        l = 0;
        for (i = 1; i <= len; ++i) {
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
                j = min(i - l, n);
                e = max(1, n - ll[i] + i);
                //      printf("i=%d j=%d e=%d\n", i, j, e);
                if (j >= e)
                    cnt += (j - e + 1LL) * (ll[i] - i - n + 1LL)+(j + e)*(j - e + 1LL) / 2LL;
                l = i;
            }
        }
        cnt = (len - n + 2LL)*(len - n + 1LL) / 2 - cnt;
        printf("Case #%d: %lld\n", t, cnt);
    }
    return 0;
}