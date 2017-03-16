#include <cstdio>

using namespace std;

int main()
{
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("A-small.out", "w", stdout);
    char to[26] = {
        'y', 'h', 'e', 's', 'o', 'c', 'v',
        'x', 'd', 'u', 'i', 'g', 'l', 'b',
        'k', 'r', 'z', 't', 'n', 'w',
        'j', 'p', 'f', 'm', 'a', 'q'
    };

    int T;
    char buf[256];
    scanf("%d", &T);
    gets(buf);
    for (int k=1; k<=T; ++k)
    {
        gets(buf);
        for (int i=0; buf[i]!='\0'; ++i)
        {
            if (buf[i]>='a' && buf[i]<='z') buf[i] = to[buf[i]-'a'];
        }
        printf("Case #%d: %s\n", k, buf);
    }

    return 0;
}
