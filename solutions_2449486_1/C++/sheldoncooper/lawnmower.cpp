#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    //freopen("largeinput.txt","r",stdin);
    //freopen("output2.txt","w", stdout);
    int t,n,m,i,j,arr[101][101],test=1;
    scanf("%d",&t);
    while(t--)
    {
        
        scanf("%d%d",&n,&m);
         int maxr[101]={0},maxc[101]={0},flag=0;       
        for(i=0;i<n;i++)
        for(j=0;j<m;j++)
        { scanf("%d",&arr[i][j]); maxr[i]=max(maxr[i],arr[i][j]);
         maxc[j]=max(maxc[j],arr[i][j]);
        }
        
        
        if(m==1||n==1)
        { printf("Case #%d: YES\n",test++);
          continue;
        }
        
        for(i=0;i<n;i++)
        {for(j=0;j<m;j++)
        if(arr[i][j]<min(maxr[i],maxc[j]))
        {
            flag=1;
            break;
        }
        if(flag==1)
        break;
        }
        if(flag==1)
        {
            printf("Case #%d: NO\n",test++);
            continue;
        }
        printf("Case #%d: YES\n",test++);
        
    }
    return 0;
}
