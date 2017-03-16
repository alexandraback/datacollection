#include <bits/stdc++.h>
using namespace std;

int pcakes[1001];

int main()
{
    freopen("B-large.in","r",stdin);
    freopen("B.out","w",stdout);
    int T;
    cin >> T;
    for (int qq=0;qq<T;qq++)
    {
        memset(pcakes,0,sizeof(pcakes));
        int D;
        int ans = 1000000;
        cin >> D;
        for (int i=0;i<D;i++)
        {
            cin >> pcakes[i];
        }
        for (int p=1;p<=1000;p++)
        {
            int cnt = 0;
            for (int i=0;i<D;i++)
            {
                cnt += (pcakes[i]-1)/p;
            }
            ans = min(ans,cnt + p);
        }
        printf("Case #%d: %d\n",qq+1,ans);
    }
}
