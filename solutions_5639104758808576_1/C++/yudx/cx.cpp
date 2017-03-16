#include<stdio.h>
#include<algorithm>
#include<vector>
#include<math.h>
#include<string.h>
#include<vector>
#include<map>
#include<set>
#include<iostream>

using namespace std;

typedef long long ll;

int n,a[1005];
char c[1005];

int main()
{
    freopen("A-large.in","r",stdin);
    freopen("A-large.out","w",stdout);
    int T,I=1,i,j;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        scanf("%s",c);
        for(i=0;i<=n;i++) a[i]=c[i]-'0';
        int cur=a[0],r=0;
        for(i=1;i<=n;i++)
        {
            if(cur<i) r=r+i-cur,cur=i;
            cur+=a[i];
        }
        printf("Case #%d: %d\n",I++,r);
    }
    return 0;
}
