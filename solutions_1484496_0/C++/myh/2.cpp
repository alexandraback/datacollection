#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <string>
using namespace std;
int n, x[510], s1, s2;
bool y[510], z[510], flag;

void Dfs2(int a) {
     z[a] = true;
     s2 += x[a];
     if (s1 == s2) {
         flag = true;
         return;
     }
     for (int i = a+1; i < n; ++i) 
      if (!y[i] && !flag) Dfs2(i);
     if (flag) return;
     z[a] = false;
     s2 -= x[a];
}


void Dfs1(int a) {
     y[a] = true;
     s1 += x[a];
     for (int i = 0; i < n; ++i)
      if (!y[i] && !flag) Dfs2(i);
     if (flag) return;
     for (int j = a+1; j < n; ++j)
      if (!y[j] && !flag) Dfs1(j);
     
     if (flag) return;
     y[a] = false;
     s1 -= x[a];
}


int main() {
    freopen("2.in","r",stdin);
    freopen("2.out","w",stdout);
    int tt;
    cin >> tt;
    for (int k = 1; k <= tt; ++k) {
        cin >> n;
        for (int i = 0; i < n; ++i) cin >> x[i];
        flag = false;
        memset(y,0,sizeof(y));
        memset(z,0,sizeof(z));
        for (int i = 0; i < n; ++i)
         if (!flag) Dfs1(i);
        printf("Case #%d:\n", k);
        if (!flag) printf("Impossible\n"); else {
            for (int i = 0; i < n; ++i) 
             if (y[i]) printf("%d ", x[i]);
            printf("\n");
            for (int i = 0; i < n; ++i)
             if (z[i]) printf("%d ", x[i]);
            printf("\n");
        }
    }
    return 0;
}
