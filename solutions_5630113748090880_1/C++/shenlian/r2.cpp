#include <iostream>
#include <string.h>
#include <stdio.h>
#include <vector>
#include <map>
#include <limits.h>
#include <stdlib.h>
#include <algorithm>
#include <set>
#include <stack>
using namespace std;
const int NUM = 2500 + 5;
int h[NUM];
int main(){
    int T;
    scanf("%d",&T);
    for(int _i = 1 ; _i <= T  ; _i++){
        int N;
        memset(h,0,sizeof(h));
        scanf("%d",&N);
        int ans[N],c;
        for(int i = 1 ; i <= 2*N - 1; i++){
            for(int j = 0 ; j < N ; j ++){
                scanf("%d",&c);
                h[c]++;
            }
        }
        int j = 0;
        for(int i = 0 ; i <= NUM ; i++){
            if(h[i] % 2 == 1) ans[j++] = i;
        }
        sort(ans,ans+N);
        printf("Case #%d:",_i);
        for(int i = 0 ; i < N ; i++) printf(" %d",ans[i]);
        printf("\n");
        
    }
    return 0;
}