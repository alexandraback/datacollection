#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

bool cmp(int a,int b)
{
     return (a>b)?true:false;
}
int main()
{
    freopen("B-small-attempt1.in","r",stdin);
    freopen("B_output_small.txt","w",stdout);
    int T,D;
    int p[1000],c[1001],result;
    scanf("%d",&T);
    for (int index=1;index<=T;index++)
    {
        scanf("%d",&D);
        result = 0;
        memset(c,0,sizeof(c));
        for (int i=0;i<D;i++)
        {
            scanf("%d",&p[i]);
            result = max(result,p[i]);
            c[p[i]]++;
        }
        int N=result;
        for (int i=N-1;i>0;i--)
        {
            int counter=0;
            for (int j=0;j<D;j++)
            {
                if (p[j]%i>0) counter+=p[j]/i;
                else counter+=p[j]/i-1;
            }   
            result=min(result,counter+i);
        }
        printf("Case #%d: %d\n",index,result);
    }
    return 0;
}
