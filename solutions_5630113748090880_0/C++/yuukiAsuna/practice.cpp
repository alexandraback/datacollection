#include <bits/stdc++.h>
#define PB push_back
#define FT first
#define SD second
#define MP make_pair
#define INF 0x3f3f3f3f
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int,int>  P;
const int N = 55,MOD = 7+1e9;
int a[2505], ans[N];
int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int T, ca = 0;
    scanf("%d", &T);
    while(T --)
    {
        int n;
        scanf("%d", &n);
        memset(a, 0, sizeof(a));
        for(int i = 0;i < 2 * n - 1;i ++) {
            for(int j = 0;j < n;j ++) {
                int x;
                scanf("%d", &x);
                a[x] ++;
            }
        }
        int cnt = 0;
        for(int i = 1;i <= 2500;i ++) if(a[i]&1) ans[cnt ++] = i;
        printf("Case #%d:", ++ca);
        for(int i = 0;i < cnt;i ++) printf(" %d", ans[i]);
        printf("\n");
    }
    return 0;
}