#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;

int t,n;
double judge[210];


int main()
{
    freopen("A-large.in","r",stdin);
    freopen("a-large-0.out","w",stdout);
    
    int i,j;
    scanf("%d",&t);
    int tt=1;
    while(t--)
    {
        scanf("%d",&n);
        double sum=0.0;
        for(i=0;i<n;i++)
        {
            scanf("%lf",&judge[i]);
            sum+=judge[i];
        }
        
        printf("Case #%d:",tt++);
        
        for(int k=0;k<n;k++)
        {
            
            
            double l=0.0,h=1.0,m;
            while((h-l)>=0.000000001)
            {
                m=(h+l)/2.0;
                double remain=1.0-m;
                double now=judge[k]+m*sum;
                for(i=0;i<n;i++)
                {
                    if(i==k)
                        continue;
                    if(judge[i]<now)
                        remain-=(now-judge[i])/sum;
                }
                if(remain>0)
                    l=m;
                else
                    h=m;
            }
            printf(" %.8lf",m*100.0);
        }
        puts("");
    }
    //system("pause");
    return 0;
} 
