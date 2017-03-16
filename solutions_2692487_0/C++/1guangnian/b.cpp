#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<stack>
#include<queue>
#include<vector>
#include<map>
#include<ctime>
#include<set>
#include<string>
using namespace std;
const int MAX=1005;
const long long inf=(1LL<<40);
#define ll long long
#define PB push_back
#define PII pair<int,int>
#define MP(x,y) make_pair(x,y)
int a[MAX],n,cur;
void update(ll &x, ll y)
{
    if(x<y)
        x=y;
}
ll dp[105][105][105];
int main()
{
    freopen("A-small.in","r",stdin);
    freopen("out.txt","w",stdout);
    int i,j,k,T;
    scanf("%d",&T);
    for(int cas=1;cas<=T;cas++)
    {
        scanf("%d%d",&cur,&n);
        //cout<<"cur="<<cur<<" n="<<n<<endl;
        for(i=1;i<=n;i++)
            scanf("%d",&a[i]);
        sort(a+1,a+n+1);
        /*for(i=1;i<=n;i++)
            printf("%d ",a[i]);
        cout<<endl;*/
        int res = n;
        for(i = 0;i <= n;i++)
        {
            ll now = (ll)cur;
            bool flag = true;
            int cnt = 0;
            for(j=1;j<=n-i;j++)
            {
                while(now<=a[j])
                {
                    if(now == 1)
                    {
                        flag=false;
                        break;
                    }
                    cnt++;
                    now = now*2-1;
                }
                now += a[j];
                //cout<<"i="<<i<<" j="<<j<<" cnt="<<cnt<<" now="<<now<<endl;
            }
            if(flag)
                res = min(res,cnt+i);
        }

        printf("Case #%d: %d\n",cas,res);
    }
    return 0;
}
