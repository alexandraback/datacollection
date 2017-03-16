#include <cstdio>
#include <cstring>

char s[105];

int main(int argc, char* argv[])
{
    int T, l, ans;
    bool rev;
    scanf("%d", &T);
    for (int test = 1; test <= T; ++test)
    {
        ans = 0;
        rev = false;
        scanf("%s", s);
        l = strlen(s);
        for (int i = l - 1; i >= 0; --i)
        {
            if (rev ^ (s[i] == '-'))
            {
                rev ^= true;
                ++ans;
            }
        }
        printf("Case #%d: %d\n", test, ans);
    }
    return 0;
}
