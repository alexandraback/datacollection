#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

int A[1005], casos, ctos, cortes, mejor;

int main()
{
    freopen("input.in","r",stdin);
    freopen("output.txt","w",stdout);

    scanf("%d",&casos);
    for(int v=1; v<=casos; v++){
        scanf("%d",&ctos);
        for(int i=1; i<=ctos; i++){
            scanf("%d",&A[i]);
        }
        mejor=1001;
        for(int x=1; x<=1000; x++){
            cortes=0;
            for(int i=1; i<=ctos; i++){
                if(A[i]%x==0){
                    cortes+=A[i]/x-1;
                }
                else {
                    cortes+=A[i]/x;
                }
            }
            if(cortes+x<mejor){
                mejor=cortes+x;
            }
        }
        printf("Case #%d: %d\n",v,mejor);
    }
    return 0;
}
