#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

int test, n, m, f[101], a[21][21], re, Min, pos[21][21];

int gf(int i){
    if (i == f[i]) return i;
    return f[i] = gf(f[i]);
}

int main(){
    freopen("c.in", "r", stdin);
    freopen("cx.out", "w", stdout);
    scanf("%d", &test);
    for (int uu = 1; uu <= test; uu++)
    {
        printf("Case #%d: ", uu);
        scanf("%d%d%d", &n, &m, &re);
        if (min(n, m) <= 2) 
        {
           printf("%d\n", re);
           continue;
        }
        if (n > m) swap(n, m);
        int now = 3; bool ok = false;
        int can = 0;
        if (re <= 4)
        {
           printf("%d\n", re);
           continue;
        }
        for (; now <= n ;)
        {
           if (re <= (now * now / 2 + 1)) 
           {
              printf("%d\n", 2 * now - 2);
              ok = true;
              break;
           }
           if (re == (now * now / 2 + 1) + 1) 
           {
              printf("%d\n", 2 * now - 1);
              ok = true;
              break;
           }
           if (now < n && re <= (now * now / 2 + 1) + now) 
           {
              printf("%d\n", 2 * now);
              ok = true;
              break;
           }
           if (now < n && re <= (now * now / 2 + 1) + now + 2)
           {
              printf("%d\n", 2 * now + 1);
              ok = true;
              break;
           }        
           now += 2;
        }
        if (ok) continue;
        now -= 2;
        can = (now * now / 2 + 1); int Use = 2 * now - 2;
        if (now != n) can += now, Use += 2;
        //printf("TT %d %d %d\n", re, can, Use);
        for (int i = 1; i <= m - now; i++)
        {
            can += n; Use += 2;
            if (re <= can) 
            {
               printf("%d\n", Use);
               ok = true;
               break;
            }
            if (i != m - now && re <= can + 2)
            {
               printf("%d\n", Use + 1);
               ok = true;
               break;
            }
        }
        if (!ok) printf("%d\n", Use + re - can);
    }
}
