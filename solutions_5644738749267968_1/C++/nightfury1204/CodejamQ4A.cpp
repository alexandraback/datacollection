//BISMILLAHIR RAHMANIR RAHIM
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<queue>
#include<stack>
#include<map>
#include<string>
#include<vector>
#include<algorithm>
#define N 1000000
#define sn scanf
#define pf printf

typedef long long int ll;
using namespace std;

int main()
{
    int i,j,k,l,t,r,x,n,m,M,a,c,d,e,f,b,visa[2000],visb[2000];
    double ar[2000],arr[2000];
    freopen("D-large.in","r",stdin);
    freopen("Output.txt","w",stdout);
    scanf("%d",&t);
    for(r=1;r<=t;r++)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%lf",&ar[i]);
        }
        for(j=0;j<n;j++)
        {
            scanf("%lf",&arr[j]);
        }
        sort(ar,ar+n);
        sort(arr,arr+n);
        a=b=0;e=f=0;
        memset(visa,0,sizeof(visa));
        memset(visb,0,sizeof(visb));
        for(i=0;i<n;i++)
        {
            c=0;d=0;
            for(j=(e<f)?e:f;j<n;j++)
            {
                if(d==0&&visa[j]==0&&arr[j]<ar[i])
                    {
                        visa[j]=1;e=j;
                        a++;d=1;
                    }
                if(c==0&&visb[j]==0&&ar[j]<arr[i])
                {
                    visb[j]=1;f=j;
                    b++;c=1;
                }
            }
        }
        printf("Case #%d: %d %d\n",r,a,n-b);
    }
    fclose(stdout);
    fclose(stdin);
        return 0;
}



