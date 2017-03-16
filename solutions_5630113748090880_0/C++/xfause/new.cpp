#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<iostream>
#include<queue>
#include<vector>
#include<set>
#include<stack>
#include<map>
#include<ctime>
#include<bitset>
#define LL long  long
#define db double
#define EPS 1e-15
#define inf 1e9

using namespace std;

int num[2510],ans[2510],a[55][500];
int main(){
    freopen ("1.in", "r", stdin);
    freopen ("1.out", "w", stdout);
    int T,cas=1;
    scanf("%d",&T);
    while (T--){
        int n,cnt=0,x;
        scanf("%d",&n);
        memset(num,0,sizeof(num));
        for (int i=1;i<=n;i++){
            for (int j=1;j<=2*n-1;j++){
                scanf("%d",&a[i][j]);
                num[a[i][j]]++;
                cnt++;
            }
        }
        printf("Case #%d: ",cas++);
        int len=n*(2*n-1),cnt1=0;
        for (int i=0;i<=2500;i++){
            if (num[i]%2==1) printf("%d ",i);
        }
        puts("");
    }
    return 0;
}
