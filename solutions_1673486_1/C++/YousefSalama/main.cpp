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
double p[100005];
int main(){
    freopen("A-large.in", "r", stdin);
    freopen("a.out", "w", stdout);
    cin >> T;
    while(T--){
        cin >> A >> B;
        for(int i = 0; i < A; i++)
            cin >> p[i];

        double ans = B + 2, prob = 1;
        for(int i = 0; i <= A; i++){
            int j = A - i;
            double cur = prob * (B - i + 1 + j) + (1.0 - prob) * (B - i + 1 + B + 1 + j);
            ans = min(ans, cur);

            if(i < A)prob *= p[i];
        }

        printf("Case #%d: %.6f\n", Cases++, ans);
    }
    return 0;
}