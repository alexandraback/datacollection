#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

const int MAXN = 100 + 10;

char s[MAXN];

int getlast(char *s, int len)
{
    for (int i = len; i; --i)
        if (s[i] == '-') return i;
    return -1;
}

void reverse(char *s, int l, int r)
{
    for (int i = l, j = r; i < j; i++, j--)
        swap(s[i], s[j]);
    
    for (int i = l; i <= r; ++i)
        if (s[i] == '+') s[i] = '-';
        else s[i] = '+';
}

int main()
{
    freopen("B.in","r",stdin);
    freopen("B.out","w",stdout);
    int TestCase;
    scanf("%d", &TestCase);
    
    for (int T = 1; T <= TestCase; ++T)
    {
        scanf("%s", s + 1);
        int N = strlen(s + 1);
        
        int ans = 0, p;
        while ( ( p = getlast(s, N) ) != -1)
        {
            if (s[1] == '+')
            {
                ++ans;
                for (int i = 1; i <= N; ++i)
                    if (s[i] == '+')
                       s[i] = '-';
                    else break;
            }
            
            reverse(s, 1, p);
            ++ans;
        }
        
        printf("Case #%d: %d\n", T, ans);
            
    }
    return 0;
}
