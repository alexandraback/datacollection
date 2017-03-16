#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <queue>
#include <iostream>
using namespace std;

const int INF = 0x3f3f3f3f;
int a[2000];
int n;

int main(){
        int tt, ca = 0;
        scanf("%d",&tt);
        while (tt--){
                scanf("%d",&n);
                for (int i = 0;i < n;i ++) {
                        scanf("%d",&a[i]);
                }
                int ans = INF;
                for (int i = 1;i <= 1500;i ++){
                        int cnt = 0;
                        for (int j = 0;j < n;j ++) cnt += (a[j] - 1) / i;
                        ans = min(ans, cnt + i);
                        if (cnt == 0) break;
                }
                printf("Case #%d: %d\n", ++ca, ans);
        }
}
