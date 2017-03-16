#include <cstdio>
#include <algorithm>
#include <map>
#include <cstdlib>
#include <string>
#include <cstring>
#include <set>
#include <queue>
#include <stack>

#define MAX 110

using namespace std;

typedef long long int ll;

ll a[MAX],b[MAX];
int A[MAX],B[MAX];
int T,N,M;
ll maior;

struct ass{

    int n,m;
    ll ultA,ultB;
    ll tot;

};


void bfs(){


    struct ass ini;
    queue<ass> fila;

    ini.n=0;
    ini.m=0;
    ini.tot=0;
    ini.ultA=a[0];
    ini.ultB=b[0];
    fila.push(ini);

    while(!fila.empty()){

        struct ass atual=fila.front();
        fila.pop();

      //  printf("total:%lld , N:%d, M:%d, ultA:%lld, ultB:%lld\n",atual.tot,atual.n,atual.m,atual.ultA,atual.ultB);

        if(atual.n == N || atual.m == M ){

            if(atual.tot > maior)
                maior=atual.tot;

            continue;
        }


        if(A[atual.n] != B[atual.m]){

            struct ass aux=atual;
            aux.n++;
            aux.ultA=a[aux.n];
            fila.push(aux);

            struct ass aux2=atual;
            aux2.m++;

            aux2.ultB=b[aux2.m];
            fila.push(aux2);

        }else{

            if(atual.ultA>atual.ultB){

                struct ass aux=atual;
                aux.tot+=atual.ultB;
                aux.ultA=atual.ultA-atual.ultB;
                aux.m++;
                aux.ultB=b[aux.m];
                fila.push(aux);

            }else if(atual.ultA<atual.ultB){
                struct ass aux=atual;
                aux.tot+=atual.ultA;
                aux.ultB=atual.ultB-atual.ultA;
                aux.n++;
                aux.ultA=a[aux.n];
                fila.push(aux);

            }else{
                struct ass aux=atual;
                aux.tot+=atual.ultB;
                aux.n++;
                aux.m++;
                aux.ultA=a[aux.n];
                aux.ultB=b[aux.m];
                fila.push(aux);

            }

        }

    }


}

int main(void){

    freopen("C.in","r",stdin);
    freopen("C.out","w",stdout);

    scanf("%d",&T);

    for(int casos=1;casos<=T;casos++){

        printf("Case #%d: ",casos);

        scanf("%d %d",&N,&M);


        for(int i=0;i<N;i++){
            scanf("%lld %d",&a[i],&A[i]);
        }

        for(int i=0;i<M;i++){
            scanf("%lld %d",&b[i],&B[i]);
        }

        maior=0;

        bfs();

        printf("%lld\n",maior);


    }


    return 0;

}
