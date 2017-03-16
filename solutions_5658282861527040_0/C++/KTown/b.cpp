#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <map>
#include <vector>
#include <thread>
#include <stdint.h>

using namespace std;

int B, A, K;
int main(){
    int T;
    scanf("%d", &T);
    for(int t=0; t++<T;){
        scanf("%d%d%d", &A, &B, &K);
        int ret = 0;
        for(int i = 0; i<A;i++){
            for(int j = 0; j<B;j++){
                if((i&j) < K)
                    ret++;
            }
        }
        printf("Case #%d: %d\n", t, ret);
    }
}
