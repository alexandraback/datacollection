#include <cstdio>
#include <cstring>
#include <string>
#include <map>
#include <vector>
#include <queue>
#include <algorithm>

#define MAX 110

using namespace std;

char linha[MAX];
int n,t;

int isVowel(char a){
    if(a == 'a') return 1;
    if(a == 'e') return 1;
    if(a == 'i') return 1;
    if(a == 'o') return 1;
    if(a == 'u') return 1;
    return 0;
}

int main(){

    freopen("A.in","r",stdin);
    freopen("A.out","w",stdout);

    scanf("%d",&t);

    for(int caso=1;caso<=t;caso++){

        scanf(" %s %d",linha,&n);

        int tam=strlen(linha);

        int resp=0;

        for(int i=0;i<tam;i++){
            int cont=0;
            for(int j=i;j<tam;j++){
                if( isVowel(linha[j])  ){
                    cont=0;
                }else{
                    cont++;
                    if(cont>=n){
                        resp+=(tam-j);
                        break;
                    }
                }
            }
        }

        printf("Case #%d: %d\n",caso,resp);

    }

    return 0;
}
