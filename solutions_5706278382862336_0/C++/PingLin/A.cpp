#include <cstdio>
#include <cmath>
using namespace std;
int main(){
    int t, p, q, tmp;
    scanf("%d", &t);
    for(int tt=1 ; tt<=t ; tt++){
        scanf("%d/%d", &p, &q);
        tmp=log2(q);

        printf("Case #%d: ", tt);
        if(pow(2, tmp)!=q){
            printf("impossible\n");
            continue;
        }
        if(p==1){
            printf("%d\n", tmp);
            continue;
        }

        tmp=1;
        while(p*2<q){
            q/=2;
            ++tmp;
        }
        printf("%d\n", tmp);
    }
}
