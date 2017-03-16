#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;
int pow[10],q1[10];
int test,a,b;

int main()
{
    freopen("1.txt","r",stdin);
    freopen("2.txt","w",stdout);
    scanf("%d",&test);
    
    pow[1]=1;   for (int i=2;i<=8;i++)  pow[i]=pow[i-1]*10;
    
    for (int t=1;t<=test;t++)
    {
        scanf("%d%d",&a,&b);    int ans=0;
        
        for (int i=a;i<=b;i++)
        {
            int p1=i;        q1[0]=0;
            for (;p1;p1/=10) q1[++q1[0]]=p1%10;
            if (q1[0]<=1)   continue;
            
            for (int j=1;j<q1[0];j++)
            {
                if (!q1[j])         continue;
                int js=1;           int p2=0;
                for (int k=j+1;k<=q1[0];k++)    p2+=q1[k]*pow[js],js++;
                for (int k=1;k<=j;k++)          p2+=q1[k]*pow[js],js++;
                
                if (p2>=a && p2<=b && p2>i)     ans++;
                if (p2==i)                      break;
            }
        }
        
        printf("Case #%d: %d\n",t,ans);
    }
}
