#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf(stderr,args)

typedef long long lint;
typedef pair<int,int> pii;
typedef pair<lint,lint> pll;

const int INF = 0x3f3f3f3f;
const lint LINF = 0x3f3f3f3f3f3f3f3fll;
const int MAXN = 1e4+10;

int table[][4] = {{1,  2,  3,  4},
                  {2, -1,  4, -3},
                  {3, -4, -1,  2},
                  {4,  3, -2, -1}};

int acc[MAXN];

int mult(int a,int b) {
    int mult = 1;
    if(a < 0) {
        mult *= -1;
        a = -a;
    }
    if(b < 0) {
        mult *= -1;
        b = -b;
    }
    return table[a-1][b-1] * mult;
}

int inv(int x) {
    if(abs(x) == 1) return x;
    return -x;
}

char v[MAXN];

int main() {
    int t=1, T;
    for(scanf("%d",&T); t<=T; ++t) {
        int l, x;
        scanf("%d%d", &l, &x);
        if(l * x > MAXN) {
            printf("FUCK!\n");
            continue;
        }
        for(int a=0;a<l;++a)
            scanf(" %c",&v[a]);
        int total = 1;
        for(int a=0;a<l*x;++a) {
            char c = v[a%l];
            if(c == '1') total = mult(total, 1);
            else if(c == 'i') total = mult(total, 2);
            else if(c == 'j') total = mult(total, 3);
            else total = mult(total, 4);
            acc[a] = total;
        }
        bool found = 0;
        for(int i = 0; i < l*x && !found; i++) {
            if(acc[i] != 2) continue;
            for(int j = i+1; j < l*x; j++) {
                if(mult(inv(acc[i]), acc[j]) != 3) continue;
                if(mult(inv(acc[j]), total) == 4) {
                    found = 1;
                    break;
                }
            }
        }
        printf("Case #%d: %s\n", t, found ? "YES" : "NO");
    }        
    return 0;
}
