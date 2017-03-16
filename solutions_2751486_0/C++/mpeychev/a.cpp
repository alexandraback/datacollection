#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

int n, l;
char s[1 << 20];
int sum[1 << 20];
int vec[1 << 20], sz;

void read() {
    scanf("%s %d\n", &s, &n);
}

bool vowel(char ch) {
    return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
}

int getSum(int le, int ri) {
    if(!le) return sum[ri];
    return sum[ri] - sum[le - 1];
}

void solve() {
    sz = 0;

    l = strlen(s);
    sum[0] = !vowel(s[0]);
    for(int i = 1; i < l; i ++) {
        sum[i] = sum[i - 1];
        if(!vowel(s[i])) sum[i] ++;
    }

    for(int i = 0; i + n - 1 < l; i ++)
        if(getSum(i, i + n - 1) == n)
            vec[sz ++] = i;

    int index = 0;
    long long ans = 0;

    for(int i = 0; i < l && index < sz; i ++) {
        ans += (l - vec[index] - n + 1);
        if(i == vec[index]) index ++;
    }

    printf("%lld\n", ans);
}

int main()
{
    int t;
    scanf("%d\n", &t);
    for(int i = 1; i <= t; i ++) {
        printf("Case #%d: ", i);
        read();
        solve();
    }

    return 0;
}
