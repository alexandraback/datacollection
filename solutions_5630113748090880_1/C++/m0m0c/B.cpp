#include<bits/stdc++.h>
using namespace std;

const int N  = 2600;
int cnt[N];

int main(){
        freopen("A-large.in", "r", stdin);
    freopen("large.out", "w", stdout);
    int TC, tc;
    scanf("%d", &TC);
    for(tc = 1; tc<= TC; tc++){
        int n;
        int x;
        scanf("%d", &n);
        vector<int>ans;
        int m = 2 * n - 1;
        memset(cnt, 0, sizeof(cnt));
        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                scanf("%d", &x);
                cnt[x] ++;
            }
        }
        for(int i = 1; i <= 2500; i++){
            if(cnt[i] & 1){
                ans.push_back(i);
            }
        }
        printf("Case #%d:", tc);
        for(int i = 0; i < ans.size(); i++){
            printf(" %d", ans[i]);
        }
        printf("\n");

    }
return 0;
}
