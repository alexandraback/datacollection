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

int n;
long long m;

char ori[10010];

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

pair <char, int> dp[10], sta;
int o = 0;

int main()
{
    freopen("C.in","r",stdin);
    freopen("C.out","w",stdout);

    int cas = 1;
    scanf("%d", &T);
    while(T--) {
        scanf("%d%lld", &n, &m);

        long long lim = n * m;

        scanf("%s", ori);
        int px = 1;

        char pre = '1'; int sym = 1;
        for(int i = 0; i < n; i++) {
            int a = 1;
            pre = cal(pre, ori[i], a);
            sym *= a;
        }

        o = 0;
        sta = make_pair(pre, sym);
        dp[o++] = make_pair(pre, sym);

        while(1) {
            int a = 1;
            pre = cal(pre, sta.first, a);
            sym *= a; sym *= sta.second;
            if(pre == sta.first && sym == sta.second) break;
            dp[o++] = make_pair(pre, sym);
        }
        
        long long pt = (m - 1) % o;
        if(dp[pt].first != '1' || dp[pt].second != -1) {
            printf("Case #%d: NO\n", cas++);
            continue;
        }

        long long mi = -1;
        pre = '1'; sym = 1; long long sum = 0;
        for(int i = 0; i < 4 && mi == -1; i++) {
            for(int j = 0; j < n && mi == -1; j++) {
                sum++;
                int a = 1;
                pre = cal(pre, ori[j], a);
                sym *= a;
                if(pre == 'i' && sym == 1) {
                    mi = sum;
                }
            }
        }
        
        long long mx = -1; sum = 0;
        pre = '1'; sym = 1;
        for(int i = 0; i < 4 && mx == -1; i++) {
            for(int j = n - 1; j >= 0; j--) {
                sum++;
                int a = 1;
                pre = cal(ori[j], pre, a);
                sym *= a;
                if(pre == 'k' && sym == 1) {
                    mx = sum;
                }
            }
        }

        if(mi == -1 || mx == -1) {
            printf("Case #%d: NO\n", cas++);
            continue;
        }
        
        if(mi + mx < lim) {
            printf("Case #%d: YES\n", cas++);
        } else {
            printf("Case #%d: NO\n", cas++);
        }
    }
    
    return 0;
}