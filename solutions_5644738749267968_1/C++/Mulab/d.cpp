#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

const int N = 1011;
int n;
bool used[N];
double ken[N], naomi[N];

int play1(){
    for(int i = n; i >= 1; i--){
        bool good = true;
        for(int j = 1; j <= i; j++)
            if(ken[j] > naomi[j + n - i]){
                good = false;
                break;
            }
        if(good)
            return i;
    }
    return 0;
}

int play2(){
    int ans = 0;
    memset(used, 0, sizeof(used));
    for(int i = 1; i <= n; i++){
        bool good = false;
        for(int j = 1; j <= n; j++)
            if(!used[j] && ken[j] > naomi[i]){
                used[j] = true;
                good = true;
                break;
            }
        if(good)
            continue;
        ans++;
        for(int j = 1; j <= n; j++)
            if(!used[j]){
                used[j] = true;
                break;
            }
    }
    return ans;
}

void solve(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        scanf("%lf", naomi + i);
    for(int i = 1; i <= n; i++)
        scanf("%lf", ken + i);
    std::sort(ken + 1, ken + n + 1);
    std::sort(naomi + 1, naomi + n + 1);
    printf("%d %d\n", play1(), play2());
}

int main(){
    int T;
    scanf("%d", &T);
    for(int i = 1; i <= T; i++){
        printf("Case #%d: ", i);
        solve();
    }
    return 0;
}

