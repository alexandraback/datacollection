#include <cstdio>
#include <algorithm>
#include <map>
#include <cstdlib>
#include <string>
#include <cstring>
#include <set>
#include <queue>
#include <stack>

#define MAX 1010

using namespace std;

int visitados[MAX];
int grau[MAX];
int lista[MAX][MAX];
int T,N;

void dfs(int atual){

    visitados[atual]++;

    for(int i=0;i<grau[atual];i++){
        if(visitados[lista[atual][i]] == 2) continue;

        dfs(lista[atual][i]);

    }

}

int main(void){

    freopen("A.in","r",stdin);

    freopen("A.out","w",stdout);

    scanf("%d",&T);

    for(int casos=1;casos<=T;casos++){

        printf("Case #%d:",casos);

        scanf("%d",&N);

        for(int i=0;i<N;i++){
            scanf("%d",&grau[i]);
            for(int j=0;j<grau[i];j++){
                scanf("%d",&lista[i][j]);
                lista[i][j]-=1;
            }
        }

        memset(visitados,0,sizeof(visitados));

        for(int i=0;i<N;i++){

            memset(visitados,0,sizeof(visitados));

            dfs(i);

            for(int j=0;j<N;j++){
                //printf("I:%d,J:%d, visitados:%d\n",i+1,j+1,visitados[j]);

                if(visitados[j] == 2){
                    printf(" Yes\n");
                    goto a;
                }
            }

        }

        printf(" No\n");

        a:;



    }


    return 0;



}
