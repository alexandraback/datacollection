#include <stdio.h>
#include <algorithm>

using namespace std;

int v[101];
int N, A;

int sol(){
    int i,j,tr,r,ta,m;
    scanf("%d %d", &A, &N);
    for (i=0;i<N;i++) scanf("%d", v+i);
    sort(v,v+N);
//    for (i=0;i<N;i++) printf("v[%d]=%d\n",i,v[i]);
    r = N;
    ta = A;
    m = 0;

    for (i=0;i<=N;i++){
        // check delete all
        tr = m+(N-i);
        if (tr < r) r = tr;
        if (i==N) continue;
        if (ta==1) break;
        while (ta<=v[i]){
//            printf("ta=%d m=%d v[%d]=%d\n", ta,m,i,v[i]);
            ta += (ta-1);
            m++;
        }
        ta += v[i];
    }
    return r;
}

int main(){
    int cas, T;
    scanf("%d", &T);
    for (cas=1; cas<=T; cas++){
        printf("Case #%d: %d\n", cas, sol());
    }
    return 0;
}

