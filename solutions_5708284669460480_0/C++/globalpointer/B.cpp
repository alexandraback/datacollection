#include <bits/stdc++.h>
#define sz(x) ((int)((x).size()))
typedef long long ll;
typedef long double real;

int K, T, S;
char k[105];
char t[105];
char s[105];
real num, den, max;

void f(int i) {
    if (i < S) for (int j = 0; j < K; j++) { s[i] = k[j]; f(i+1); }
    else {
        int count = 0;
        for (int j = 0; j+T <= S; j++) {
            bool cool = true; for (int k = 0; k < T; k++) if (s[j+k] != t[k]) { cool = false; break; }
            if (cool) count++;
        }
        //printf("%s %d\n", s, count);
        max = std::max(max, real(count));
        num += count;
        den++;
    }
}

int main()
{
    int TestCases; scanf("%d", &TestCases);
    for (int testcase = 1; testcase <= TestCases; testcase++) {
        scanf("%d%d%d %s %s", &K, &T, &S, k, t);
        s[S] = '\0'; num = den = max = 0.0L;
        f(0);
        printf("Case #%d: ", testcase);
        if (max == 0.0L) printf("0.0\n");
        else printf("%Lf\n", max - num/den);
    }
}

