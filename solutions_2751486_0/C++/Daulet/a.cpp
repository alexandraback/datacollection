#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

bool isConsonant(char ch)
{
    if (ch != 'a' && ch != 'o' && ch != 'e' && ch != 'i' && ch != 'u')
        return true;
    return false;
}

long long solve(char *s, int n)
{
    int l = strlen(s);
    long long res = 0;
    for (int i = 0; i < l; ++i)
        for (int j = i; j < l; ++j) {
            int c = 0;
            for (int k = i; k <= j; ++k) {
                if (isConsonant(s[k])) c++;
                else
                    c = 0;
                if (c >= n) {
                    res++;
                    break;
                }
            }
        }
    return res;
}

char s[1100000];

int main()
{
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
    int T, n;
    scanf("%d\n", &T);
    for (int t = 1; t <= T; ++t) {
        scanf("%s %d\n", &s, &n);
        printf("Case #%d: %lld\n", t, solve(s, n));
    }

    return 0;
}
