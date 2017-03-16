/* *************************
 * Author: xg1990
 * Created Time:  
 * LastModified:  Sat 14 Apr 2012 11:18:22 AM CST
 * C File Name: 
 * ************************/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;


int main() {
    freopen("B-small-attempt0.in","r",stdin);
    freopen("B-small-attempt0.out","w",stdout);
    int T;
    scanf("%d", &T);
    for(int t = 0; t < T; ++t){
        int N, S, p;
        int a, ans = 0;
        scanf("%d %d %d", &N, &S, &p);
        int s1 = p + max(0, p - 1) * 2;
        int s2 = p + max(0, p - 2) * 2;
        for(int i = 0;i < N; ++i){
            scanf("%d", &a);
            if(a >= s1)
                ans ++;
            else if(a >= s2 && S > 0){
                ans ++;
                S --;
            }
        }
        printf("Case #%d: %d\n", t + 1, ans);
    }
    return 0;
}


