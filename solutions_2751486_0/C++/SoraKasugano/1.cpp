#include <cstdio>
#include <cstring>
char s[1000010];
long long solve() {
    int n;
    scanf("%s%d", s, &n);
    int l = int(strlen(s)), x = 0, y = -1;
    long long z = 0;
    for (int i = 0 ; i < l ; ++i) {
        if (s[i] == 'a' || s[i] == 'i' || s[i] == 'u' || s[i] == 'e' || s[i] == 'o') {
            x = 0;
        }
        else {
            ++x;
            if (x >= n) y = i - n + 1;
        }
        z += (y + 1);
    }
    return z;
}
int main() {
    int t;
    freopen("1.txt", "r", stdin);
    freopen("2.txt", "w", stdout);
    scanf("%d", &t);
    for (int i = 1 ; i <= t ; ++i)
        printf("Case #%d: %lld\n", i, solve());
    fclose(stdin);
    fclose(stdout);
    return 0;
}