#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <list>
using namespace std;

#define PB push_back
#define MP make_pair
#define A first
#define B second
#define eps 1e-8

typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<double> VD;
typedef long long LL;
typedef pair<int,int> PII;

char s[1000010];
int t, a[1000010], b[1000010];

int main() {
    freopen("A-large.in", "r", stdin);
    freopen("A-large.out", "w", stdout);
    scanf("%d", &t);
    for (int ca = 1; ca <= t; ca ++ ) {
        int c;
        scanf("%s%d", s, &c);
        int l = strlen(s);
        a[l] = 0;
        for (int i = l - 1; i >= 0; i -- )
            if (s[i] != 'a'
             && s[i] != 'e'
             && s[i] != 'i'
             && s[i] != 'o'
             && s[i] != 'u') a[i] = a[i + 1] + 1;
            else a[i] = 0;
        b[l] = l;
        LL ans = 0;
        for (int i = l - 1; i >= 0; i -- ) {
            if (a[i] >= c) b[i] = i + c - 1;
            else b[i] = b[i + 1];
            ans += l - b[i];
        }
        printf("Case #%d: %lld\n", ca, ans);
    }
    return 0;
}
