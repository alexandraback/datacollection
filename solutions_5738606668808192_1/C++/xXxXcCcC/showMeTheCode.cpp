#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int> pr;

const int maxn = 100005;


void solve(){
    int N,J;
    scanf("%d %d",&N,&J);
    for (int i=0;i<500;i++){
        printf("11");
        for (int j=0;j<14;j++){
            if (i&(1<<j)) printf("11");
            else printf("00");
        }
        printf("11");
        for (int j=2;j<=10;j++)
            printf(" %d",j+1);
        printf("\n");
    }
}

int main(){
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    int T;
    scanf("%d",&T);
    for (int kase=1;kase<=T;kase++){
        printf("Case #%d:\n",kase);
        solve();
    }
    return 0;
}
