#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;

#define DEBUG


int num[11],n;
char str[11][110];
char finstr[1100];
bool f[300];
bool check()
{
    memset(f,false,sizeof f);
    int cnt = 0;
    char last =200;
    for(int i=0;i<n;i++)
    {
        int tmpnum = num[i];
        int len = strlen(str[tmpnum]);
        for(int j=0;j<len;j++)
        {
            if( str[tmpnum][j] != last )
            {
                if( f[ str[tmpnum][j]-'a' ] == true ) return false;
                else f[str[tmpnum][j]-'a' ] = true;
            }
            last = str[tmpnum][j];
        }
    }
    return true;
}
int main()
{
#ifdef DEBUG
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
#endif
    int t,casecnt=1;scanf("%d",&t);
    while(t--)
    {
        printf("Case #%d: ",casecnt++);
        scanf("%d\n",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%s",str[i]);
            num[i]=i;
        }
        for(int )
        int ans = 0;
        do
        {
            if ( check() ) ans++;
        } while( next_permutation(num,num+n) );
        printf("%d\n",ans);
    }
    return 0;
}
