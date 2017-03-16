#include <cstdio>
#include <algorithm>
#include <string.h>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

const int MAXN = 110;

struct St{
   long long a;
   int kind;
}st1[MAXN], st2[MAXN];

long long get(int ii, int jj, int kk){
    long long sum = 0;
    int i;
    if (ii != 0){
        long long temp = 0;
        for (int i = 1; i <= ii; i++){
            if (st2[i].kind == st1[1].kind){
                temp += st2[i].a;
            }
        }
        if (temp > st1[1].a) sum += st1[1].a;
        else sum += temp;
    }
    if (jj != 0 && jj != ii){
        long long temp = 0;
        for (int i = ii + 1; i <= jj; i++){
            if (st2[i].kind == st1[2].kind){
                temp += st2[i].a;
            }
        }
        if (temp > st1[2].a) sum += st1[2].a;
        else sum += temp;
    }
    if (kk != 0 && kk != jj){
        long long temp = 0;
        for (int i = jj + 1; i <= kk; i++){
            if (st2[i].kind == st1[3].kind){
                temp += st2[i].a;
            }
        }
        if (temp > st1[3].a) sum += st1[3].a;
        else sum += temp;
    }
    return sum;
}

long long get(int ii, int jj){
    long long sum = 0;
    int i;
    if (ii != 0){
        long long temp = 0;
        for (int i = 1; i <= ii; i++){
            if (st2[i].kind == st1[1].kind){
                temp += st2[i].a;
            }
        }
        if (temp > st1[1].a) sum += st1[1].a;
        else sum += temp;
    }
    if (jj != 0 && jj != ii){
        long long temp = 0;
        for (int i = ii + 1; i <= jj; i++){
            if (st2[i].kind == st1[2].kind){
                temp += st2[i].a;
            }
        }
        if (temp > st1[2].a) sum += st1[2].a;
        else sum += temp;
    }
    return sum;
}

long long get(int ii){
    long long sum = 0;
    int i;
    if (ii != 0){
        long long temp = 0;
        for (int i = 1; i <= ii; i++){
            if (st2[i].kind == st1[1].kind){
                temp += st2[i].a;
            }
        }
        if (temp > st1[1].a) sum += st1[1].a;
        else sum += temp;
    }
    return sum;
}

long long check1(int ii, int jj){
    long long sum = 0;
    if (ii != 0){
        long long temp = 0;
        for (int i = 1; i <= ii; i++){
            if (st2[i].kind == st1[1].kind){
                temp += st2[i].a;
            }
        }
        if (temp > st1[1].a + st1[2].a) sum += st1[1].a + st1[2].a;
        else sum += temp;
    }
    long long c = 0;
    for (int i = ii + 1; i <= jj; i++){
        if (st1[3].kind == st2[i].kind){
            c += st2[i].a;
        }
    }
    if (c > st1[3].a) sum += st1[3].a;
    else sum += c;
    return sum;
}

long long check2(int ii, int jj){
    long long sum = 0;
    if (ii != 0){
        long long temp = 0;
        for (int i = 1; i <= ii; i++){
            if (st2[i].kind == st1[1].kind){
                temp += st2[i].a;
            }
        }
        if (temp > st1[1].a) sum += st1[1].a;
        else sum += temp;
    }
    long long c = 0;
    for (int i = ii + 1; i <= jj; i++){
        if (st1[3].kind == st2[i].kind){
            c += st2[i].a;
        }
    }
    if (c > st1[3].a + st1[2].a) sum += st1[3].a + st1[2].a;
    else sum += c;
    return sum;
}

int main(){
    int t, n, m;
    freopen("C.in", "r", stdin);
    freopen("C.out", "w", stdout);
    scanf("%d", &t);
    for (int h = 1; h <= t; h++){
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; i++){
            scanf("%lld%d", &st1[i].a, &st1[i].kind);
        }
        for (int i = 1; i <= m; i++){
            scanf("%lld%d", &st2[i].a, &st2[i].kind);
        }
        long long ans = 0;
        if (n == 1){
            for (int i = 0; i <= m; i++){
                long long temp = get(i);
                if (temp > ans) ans = temp;
            }
        }
        if (n == 2){
            for (int i = 0; i <= m; i++){
                long long temp = get(i, m);
                if (temp > ans) ans = temp;
            }
            if (st1[1].kind == st1[2].kind){
                long long cur = 0;
                for (int i = 1; i <= m; i++){
                    if (st2[i].kind == st1[1].kind){
                        cur += st2[i].a;
                    }
                }
                if (cur > st1[1].a + st1[2].a){
                    ans = st1[1].a + st1[2].a;
                }else{
                    ans = cur;
                }
            }
        }
        if (n == 3){
            for (int i = 0; i <= m; i++){
                for (int j = i; j <= m; j++){
                    for (int k = j; k <= m; k++){
                        long long temp = get(i, j, k);
                        if (temp > ans){
                            ans = temp;
                        }
                    }
                }
            }
            if (st1[1].kind == st1[2].kind && st1[2].kind == st1[3].kind){
                long long cur = 0;
                for (int i = 1; i <= m; i++){
                    if (st2[i].kind == st1[1].kind){
                        cur += st2[i].a;
                    }
                }
                if (cur > st1[1].a + st1[2].a + st1[3].a){
                    ans = st1[1].a + st1[2].a + st1[3].a;
                }else{
                    ans = cur;
                }
            }
            if (st1[1].kind == st1[2].kind && st1[2].kind != st1[3].kind){
                for (int i = 0; i <= m; i++){
                    long long c1 = check1(i, m);
                    if (c1 > ans){
                        ans = c1;
                    }
                }
            }
            if (st1[1].kind != st1[2].kind && st1[1].kind == st1[3].kind){
                for (int i = 0; i <= m; i++){
                    long long c2 = check2(i, m);
                    if (c2 > ans){
                        ans = c2;
                    }
                }
            }
        }
        cout << "Case #" << h << ": ";
        cout << ans << endl;
    }
    return 0;
}
