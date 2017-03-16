#include <iostream>
#include <cstdio>
#include <stack>
#include <cstring>
#include <queue>
#include <algorithm>
#include <cmath>
//#include <unordered_map>
//#define lson x<<1
//#define rson x<<1|1
//#define mid ((lt[x].l+lt[x].r)/2)
//#define ID(x, y) ((x)*m+(y))
//#define CHECK(x, y) ((x)>=0 && (x)<n && (y)>=0 && (y)<m)
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int INF=0x3f3f3f3f;
void Open()
{
    #ifndef ONLINE_JUDGE
        freopen("A-large.in","r",stdin);
        freopen("A-large.out","w",stdout);
    #endif // ONLINE_JUDGE
}
char str[1111];
char ans[2111];
int main()
{
//    Open();
    int T;scanf("%d", &T);
    int cas = 1;
    while(T--)
    {
        scanf("%s", str);
        int len = strlen(str);
        int l = 1000, r = 1000;
        for(int i = 0; i < len; i++)
        {
            if(l >= r) {
                ans[r++] = str[i];
            }else if(str[i] >= ans[l]){
                ans[--l] = str[i];
            }else {
                ans[r++] = str[i];
            }
        }
        ans[r] = '\0';
        printf("Case #%d: %s\n", cas++, ans+l);
    }
    return 0;
}
