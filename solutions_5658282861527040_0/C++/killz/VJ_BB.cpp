#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<string>
#include<cstring>
#include<vector>
#include<cmath>
#include<iostream>

using namespace std;

int i, n, k, N, M, K;

int A, B, C;

int main(){
    freopen("B-small-attempt0 (1).in", "r", stdin);
    freopen("B-sm.out", "w", stdout);
int a, b, c, d;
int T, R;
string tp;
cin >> T;
R = T;
while(T--){
    scanf("%d %d %d", &A, &B, &C);
    k = 0;
    for(a=0;a<A;a++){
        for(b=0;b<B;b++){
            if((a&b) < C){
                k++;
            }
        }
    }
    printf("Case #%d: %d\n", R-T, k);
}

return 0;
}
