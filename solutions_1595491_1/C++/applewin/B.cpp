#include<stdio.h>
#include<stdlib.h>
using namespace std;
int cmp(const void *a, const void *b){
    int c = *(int*)a;
    int d = *(int*)b;
    return d-c;
}
int best(int total, bool s){
    if(s){
        if(total == 0 || total == 1)
            return total;
        return (total-2)/3 + 2;
    }
    if(total == 0)  return total;
    return (total -1)/3 +1;
}
int tt[110];
int main(){
    int T, ans,N,S,p;
    scanf("%d", &T);
    for(int c=1;c<=T;++c){
        ans = 0;
        scanf("%d %d %d",&N,&S,&p);
        for(int i=0;i<N;++i)
            scanf("%d", &tt[i]);
        qsort(tt, N,sizeof(int),  cmp);
        for(int i=0;i<N;++i){
    //        printf("%d\n",tt[i]);
            if(best(tt[i],false) >= p)    ++ans;
            else if(best(tt[i],true) >=p && S >0){
                ++ans;--S;
            }
        }
        printf("Case #%d: %d\n", c,ans);
    }
    return 1;
}
