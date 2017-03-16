#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
char a[105];
int len;
int f()
{
    for(int i=len-1; i>=0; i--)
    {
        if(a[i]=='-')
        {
            reverse(a,a+i+1);
            return 1;
        }
    }
    return 0;
}
int main()
{
    //freopen("B-large.in","r",stdin);
    //freopen("large.txt","w",stdout);
    int T;
    scanf("%d",&T);
    for(int cases=1; cases<=T; cases++)
    {
        scanf("%s",a);
        len=strlen(a);
        int ans=0;
        while(true)
        {
            if(a[0]=='-')
            {
                for(int i=0;a[i]=='-';i++)
                    a[i]='+';
                ans++;
                //printf("#%s\n",a);
            }
            if(f()) ans++;
            else break;
            //printf("##%s\n",a);
        }
        printf("Case #%d: %d\n",cases,ans);
    }
    return 0;
}
