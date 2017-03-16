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
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <sstream>
using namespace std;
int T, A, B, Cases = 1;
double p[5];
int main(){
    freopen("a.out", "w", stdout);
    cin >> T;
    while(T--){
        cin >> A >> B;
        for(int i = 0; i < A; i++)
            cin >> p[i];

        double ans = 1000000000;
        for(int opr = 0; opr <= A + 1; opr++){
            double total = 0;
            for(int mask = 0; mask < (1 << A); mask++){
                int cur = 0, idx = -1;
                double prob = 1.0;

                for(int i = 0; i < A; i++)
                    if(mask & (1 << i)){

                        prob *= p[i];
                    }else{
                        prob *= 1 - p[i];
                        if(idx == -1)idx = i;
                    }

                 if(opr == 0){
                    cur = B - A + 1;
                    if(idx != -1)cur += B + 1;
                }else if(opr <= A){
                    cur = opr + B - (A - opr) + 1;

                    if(idx != -1 && idx < A - opr)cur += B + 1;
                }else{
                    cur = 1 + B + 1;
                }

                total += cur * prob;
            }
            ans = min(ans, total);
        }
        printf("Case #%d: %.6f\n", Cases++, ans);
    }
    return 0;
}