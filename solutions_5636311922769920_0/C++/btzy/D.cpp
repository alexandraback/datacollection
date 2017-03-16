#include <cstdio>
using namespace std;
int t,k,c,s;
int main(){
    scanf("%d",&t);
    for(int ct=1;ct<=t;++ct){
        scanf("%d%d%d",&k,&c,&s);
        if(c*s<k){
            printf("Case #%d: IMPOSSIBLE\n",ct);
            continue;
        }
        printf("Case #%d:",ct);
        int covered=0;
        while(covered<k){
            long long loc=0;
            long long mul=1;
            for(int i=0;i<c;++i){
                loc+=mul*((covered<k)?covered:(k-1));
                mul*=k;
                ++covered;
            }
            printf(" %lld",loc+1);
        }
        printf("\n");
    }
}
