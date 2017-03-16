#include <cstdio>
#include <cstring>
#include <string>
#include <map>
#include <vector>
#include <queue>
#include <algorithm>

#define MAX 1000100

using namespace std;

typedef long long int ll;

char linha[MAX];
int n,t;
ll pd[MAX];
int pre[MAX];

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

        pd[tam]=0;
        pre[tam]=0;
        pd[tam+1]=0;
        pre[tam+1]=0;

        for(int i=tam-1;i>=0;i--){

            if(isVowel(linha[i])){
                pre[i]=0;
                pd[i]=2*pd[i+1]-pd[i+2];
            }else{
                pre[i]=pre[i+1]+1;
                if(pre[i] >= n){
                    pd[i]=pd[i+1]+tam-i-n+1;
                }else{
                    pd[i]=2*pd[i+1]-pd[i+2];
                }
            }

        }


        printf("Case #%d: %I64d\n",caso,pd[0]);

    }

    return 0;
}
