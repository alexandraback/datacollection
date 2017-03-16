#include <cstdio>

char map[26]={'y','h','e','s','o','c','v','x','d','u','i','g','l','b','k','r','z','t','n','w','j','p','f','m','a','q'};
char temp[1024];

int main()
{
    //freopen("A-small-attempt0.in", "r", stdin);
    //freopen("A-small-attempt0.out", "w", stdout);
    int n;
    scanf("%d\n",&n);
    for(int i=1;i<=n;++i)
    {
        gets(temp);
        for(int j=0;temp[j];++j)
        {
            if(temp[j] >= 'a' && temp[j] <= 'z')
            {
                temp[j] = map[temp[j] - 'a'];
            }
        }
        printf("Case #%d: %s\n", i, temp);
    }
    return 0;
}
