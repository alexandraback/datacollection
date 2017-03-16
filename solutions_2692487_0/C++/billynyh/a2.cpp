#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <vector>
#include <string>
#include <queue>
#include <iostream>
using namespace std;

bool fless(double a,double b){ return b-a>1e-6; }
bool fequal(double a,double b){ return fabs(b-a)<=1e-6; }

int main(){
    int tt; scanf("%d",&tt);
    for (int ti=1;ti<=tt;ti++){
        int A, n;
        scanf("%d%d", &A, &n);

        int a[n+1];

        for (int i=0;i<n;i++){
            scanf("%d", &a[i]);
        }
        sort(a, a+n);
        
        int curr = A;
        
        int i = 0;
        int step = 0;
        int ans = n;
        while (i<n) {
            if (curr > a[i]){
                curr += a[i];
                i++;
            } else {
                if (curr > 1){
                    ans = min(ans, step + n-i);
                    curr += curr - 1;
                    step++;
                } else {
                    break;
                }
            }
        }

        if (i==n){
            ans = min(ans, step);
        }


        printf("Case #%d: %d\n",ti,ans);
    }
    return 0;
}

