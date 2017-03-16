#include<cstdio>
#include<algorithm>
#include<cmath>
#include<map>
using namespace std;
int main()
{
    freopen("C-small-attempt0.in","r",stdin);
    freopen("out.txt","w",stdout);
    int t,a[25],s1[25],s2[25],sum,T,N,m2;
    map<int,int> pos;
    scanf("%d",&T);
    for(int t=1;t<=T;t++)
    {
        pos.clear();
        scanf("%d",&N);
        for (int i=0;i<N;i++)   scanf("%d",&a[i]);
        bool flag=0;
        for (int i=1;i<(1<<N);i++)
        {
            sum=0;
            for (int j=0;j<N;j++)
            {
                if ( (i & (1<<j)) )
                    sum+=a[j];
            }
            if (pos.find(sum)!=pos.end())
            {
                m2 = pos[sum];
                //printf("%d\n",m2);
                //if (!(m2 & i))
                {
                    flag=1;
                    for (int j=0;j<N;j++)
                    {
                        if( (i & (1<<j)) ) s1[j]=1;
                        else s1[j]=0;
                        if( (m2 & (1<<j))) s2[j]=1;
                        else s2[j]=0;
                    }
                    break;
                }
            }
            else
                pos[sum]=i;
        }
        if (!flag)
            printf("Case #%d: Impossible\n",t);
        else
        {
            printf("Case #%d:\n",t);
            for (int i=0;i<N;i++)
            {
                if (s1[i]==1)printf("%d ",a[i]);
            }
            printf("\n");
            for (int i=0;i<N;i++)
            {
                if (s2[i]==1)printf("%d ",a[i]);
            }
            printf("\n");
        }
    }
    return 0;
}


