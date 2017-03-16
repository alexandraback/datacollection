#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cmath>
using namespace std;
int lev1[1010], lev2[1010];
bool vis1[1010], vis2[1010];
int T, N;

int getMin1() {
    int idx = -1;
    for (int i = 0; i < N; i++) {
        if (!vis1[i]) {
           if (idx == -1 || lev1[idx] > lev1[i]) idx = i;
           else if (lev1[idx] == lev1[i]) {
                if (lev2[idx] < lev2[i]) idx = i; 
           }
        }
    }
    return idx;
} 

int getMin2() {
    int idx = -1;
    for (int i = 0; i < N; i++) {
        if (!vis2[i]) {
           if (idx == -1 || lev2[idx] > lev2[i]) idx = i;
        }
    }
    return idx;
} 

int main() {
    scanf("%d", &T);
    freopen("test.out","w",stdout);
    for (int cas = 1; cas <= T; cas++) {
        scanf("%d", &N);
        memset(vis1, 0 ,sizeof(vis1));
        memset(vis2, 0 ,sizeof(vis2));
        for (int i = 0; i < N; i++) {
            scanf("%d %d", lev1 + i, lev2 + i);
        }
        int sum = 0,cnt = 0;;
        bool ok = 1;
        for (int i = 0; i <= 2 * N; i++) {
            int loc1 = getMin1();
            int loc2 = getMin2();
            if (loc2 != -1 && sum >= lev2[loc2]) {
               if (!vis1[loc2])     sum += 2;
               else                 sum++;
               vis2[loc2] = 1;
               vis1[loc2] = 1;
               cnt++;
            } else if (loc1 != -1 && sum >= lev1[loc1]) {
               vis1[loc1] = 1;
               sum++;  
               cnt++;
            }
        }
        for (int i = 0; i < N; i++) {
            if (!vis2[i]) ok = 0;
        }
        if (ok) printf("Case #%d: %d\n", cas, cnt);
        else    printf("Case #%d: Too Bad\n",cas);
    }
}
