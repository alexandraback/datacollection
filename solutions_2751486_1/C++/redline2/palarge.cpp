#include<stdio.h>
#include<algorithm>
#include<string.h>

using namespace std;


char s[1000005];
int T,N,cnt[1000005],len,p;
long long ans;

int main()
{
    freopen("A-large.in","r",stdin);
    freopen("palarge.txt","w",stdout);

    scanf("%d",&T);

    for( int cas = 1; cas <= T; cas++ ){
        scanf(" %s %d",s,&N);
        len = strlen(s);
        ans = 0LL;

        if( s[0] == 'a' || s[0] == 'e' || s[0] == 'i' || s[0] == 'o' || s[0] == 'u' )cnt[0] = 0;
        else    cnt[0] = 1;
        for( int i = 1; i < len; i++ ){
            if( s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' )cnt[i] = 0;
            else    cnt[i] = cnt[i-1] + 1;
        }

        p = -1;
        for( int i = N-1; i < len; i++ ){
            if( cnt[i] >= N )   p = i-N+1;
            ans += (p+1);
        }

        printf("Case #%d: %I64d\n",cas,ans);
    }


    return 0;
}
