#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
const int maxn=15000;
int hash[maxn];
int main()
{
    int t,ca=1;
    freopen("B-large.in","r",stdin);
    freopen("B-large.out","w",stdout);
    scanf("%d",&t);
    while(t--)
    {
        printf("Case #%d: ",ca++);
        int n,x;
        scanf("%d",&n);
        memset(hash,0,sizeof(hash));
        for(int i=0;i<2*n-1;i++)
        {
            for(int j=0;j<n;j++)
            {
               scanf("%d",&x);
               hash[x]++;
            }
        }
        int sign=0;
        for(int i=1;i<maxn;i++)
        {
            if(hash[i]%2)
            {
               if(sign==0)
               {
                   printf("%d",i);
                   sign=1;
               }
               else
               printf(" %d",i);
            }
        }
        printf("\n");
    }
    return 0;
}
