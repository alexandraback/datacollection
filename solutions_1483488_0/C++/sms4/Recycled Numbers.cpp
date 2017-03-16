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
#include <vector>

using namespace std;

vector<int> adj[2000001];

int main(){

    freopen("a.txt", "r", stdin);
    freopen("b.txt", "w", stdout);
    int t, a, b,caso;
    caso = 1;
    scanf("%d", &t);
    while(t--){
        scanf("%d%d", &a, &b);
        int temp, mult, div, resto, maxi, contador;
        contador = 0;
        for(int i =0;i<2000001;i++){
            adj[i].clear();
        }
        while(a < b){
            mult = 10;
            maxi = 10;
            while(maxi*10 <= a){
                maxi *= 10;
            }
            int ant = 0;
            bool repetido;
            while(mult <= a){
                div = a/mult;
                resto = a%mult;
                temp = resto*maxi + div;
                if(temp > a && temp <= b){
                    vector<int> &v = adj[a];
                    repetido = false;
                    for(int j=0;j<v.size();j++){
                        if(temp == v[j]){
                            repetido = true;
                        }
                    }
                    if(!repetido){
                        adj[a].push_back(temp);
                        contador++;
                    }
                }
                mult *=10;
                maxi /=10;
            }
            a++;
        }
        printf("Case #%d: %d\n",caso++, contador);
    }


    return 0;
}
