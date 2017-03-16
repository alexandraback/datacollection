
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 2e3+10;

void print(char s[]) {
    int len = strlen(s);
    int ia[MAXN], ib[MAXN];
    memset(ia, 0, sizeof(ia));
    for(int i=0; i<len; ++i) {
        ++ia[s[i]-'A'];
    }
    ib[0] = ia['Z'-'A'];
    ib[2] = ia['W'-'A'];
    ib[4] = ia['U'-'A'];
    ib[6] = ia['X'-'A'];
    ib[8] = ia['G'-'A'];
    ib[1] = ia['O'-'A'] - ib[0] - ib[2] - ib[4];
    ib[3] = ia['T'-'A'] - ib[2] - ib[8];
    ib[5] = ia['F'-'A'] - ib[4];
    ib[7] = ia['S'-'A'] - ib[6];
    ib[9] = ia['I'-'A'] - ib[5] - ib[6] - ib[8];
    for(int i=0; i<10; ++i) {
        for(int j=0; j<ib[i]; ++j) {
            printf("%d", i);
        }
    }
    printf("\n");
}

int main() {
    freopen("A-large1.in", "r", stdin);
    freopen("A-large1.out", "w", stdout);
    int icase;
    char str[MAXN];
    scanf("%d", &icase);
    for(int i=1; i<=icase; ++i) {
        scanf("%s", str);
        printf("Case #%d: ", i);
        print(str);
    }
    return 0;
}

/*
Z-0
W-2
U-4
X-6
G-8
1.3.5.7.9
O-1
T-3
F-5
S-7

*/
