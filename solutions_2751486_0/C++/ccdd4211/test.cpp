#include <iostream>
#include <cstdio>
#include <map>
#include <cstring>
#include <algorithm>
#include <fstream>
#include <string>
#include <queue>
#include <bitset>
#include <ctime>
#include <cmath>
#define  inf  0XFFFFFFF
#define  N    2222222
#define  LL   long long
#define  mod  1000000007ll
#define  eps  1e-10
#define  file1

using namespace std;

#ifdef file
ifstream fi("input.txt");
#define  cin fi
ofstream fo("output.txt");
#define  cout fo
#endif

char s[N];
LL next[N];
bool vol(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

int main()
{
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("out.txt", "w", stdout);
    int n; scanf("%d", &n);
    for (int T=1; T<=n; T++) {
        LL ans = 0, len;
        scanf("%s%lld", s, &len);
        LL l = strlen(s);
        memset(next, 0, sizeof next);
        int last = -1;
        int cons = 0;
        for (int i=l-1; i>=0; i--) {
            if (!vol(s[i])) {
                cons++;
                if (cons >= len)
                    last = i;
            }
            else
                cons = 0;
            next[i] = last;
        }
        for (int i=0; i<l; i++) {
            if (next[i] == -1) continue;
            ans += l - (next[i]+len-1);
        }
        printf("Case #%d: %lld\n", T, ans);
    }
}
