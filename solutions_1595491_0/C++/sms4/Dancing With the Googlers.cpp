#include <iostream>
#include <cstdio>
#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <cstring>
#include <string.h>
#include <string>
#include <cstdlib>
#include <stdlib.h>
#include <list>

using namespace std;

int val[101];
int num[3];

int main(){

    freopen("a.txt", "r", stdin);
    freopen("b.txt", "w", stdout);
    int t, n, s, p, resp, div, resto, caso;
    int contador;
    caso = 1;
    scanf("%d", &t);
    while(t--){
        scanf("%d%d%d", &n,&s,&p);
        for(int i=0;i<n;i++){
            scanf("%d", &val[i]);
        }
        contador = 0;
        for(int i=0;i<n;i++){
            div = val[i]/3;
            resto = val[i]%3;
            num[0] = div;
            num[1] = div;
            num[2] = div;
            if(resto){
                num[2]++;
            }
            if(num[2] >= p){
                contador++;
            }else if(s && resto != 1 && (num[2]+1) == p){
                if(resto == 2 || div ){
                    s--;
                    contador++;
                }
            }
        }
        printf("Case #%d: %d\n",caso++, contador);
    }
    return 0;
}
