#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <cmath>
using namespace std;

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int t;
    scanf("%d",&t);
    for(int cc=0;cc<t;cc++)
    {
        int n;
        scanf("%d",&n);
        vector<int> cake;
        cake.resize(n);
        int maxcake=0;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&cake[i]);
            if(maxcake<cake[i]) maxcake=cake[i];
        }

        int ans=maxcake;
        for(int i=1;i<=maxcake;i++)
        {
            int cnt=i;
            for(int j=0;j<n;j++)
            {
                cnt+=(int)ceil((double)cake[j]/i)-1;
            }
            if(cnt<ans)
                ans=cnt;
        }
        printf("Case #%d: %d\n",cc+1,ans);
    }
    return 0;
}
