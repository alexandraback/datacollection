#include <cstdio>

int main()
{
    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++)
    {
        int M;
        char buf[1005];
        scanf("%d %s", &M, buf);
        int total=0, ans=0;
        for(int i=0; i<=M; i++)
        {
            int c = buf[i] - '0';
            if (c)
            {
                while (total < i)
                {
                    ans++;
                    total++;
                }
                total+=c;
            }
        }
        printf("Case #%d: %d\n", t, ans);
    }
}
