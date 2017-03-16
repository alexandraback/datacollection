#include <cstdio>
#include <cstring>
#include <map>
using namespace std;
int T, N;
int num[510];
map<int, int> tot;
int main()
{
    freopen("C.in","r",stdin);
    freopen("C.out","w",stdout);
    scanf("%d", &T);
    for (int cas = 1; cas <= T; cas++) {
        scanf("%d", &N);
        tot.clear();
        for (int i = 0; i < N; i++) {
            scanf("%d", num + i);
        }
        bool ok = 0;
        int f, s;
        for (int i = 0; i < (1 << N); i++) {
            int sum = 0;
            for (int j = 0; j < N; j++) {
                if (i & (1 <<j)) sum += num[j];
            }
            if (tot.find(sum) == tot.end()) {
               tot[sum] = i;
            } else {
               ok = 1;
               f = tot[sum];
               s = i;
               break;
            }
        }
        printf("Case #%d:\n",cas);
        if (!ok) printf("Impossible\n");
        else {
             for (int i = 0; i < N; i++) {
                 if ((f & (1 <<i)) && (s & (1 << i))) {
                    f-= (1<<i);
                    s-= (1<<i);
                 }
             }
             int cnt = 0;
             for (int i = 0; i < N; i++) {
                 if (f & (1 << i)) {
                       if (cnt != 0)   printf(" %d", num[i]);
                       else            printf("%d", num[i]);
                       cnt++;
                 }
             }
             printf("\n");
             cnt = 0;
             for (int i = 0; i < N; i++) {
                 if (s & (1 << i)) {
                       if (cnt != 0)   printf(" %d", num[i]);
                       else            printf("%d", num[i]);
                       cnt++;
                       
                 }
             }
             printf("\n");
        }
    }
}
