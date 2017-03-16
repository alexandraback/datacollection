//In the name of Allah

#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
#include <bitset>
#include <math.h>
#include <queue>
#include <map>
#include <set>
#include <limits.h>
#include <limits>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include <assert.h>
using namespace std;

int T, cnt;
long long C, D, V, X[105];

int main(){
    freopen("C.txt", "r", stdin);
    freopen("Cout.txt", "w", stdout);
    
    scanf("%d", &T);
    while(T--){
        scanf("%d %d %d", &C, &D, &V);
        for(int i = 0; i < D; i++)
            scanf("%d", &X[i]);
        sort(X, X + D);
        
        int res = 0;
        long long Y = 0;
        for(int i = 0; i < D; i++){
            while((V > Y) && (X[i] > Y + 1)){
                res++;
                Y += (Y + 1) * C;
            }
            if(V <= Y)break;
            if(X[i] <= Y + 1){
                Y += X[i] * C;
            }
        }
        while(V > Y){
            res++;
            Y += (Y + 1) * C;
        }

        printf("Case #%d: %d\n", ++cnt, res);
    }
    return 0;
}