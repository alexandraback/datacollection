#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

typedef long long int ll;

int T;
ll P,Q;

int main(void){

    freopen("A.in","r",stdin);
    freopen("A.out","w",stdout);

    scanf("%d",&T);

    for(int caso=1;caso<=T;caso++){
        printf("Case #%d: ",caso);
        scanf("%lld/%lld",&P,&Q);
        int resp=0;
        int cont=0;
        bool passo=false;
        while(1){


            if(P == 0) break;
            if(P == 1 && Q == 1) break;

            while(P<Q){
                P*=2;
                if(!passo) resp++;
            }
            P-=P/Q*Q;

            if(passo){
                cont++;
                if(cont == 50){
                    resp=-1;
                    break;
                }
            }

            passo=true;

        }

        if(resp == -1) printf("impossible\n");
        else cout << resp << endl;

    }

    return 0;
}
