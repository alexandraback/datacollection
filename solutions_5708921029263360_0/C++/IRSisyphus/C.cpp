#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int T;

int main(){
    freopen("small.in", "r", stdin);
    freopen("small.out", "w", stdout);
    scanf("%d\n", &T);
    for (int t = 1; t <= T; ++t){
        printf("Case #%d: ", t);
        int clothes[3]; int limit;
        scanf("%d %d %d %d", &clothes[0], &clothes[1], &clothes[2],&limit);
        int temp1 = clothes[0], temp2 = clothes[1], temp3 = clothes[2];
        sort(clothes, clothes+3);
        int small = -1, mid = -1, large = -1;
        if (temp1 == clothes[0]) small = 0;
        else if (temp2 == clothes[0]) small = 1;
        else small = 2;

        if (temp1 == clothes[1] && small!= 0) mid = 0;
        else if (temp2 == clothes[1] && small!= 1) mid = 1;
        else mid = 2;

        if (temp1 == clothes[2] && small!= 0 && mid!= 0) large = 0;
        else if (temp2 == clothes[2] && small!= 1 && mid!= 1) large = 1;
        else large = 2;
        clothes[0] = temp1, clothes[1] = temp2, clothes[2] = temp3;

        if (clothes[large] == 1){
            printf("1\n1 1 1\n"); continue;
        }

        int total = clothes[small] * clothes[mid] * limit;
        total = min(total, clothes[small] * clothes[mid] * clothes[large]);
        limit = total/(clothes[small] * clothes[mid]);
        printf("%d\n", total);
        int localmark = 0;
        int output[3];
        for (int i = 1; i <= limit; ++i){
            for (int j = 1; j <= clothes[small]; ++j){
                for (int k = 1; k <= clothes[mid]; ++k){
                    output[small] = j;
                    output[mid] = k;
                    if ((k + localmark)%clothes[large] == 0) output[large] = clothes[large];
                    else output[large] = (k + localmark)%clothes[large];
                    printf("%d %d %d\n", output[0], output[1], output[2]);
                }
                localmark = (localmark+1)%clothes[large];
            }
            localmark = i%clothes[large];
        }
    }
}
