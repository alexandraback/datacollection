#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <stack>
#include <queue>
#include <bitset>
#include <map>
#include <vector>
#include <cstdlib>
#include <set>
using namespace std;
#define LL long long
#define B 240
#define eps 1e-8
#define MP make_pair
#define Pi acos(-1.0)
#pragma comment(linker, "/STACK:1024000000,1024000000")
#define inf 0x3f3f3f3f
#define ls (o << 1)
#define rs (2*o + 1)
#define md ((ll + rr) >> 1)
#define lson ll, md, ls
#define rson md + 1, rr, rs
#define MOD 998244353
const int N = 1e3+20;
char str[N],ans[N];
bool is[2*N];

int main()
{
    freopen("A-large (1).in","r",stdin);
    freopen("A-large (1).out","w",stdout);
    int t,cnt = 1;
    scanf("%d",&t);
    while(t--){
        scanf("%s",str);
        int n = strlen(str);
        int ss = n,ee=n+1;
        memset(ans,0,sizeof(ans));
        ans[ss] = str[0];

        for(int i=1;i<n;i++){
            ans[ss-1] = str[i];
            if(strcmp(ans+ss-1,ans+ss)>0)
                    ss--;
            else ans[ee++] = str[i];
        }
        printf("Case #%d: ",cnt++);
        for(int i=ss;i<ee;i++)
            printf("%c",ans[i]);
        printf("\n");
    }
    return 0;
}
