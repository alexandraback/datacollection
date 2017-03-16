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
        freopen("B-small-attempt0.in","r",stdin);
        freopen("B-small-attempt0.out","w",stdout);
    #endif // ONLINE_JUDGE
}
int num[3333];
vector<int> ans;
int main()
{
//    Open();
    int T;scanf("%d", &T);
    int cas = 1;
    while(T--)
    {
        memset(num, 0, sizeof(num));
        ans.clear();
        int n;scanf("%d", &n);
        for(int i = 0; i < 2*n-1; i++)
        {
            for(int j = 0;j < n; j++)
            {
                int x;scanf("%d", &x);
                num[x]++;
            }
        }
        for(int i = 0; i < 2601; i++)
            if(num[i]&1) ans.push_back(i);
        sort(ans.begin(), ans.end());
        printf("Case #%d: ", cas++);
        for(int i = 0; i < n; i++)
            printf("%d%c", ans[i], " \n"[i == n-1]);
    }
    return 0;
}
