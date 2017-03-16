#include <iostream>
#include <cstdio>
#include <stack>
#include <cstring>
#include <queue>
#include <algorithm>
#include <cmath>
//#include <unordered_map>
#define N 1010
using namespace std;
typedef pair<int,int> PII;
const int INF=0x3f3f3f3f;
void Open()
{
    //#ifndef ONLINE_JUDGE
        freopen("B-small-attempt2.in","r",stdin);
        freopen("B-small-attempt2.out","w",stdout);
    //#endif // ONLINE_JUDGE
}
int num[N];
int main()
{
    Open();
    int T;
    scanf("%d",&T);
    int cas=1;
    while(T--)
    {
        int n;
        scanf("%d",&n);
        int ans=0;
        for(int i=0;i<n;i++)
        {
            int tmp;
            scanf("%d",&tmp);
            num[i]=tmp;
            ans=max(ans,tmp);
        }
        for(int x=2;x<ans;x++)
        {
            int sum=0;
            for(int i=0;i<n;i++)
            {
                sum+=(num[i]-1)/x;
            }
            ans=min(ans,sum+x);
        }
        printf("Case #%d: %d\n",cas++,ans);
        //cout<<endl;
    }
    return 0;
}
