#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int txt = 1;
void solve(){
    int r,c,w;
    scanf("%d%d%d",&r,&c,&w);
    int res = 0;
    res += (r - 1) * c / w;
    while(c >= 2 * w) c -= w,res ++;
    res += min(w + 1,c);
    printf("Case #%d: %d\n",txt ++,res);
}
int main()
{
    freopen("A-large.in","r",stdin);
    freopen("data.out","w",stdout);
    int _;
    scanf("%d",&_);
    while(_--) solve();
    return 0;
}
