#include <cstdio>

int main()
{
    freopen("C-small-attempt0.in", "r", stdin);
    freopen("C-small-attempt0.out", "w", stdout);
    //freopen("C-large.in","r",stdin);
    //freopen("C-large.out","w",stdout);
    int t, a, b, n, m;
    int r[256];
    scanf("%d",&t);
    for(int k=1;k<=t;++k)
    {
        scanf("%d%d",&a,&b);
        n = 0, m = 1;
        int temp = a;
        while(temp > 0)
        {
            ++ n;
            temp /= 10;
        }
        for(int i=1;i<n;++i)
        {
            m *= 10;
        }
        int ans = 0;
        for(int i=a;i<=b;++i)
        {
            temp = i;
            int cnt = 0;
            for(int j=1;j<n;++j)
            {
                int last = temp % 10;
                temp = temp / 10 + last * m;
                if(temp > i && temp <= b)
                {
                    int c;
                    for(c=0;c<cnt;++c)
                    {
                        if(r[c] == temp)
                        {
                            break;
                        }
                    }
                    if(c == cnt)
                    {
                        r[c] = temp;
                        ++ cnt;
                    }
                }
            }
            ans += cnt;
        }
        printf("Case #%d: %d\n", k, ans);
    }
    return 0;
}
