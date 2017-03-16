#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <set>
#include <stack>
#include <vector>

#define MAX 105

using namespace std;

typedef long long int ll;

const ll MOD = 1000000007;

int T,tamC;
int N;
char linha[MAX][MAX];
int matriz[MAX][MAX];
int compo[MAX];
char visitados[MAX];
vector<int> lista[MAX];
vector<int> listaR[MAX];
ll fat[MAX];
int tam[MAX];
set<char> heap[MAX];
pair<char,char> v[MAX];
stack<int> pilha;

void dfs(int atual){

    visitados[atual]=1;

    for(int i=0;i<lista[atual].size();i++){
        int prox=lista[atual][i];
        if(visitados[prox]) continue;
        dfs(prox);
    }

    pilha.push(atual);
}




void dfs2(int atual,int num){

    tamC++;
    compo[atual]=num;
    visitados[atual]=1;

    for(int i=0;i<listaR[atual].size();i++){
        int prox=listaR[atual][i];
        if(visitados[prox]) continue;
        dfs2(prox,num);
    }
}

void dfs3(int atual){
    visitados[atual]=1;
    for(int i=0;i<N;i++){
        if(matriz[atual][i] == 0) continue;
        if(visitados[i]) continue;
        dfs3(i);
    }
}


int main(void){

    fat[0]=1;
    for(int i=1;i<MAX;i++)
        fat[i]=(fat[i-1]*i)%MOD;
    freopen("B.in","r",stdin);
    freopen("B.out","w",stdout);

    scanf("%d",&T);

    for(int caso=1;caso<=T;caso++){
        printf("Case #%d: ",caso);
        scanf("%d",&N);
        for(int i=0;i<N;i++){
            scanf(" %s",linha[i]);
            tam[i]=strlen(linha[i]);
        }

        bool passo=true;

        //consistencia das string

        for(int i=0;i<N;i++){
            memset(visitados,0,sizeof visitados);
            visitados[linha[i][0]-'a']=1;
            for(int j=1;j<tam[i];j++){
                if(linha[i][j]==linha[i][j-1]){
                    continue;
                }

                if(visitados[linha[i][j]-'a']){
                    passo=false;
                    break;
                }
                visitados[linha[i][j]-'a']=1;
            }
        }

        if(!passo){
            printf("0\n");
            continue;
        }

        for(int i=0;i<N;i++)
            heap[i].clear();

        //caracteres dentro que deviam estar junto
        for(int i=0;i<N;i++){
            for(int j=1;j<tam[i]-1;j++){
                if(linha[i][j] == linha[i][0]) continue;
                if(linha[i][j] == linha[i][tam[i]-1]) continue;
                heap[i].insert(linha[i][j]);
            }
        }

        passo=true;

        for(int i=0;i<N;i++){
            for(set<char>::iterator it=heap[i].begin();it!=heap[i].end();it++){
               // printf("ii:%d , c:%c\n",i,*it);
                for(int j=0;j<N;j++){
                    if(i == j) continue;
                    if(*it == linha[j][0] || *it == linha[j][tam[j]-1]){
                        passo=false;
                        break;
                    }
                    if(heap[j].find(*it)!=heap[j].end()){
                        passo=false;
                        break;
                    }
                }
                if(!passo) break;
            }
        }

        if(!passo){
            printf("0\n");
            continue;
        }


        for(int i=0;i<N;i++){
            v[i].first=linha[i][0];
            v[i].second=linha[i][tam[i]-1];
        }

        memset(matriz,0,sizeof matriz);
        memset(visitados,0,sizeof visitados);
        for(int i=0;i<N;i++){
            lista[i].clear();
            listaR[i].clear();
        }

        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if(v[i].second == v[j].first){
                    lista[i].push_back(j);
                    listaR[j].push_back(i);
                    matriz[i][j]=matriz[j][i]=1;
                }
            }
        }


        for(int i=0;i<N;i++){
            if(!visitados[i]){
                dfs(i);
            }
        }


        int comp=1;

        ll resp=1;
        memset(visitados,0,sizeof visitados);
        while(!pilha.empty()){
            int atual=pilha.top();
//            printf("atual:%d\n",atual);
            pilha.pop();
            tamC=0;
            if(!visitados[atual]){
                dfs2(atual,comp++);
                resp=(resp*fat[tamC])%MOD;
            }
        }

        memset(visitados,0,sizeof visitados);

        int cont=0;
        for(int i=0;i<N;i++){
            if(!visitados[i]){
                dfs3(i);
                cont++;
            }
        }

        resp=(resp*fat[cont])%MOD;

        cout << resp << endl;

    }

    return 0;
}
