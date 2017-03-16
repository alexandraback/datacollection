#include <cstdio>
#include <algorithm>
#include <climits>
using namespace std;
int self;
int n;
int a[102];
void solve(int tc)
{
    scanf("%d%d",&self,&n);
    for (int i = 1 ; i <= n; ++i)
        scanf("%d",&a[i]);
    sort(&a[1],&a[n] + 1);
    int ans = n;
    int sub_ans = 0;
    if (self >= 2)
    {
        for (int i = 1; i <= n ; ++i)
        {
            if (self > a[i]) self += a[i];
            else
            {
                while (self <= a[i])
                {
                    self += self - 1;
                    ++sub_ans;
                }
                self += a[i];
            }
            ans = min(ans , sub_ans + n - i);
        }
    }
    else ans = n;
    printf("Case #%d: %d\n",tc,ans);
}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int t = 0;
    scanf("%d",&t);
    for (int i = 1 ; i <= t ; ++i)
        solve(i);
    return 0;
}
