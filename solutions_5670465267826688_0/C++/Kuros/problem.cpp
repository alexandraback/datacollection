#include <stdio.h>
#include <set>
#include <string>
#include <string.h>
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

#define MAXN 110111
#define tl(x) (x << 1)
#define tr(x) (x << 1 | 1)

int T;

int n, m;

char ori[10010];

char s[10010];

char cal(char a, char b, int & sym) {
    if(a == '1') return b;
    else if(b == '1') return a;
    else if(a == 'i' && b == 'j') return 'k';
    else if(a == 'j' && b == 'k') return 'i';
    else if(a == 'k' && b == 'i') return 'j';
    sym = -1;
    if(a == 'j' && b == 'i') return 'k';
    else if(a == 'k' && b == 'j') return 'i';
    else if(a == 'i' && b == 'k') return 'j';
    else if(a == b) return '1';
}

bool can[10010];

int main()
{
    freopen("pro.in","r",stdin);
    freopen("pro.out","w",stdout);
    int cas = 1;
    scanf("%d", &T);
    while(T--) {
        scanf("%d%d", &n, &m);
        scanf("%s", ori);
        int len = 0;
        for(int i = 1; i <= m; i++) {
            for(int j = 0; j < n; j++) {
                s[len++] = ori[j];
            }
        }
        memset(can,0,sizeof(can));
        s[len] = 0; char pre = '1'; int sym = 1;
        for(int i = len - 1; i >= 0; i--) {
            int a = 1;
            char b = cal(s[i], pre, a);
            sym *= a;
            if(sym == 1 && b == 'k') can[i] = 1;
            pre = b;
        }

        bool find = 0;
        pre = '1'; sym = 1;
        for(int i = 0; i < len - 2; i++) {
            int a = 1;
            char b = cal(pre, s[i], a);
            sym *= a;
            if(sym == 1 && b == 'i') {
                char pr = '1'; int sm = 1;
                for(int j = i + 1; j < len - 1; j++) {
                    int a1 = 1; char b1 = cal(pr, s[j], a1);
                    sm *= a1;
                    if(sm == 1 && b1 == 'j') {
                        if(can[j + 1]) {
                            find = 1;
                            break;
                        }
                    }
                    pr = b1;
                    if(find) break;
                }
            }
            pre = b;
            if(find) break;
        }
        if(find) {
            printf("Case #%d: YES\n", cas++);
        } else {
            printf("Case #%d: NO\n", cas++);
        }
    }
    
    return 0;
}