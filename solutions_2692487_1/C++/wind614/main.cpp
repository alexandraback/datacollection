#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
#define INF (1<<30)
const int N=105;
int a[N];
int main()
{
    freopen("A-large.in","r",stdin);
    freopen("out.txt","w",stdout);
    int t,t_cnt=0;
    scanf("%d",&t);
    while(t--)
    {
        int A,n;
        scanf("%d%d",&A,&n);
        for(int i=0;i<n;i++) scanf("%d",&a[i]);
        sort(a,a+n);

        printf("Case #%d: " ,++t_cnt);
        if(A==1)
        {
            printf("%d\n",n);
            continue;
        }
        int ans=n,tmp=A;
        for(int i=0;i<n;i++)
        {
            A=tmp;
            int cnt=(n-i-1);
            for(int j=0;j<=i;j++)
            {
                if(A>a[j])
                {
                    A+=a[j];
                }
                else
                {
                    while(A<=a[j]) A+=A-1,cnt++;
                    A+=a[j];
                }
            }
            ans=min(ans,cnt);
        }
        printf("%d\n",ans);
    }
	return 0;
}
