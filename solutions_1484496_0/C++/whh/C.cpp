#include <cstdio>
#include <cstring>
#include <algorithm>
#define FOR(i,s,e) for(int (i)=(s);(i)<(e);++(i))

using namespace std;
typedef long long LL;

int Z, N;
LL a[505];
LL sum;
int p[505];
bool ok;

void recur(int k,LL s, int cnt){
   // printf("%d %lld %d \n", k, s, cnt);
    if (ok) return;
    if (k==N){
        if (s==0 && cnt){
            bool f = true;
            for (int i=0;i<N;++i){
                if (p[i]==-1){
                    if (!f) printf(" ");
                    printf("%lld", a[i]);
                    f= false;
                }
            }
            puts("");
            f = true;
            for (int i=0;i<N;++i){
                if (p[i]==1){
                    if (!f) printf(" ");
                    printf("%lld", a[i]);
                    f= false;
                }
            }
            puts("");
            
            ok = true;
        }
        return;
    }    
    p[k] = -1;
    recur(k+1,s-a[k],cnt+1);
    p[k] = +1;
    recur(k+1,s+a[k],cnt+1);
    p[k] = 0;
    recur(k+1,s,cnt);
}

int main(){

    scanf("%d", &Z);
    for (int tc=1;tc<=Z;++tc){
        printf("Case #%d:\n", tc);
        scanf("%d", &N);
        for (int i=0;i<N;++i){
            scanf("%lld", &a[i]);
        }
        ok = false;
        recur(0,0,0);
        if (!ok){
            puts("Impossible");
        }
    }

    return 0;
}
