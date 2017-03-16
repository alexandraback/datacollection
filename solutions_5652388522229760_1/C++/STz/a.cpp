#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <bitset>
using namespace std;
#define N 111111
#define M 222222
#define md 1000000007
#define ll long long

bool q[10];

bool ck(int n){
    int m = n;
    while(m){ q[m%10]=true; m/=10; }
    for(int i=0;i<10;i++) if(!q[i]) return false;
    return true;
}
int main(){
    freopen("a.in","r",stdin);
    freopen("a.out","w",stdout);
    int t;
    scanf("%d",&t);
    for(int s=1;s<=t;s++){
        int n, ans;
        memset(q,0,sizeof q);
        scanf("%d",&n);
        printf("Case #%d: ",s);
        if(n == 0)
            printf("INSOMNIA\n");
        else {
            ans = 0;
            do { ans += n; } while (ck(ans) == false);
            printf("%d\n",ans);
        }
    }
}
