#include <iostream>
#include <math.h>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <map>
#include <string.h>
using namespace std;

#define OK puts("OK")
typedef int ll;
const int N = 2000000;
int a[11];
int p[10] = {1,10,100,1000,10000,100000,1000000,10000000};
int A,B;
int gao(int x){
    int ans = 0;
    int n,i;
    int tmp = 0;
    int t = x;
    while(t){
        tmp ++;
        t /= 10;
    }
//    printf("%d: ",x);
    for(i = 1; i < tmp; i++){
        a[i] = x/p[i] + p[tmp-i]*(x%p[i]);
//        printf(" %d",a[i]);
    }
//    printf("\n");
    sort(a+1,a+tmp);
    n = unique(a+1,a+tmp) - (a+1);
    for(i = 1; i <= n; i++){
        if(a[i] > x && a[i] <= B){
            ans++;
//            printf("%d\n",ans);
        }
    }
    return ans;
}
int solve(){
    int ans = 0;
    for(int i = A; i <= B; i++){
        ans += gao(i);
//        printf("%d\n",ans);
    }
    return ans;
}
int main() {
    freopen("C-large.in", "r", stdin);
    freopen("CL.out", "w", stdout);
//    freopen("in", "r", stdin);
//    freopen("out", "w", stdout);
    int t;
    scanf("%d", &t);
    for (int cas = 1; cas <= t; cas++) {
        scanf("%d%d",&A,&B);
        printf("Case #%d: %d\n",cas,solve());
    }
}