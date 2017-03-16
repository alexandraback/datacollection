#include<cstdio>
#include<string>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<iostream>
#include <stdio.h>
using namespace std;
#define N 2000005
#define INF 1000000009
typedef long long LL;
int n;
double a[1005];
double b[1005];
int main(){
    int t;
    freopen("D-small-attempt3.in","r",stdin);
    freopen("opD.out","w",stdout);
    scanf("%d", &t);
    int num = 1;
    while(t--){
        scanf("%d", &n);
        for(int i = 0; i < n; i++){
            scanf("%lf", &a[i]);
        }
        for(int i = 0; i < n; i++){
            scanf("%lf", &b[i]);
        }
        sort(a, a + n);
        sort(b, b + n);
        int ans0 = 0;
        for(int i = 0, j = 0; i < n && j < n;){
            if(a[i] > b[j]){
                ans0++;
                i++;
                j++;
            }
            else i++;
        }
        int ans1 = 0;
        for(int i = 0; i < n; i++){
            int f = 0;
            for(int j = 0; j < n; j++){
                if(b[j] > a[i]){
                    b[j] = 0;
                    f = 1;
                    break;
                }
            }
            if(f == 0)break;
            else ans1++;
        }
        printf("Case #%d: ", num++);
        printf("%d %d\n", ans0, n - ans1);
    }
    return 0;
}
