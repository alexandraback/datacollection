#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;


int main()
{
    freopen("B-small-attempt0.in","r",stdin);
    freopen("B-small-attempt0.out","w",stdout);
    int T,it,A,B,K,i,j,x;
    scanf("%d",&T);
    for(it=1; it<=T; it++)
    {
        scanf("%d%d%d",&A,&B,&K);
        int cnt=0;
        for(i=0; i<A; i++)
        {
            for(j=0; j<B; j++)
            {
               x=(i&j);
               if(x<K)  cnt++;
            }
        }
        printf("Case #%d: %d\n",it,cnt);
    }
    return 0;
}
