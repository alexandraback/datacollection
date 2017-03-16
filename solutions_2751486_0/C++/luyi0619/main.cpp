#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int N = 100010;
char str[N];
int cnt[N], next[N];
bool check(char c)
{
    if( c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' )
        return false;
    return true;
}
int main()
{
    freopen("C:\\Users\\v-y\\Downloads\\A-small-attempt3.in","r",stdin);
    freopen("C:\\Users\\v-y\\Downloads\\A-small-attempt3.out","w",stdout);
    int t, cas = 1;
    scanf("%d",&t);
    while(t--)
    {
        int n, len;
        scanf("%s %d",str,&n);
        len = strlen(str);
        cnt[0] = check(str[0]);
        for(int i = 1; i < len ; i ++)
        {
            if( check( str[i] ))
                cnt[i] = cnt[i-1] + 1;
            else
                cnt[i] = 0;
        }

        long long ans = 0;
        int x = -1 , y = x + n - 1;
        for(int i = 0 ; i < len ; i  ++)
        {
            if(x < i)
            {
                x = i;
                y = x + n - 1;

                while(y < len)
                {
                    if(cnt[x] && cnt[y] - cnt[x] == n - 1 )
                    {
                        break;
                    }
                    else
                    {
                        x ++;
                        y ++;
                    }
                }
            }
            if(y >= len)
                break;

            ans += len - y;


        }
        printf("Case #%d: %lld\n",cas ++ ,ans);
    }
    return 0;
}
