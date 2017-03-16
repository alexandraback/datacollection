#include <stdio.h>
#include <string.h>

#define MOD 1000000007

int n;
char head[100], tail[100];
int in[100];

long long cpl(int num);

int main()
{
    int cn, cc;
    freopen("b.in", "r", stdin);
    freopen("b.out", "w", stdout);

    scanf("%d", &cn);

    for (cc=1; cc<=cn; cc++)
    {
        int i, j;

        char seg[100][101];
        int cnt[256] = {0};

        char ch;

        long long ways;
        int pl;

        scanf("%d", &n);
        for (i=0; i<n; i++)
            scanf("%s", seg[i]);

        for (i=0; i<n; i++)
        {
            head[i] = seg[i][0];
            for (j=0; seg[i][j]; j++)
                cnt[seg[i][j]]++;
            tail[i] = seg[i][j-1];
        }

        for (i=0; i<n; i++)
        {
            int hp, tp;
            int len;

            hp = 0;
            while (seg[i][hp] == head[i])
                hp++;
            if (head[i] == tail[i] && seg[i][hp])
                goto BAD;
            j = hp;
            while (seg[i][j] != '\0' && seg[i][j] != tail[i])
            {
                if (seg[i][j] == head[i])
                    goto BAD;
                j++;
            }
            tp = j;
            while (seg[i][j] != '\0')
            {
                if (seg[i][j] != tail[i])
                    goto BAD;
                j++;
            }

            for (j=hp; j<tp; j++)
            {
                if (seg[i][j] != seg[i][j-1])
                    len = 1;
                else
                    len++;

                if (seg[i][j] != seg[i][j+1] && len < cnt[seg[i][j]])
                    goto BAD;
            }
        }

        ways = 1;
        pl = n;
        for (ch='a'; ch<='z'; ch++)
        {
            int hw, tw;
            int num;

            hw = tw = -1;
            num = 0;

            for (i=0; i<n; i++)
                if (!in[i])
                {
                    if (head[i] == ch && tail[i] == ch)
                        num++;
                    else if (head[i] == ch)
                    {
                        if (hw >= 0) goto BAD;
                        hw = i;
                    }
                    else if (tail[i] == ch)
                    {
                        if (tw >= 0) goto BAD;
                        tw = i;
                    }
                }

            if (num) ways = ways * cpl(num) % MOD;
            if (num || hw >= 0 || tw >= 0)
            {
            if (hw >= 0) num++;
            if (tw >= 0) num++;
            pl -= num - 1;
            }
        }

        ways = ways * cpl(pl) % MOD;
        printf("Case #%d: %lld\n", cc, ways);
        continue;
    BAD:
        printf("Case #%d: 0\n", cc);
    }

    return 0;
}

long long cpl(int num)
{
    long long pl = 1;
    while (num)
    {
        pl = pl * num % MOD;
        num--;
    }

    return pl;
}
