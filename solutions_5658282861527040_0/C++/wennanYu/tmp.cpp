#include <iostream>
#include <vector>
#include <cstring>
#include <cstdio>
#include <map>
#include <cmath>
#include <algorithm>
#include <set>

using namespace std;

int A, B, K, ans, cas, T;

int main(){
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    scanf("%d", &T);
    while (T--){
        ans = 0;
        scanf("%d%d%d", &A, &B, &K);
        for (int i=0;i<A;++i){
            for (int j=0;j<B;++j){
                if ((i&j)<K) ans++;
            }
        }
        printf("Case #%d: %d\n", ++cas, ans);
    }
}
