#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

char str[1111111];
int a[1111111];

int main()
{
    int cases,o,i,len,cnt,n,j,k;
    freopen("A-large.in","r",stdin);
    freopen("A-large.out","w",stdout);
    scanf("%d",&cases);
    long long ans;
    for(o=1;o<=cases;o++)
    {
        ans=0;
        scanf("%s",str);
        scanf("%d",&n);
        len=strlen(str);
        for(i=0;i<len;i++)
            a[i]=-1;
        cnt=0;
        bool flag=false;
        for(i=0;i<len;i++)
        {
            if(i>0)
                a[i]=a[i-1];
            if( str[i]=='a' || str[i]=='e' || str[i]=='i' || str[i]=='o' || str[i]=='u')
            {
                cnt=0;
            }
            else
            {
                cnt++;
                if(cnt>=n)
                {
                    a[i]=i-n+1;
                }
            }
            ans=ans+a[i]+1;
        }
        printf("Case #%d: %lld\n",o,ans);
    }
    return 0;
}
