/*
Author: LotK
LANG: C++
*/

#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> v[1005];

int ans, n, m[1005];
int used[1005];
int sol(int x, int y) {
    int i, j;
  //  printf("xy %d %d\n", x, y);
  //  printf("y m[%d] = %d\n", y, m[y]);
    for(i=0 ; i<m[y] ; i++) {
   //   printf("%d %d\n", y, v[y][i]);
        if(x!=v[y][i] && used[v[y][i]] == 1) {
            ans = 1;
            break;
        }
        if(x==v[y][i]) continue;

        used[v[y][i]] = 1;
        sol(x, v[y][i]);

        if(ans == 1) {
            break;
        }
    }
    return 0;
}
int reset() {
    int i, j;
    for(i=0 ; i<=n ; i++) {
        v[i].clear();
    }
}
int main() {
    freopen("A-large.in", "r", stdin);
    freopen("A-large.out", "w", stdout);
    //freopen("tmp.in", "r", stdin);
    //freopen("tmp.out", "w", stdout);

    int t, tt, i, j, d;
    scanf("%d", &tt);
    for(t=0 ; t<tt ; t++) {
        ans = 0;
        scanf("%d", &n);
        reset();

        for(i=1 ; i<=n ; i++) {
            scanf("%d", &m[i]);
            for(j=0 ; j<m[i] ; j++) {
                scanf("%d", &d);
                v[i].push_back(d);
            }
        }

        /*
        for(i=1 ; i<=n ; i++) {
            printf("%d ", m[i]);
            for(j=0 ; j<m[i] ; j++) {
                printf("%d ", v[i][j]);
            }
            printf("\n");
        }*/


        for(i=1 ; i<=n ; i++) {
            for(j=0 ; j<=n ; j++)
                used[j] = 0;

            sol(i, i);
            if(ans == 1) break;
        }



        printf("Case #%d: ", t+1);
        if(ans == 1) printf("Yes\n");
        else printf("No\n");
    }

}
