#include<cstdio>
#include<cstring>
using namespace std;
const int N = 10005;
int cnt[N];
int a[105][55];
void solve(){
    memset(cnt,0,sizeof(cnt));
    int n;
    scanf("%d",&n);
    for(int i = 0 ; i < 2 * n - 1 ; i ++)
    for(int j = 0 ; j < n ; j ++){
        scanf("%d",&a[i][j]);
        cnt[ a[i][j] ] ++;
    }
    for(int i = 0 ; i < N ; i ++)
        if(cnt[i] % 2) printf("%d ",i);
    printf("\n");
}
int main(){
    freopen("B-large.in","r",stdin);
    freopen("out.txt","w",stdout);
    int _,txt = 1;
    scanf("%d",&_);
    while(_--){
        printf("Case #%d: ",txt ++);
        solve();
    }
    return 0;
}
