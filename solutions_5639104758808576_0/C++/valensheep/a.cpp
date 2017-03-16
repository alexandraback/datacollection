#include <stdio.h>
#include <algorithm>
#include <cstring>
using namespace std;

char s[2000];

int main(){
        int tt, ca = 0;
        scanf("%d",&tt);
        while (tt--){
                int n;
                scanf("%d",&n);
                scanf("%s",s);
                int sum = 0;
                int ans = 0;
                for (int i = 0;i <= n;i ++){
                        int t = s[i] - '0';
                        if (sum >= i) sum += t;
                        else {
                                ans += i - sum;
                                sum += t + (i - sum);
                        }
                }
                printf("Case #%d: %d\n", ++ca, ans);
        }
}
