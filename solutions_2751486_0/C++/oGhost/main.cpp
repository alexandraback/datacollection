#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

char str[1111111];


int main()
{
    int cases,o,i,len,cnt,n,j,k;
    freopen("A-small-attempt0.in","r",stdin);
    freopen("A-small-attempt0.out","w",stdout);
    scanf("%d",&cases);
    long long ans;
    for(o=1;o<=cases;o++)
    {
        ans=0;
        scanf("%s",str);
        scanf("%d",&n);
        len=strlen(str);
        cnt=0;
        for(i=0;i<len;i++)
        for(j=i+n-1;j<len;j++)
        {
            cnt=0;
        for(k=i;k<=j;k++)
        {
            if( str[k]=='a' || str[k]=='e' || str[k]=='i' || str[k]=='o' || str[k]=='u')
            {
                cnt=0;
            }
            else
            {
                cnt++;
                if(cnt>=n)
                {
                    ans++;
                    break;
                }
            }
        }
        }
        printf("Case #%d: %lld\n",o,ans);
    }
    return 0;
}
