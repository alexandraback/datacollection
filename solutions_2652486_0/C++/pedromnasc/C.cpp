#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include <stack>
#include <cmath>
#include <cstdlib>

#define MAX 110

using namespace std;

typedef long long int ll;

int T,R,N,M,K,cont;
int v[MAX];
int pot[8];
vector<int> vetor;
int numeros[10];
vector<int>  conj[10000];

int bckt(int p,int atual,int esp){

    if(p == esp) return 1;

    if(atual == N) return 0;

    if(bckt(p*vetor[atual],atual+1,esp)) return 1;
    if(bckt(p,atual+1,esp)) return 1;

    return 0;

}

void bckt2(int atual){

    //printf("atual:%d, N:%d\n",atual,N);
   // system("PAUSE");
    if(atual == N){

        for(int i=0;i<N;i++){
            conj[cont].push_back(numeros[i]);
        }
        cont++;
        return;

    }

    for(int i=2;i<=M;i++){
        numeros[atual]=i;
        bckt2(atual+1);
    }

}


int main(void){

    freopen("C.in","r",stdin);
    freopen("C.out","w",stdout);

    for(int i=0;i<8;i++)
        pot[i]=1<<i;
    scanf("%d",&T);

    for(int caso=1;caso<=T;caso++){
        scanf("%d %d %d %d",&R,&N,&M,&K);

        printf("Case #%d:\n",caso);

        for(int vezes=0;vezes<R;vezes++){

            for(int i=0;i<K;i++){
                scanf("%d",&v[i]);
            }
            cont=0;
            bckt2(0);

            for(int i=0;i<cont;i++){

                vetor=conj[i];

                bool passo=true;
                for(int j=0;j<K;j++){
                    bool aux=bckt(1,0,v[j]);
                    if(!aux){
                        passo=false;
                        break;
                    }
                }



                if(passo){
                    for(int i=0;i<N;i++)
                        printf("%d",vetor[i]);
                    printf("\n");
                    break;
                }

            }

        }


    }

    return 0;
}
