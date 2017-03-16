#include<stdio.h>
#include<set>
#include<algorithm>
#include<string.h>

using namespace std;




int main()
{

    freopen("A-small-attempt0.in","r",stdin);
    freopen("pa.txt","w",stdout);
    int T,N,cnt,len,ans;
    char s[200];
    set< pair<char,char> > Set;
    scanf("%d",&T);

    for( int cas = 1; cas <= T; cas++ ){
        scanf(" %s %d",s,&N);
        Set.clear();
        len = strlen(s);
        ans = 0;
        for( int i = 0; i < len; i++ ){
            for( int j = i+N-1; j < len; j++ ){
                cnt = 0;
                for( int k = i; k <= j; k++ ){
                    if( s[k] == 'a' || s[k] == 'e' || s[k] == 'i' || s[k] == 'o' || s[k] == 'u' )
                        cnt = 0;
                    else
                        cnt++;
                    if( cnt >= N ){
                        ans++;
                        break;
                    }
                }
            }
        }
        printf("Case #%d: %d\n",cas,ans);

    }


    return 0;
}
