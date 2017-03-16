#include <iostream>
#include <cstdio>
#include <queue>
#include <cmath>
using namespace std;


int arr[1010];
int main()
{
    #ifdef CODEBLOCKS
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif // CODEBLOCKS

    int t;
    scanf("%d",&t);

    for(int ti=1;ti<=t;ti++)
    {
        int d;
        scanf("%d",&d);
        int a=0;

        for(int i=0;i<d;i++)
        {
            int tmp;
            scanf("%d",&arr[i]);
            a=max(arr[i],a);
        }

        int ans=a;
        a--;
        while(a>0)
        {
            int cnt=0;
            for(int i=0;i<d;i++)
            {
                cnt+=(arr[i]-1)/a;
            }
            ans=min(ans,cnt+a);
            a--;
        }
        cout<<"Case #"<<ti<<": "<<ans<<endl;
    }
    return 0;
}
