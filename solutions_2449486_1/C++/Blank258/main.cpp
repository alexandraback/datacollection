# include <stdbool.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <math.h>

int map[101][101], ans[105];

int n, m;

int min()
{
    int i, j, min = map[0][0];
    for(i = 0; i < m; i++)
    {
        for(j = 0; j < n; j++)
        {
            if(map[i][j] < min) min = map[i][j];
        }
    }
    return min;
}

int find(int min)
{
    int i, j, row = 0, column = 0, count, sum;
    for(i = sum = 0; i < m; i++)
    {
        count = 0;
        for(j = 0; j < n; j++)
        {
            if(map[i][j] == min)    count++;
        }
        if(count == n)  row++;
        sum += count;
    }
    for(j = 0; j < n; j++)
    {
        count = 0;
        for(i = 0; i < m; i++)
        {
            if(map[i][j] == min)    count++;
        }
        if(count == m)  column++;
    }
    if(sum == n*row+m*column-row*column)
    {
        return 1;
    }
    return 0;
}

void set(int min)
{
    int i, j, k;
    for(i = min+1; ans[i] == 0; i++);
    k = i;
    for(i = 0; i < m; i++)
    {
        for(j = 0; j < n; j++)
        {
            if(map[i][j] == min)    map[i][j] = k;
        }
    }
}


int main()
{
//    freopen("B-large.in", "r", stdin);
//    freopen("out", "w", stdout);
    int t, cnt = 1, i, j, k;
    bool escape;
    scanf("%d", &t);
    while(cnt <= t)
    {
        scanf("%d %d", &m, &n);
        memset(ans, 0, sizeof(ans));
        for(i = k = 0; i < m; i++)
        {
            for(j = 0; j < n; j++)
            {
                scanf("%d", &map[i][j]);
                ans[map[i][j]]++;
                if(map[i][j] > k)   k = map[i][j];
            }
        }
        escape = false;
        i = min();
        while(i < k)
        {
            if(find(i))
            {
                set(i);
                i = min();
                continue;
            }
            escape = true;
            break;
        }
        if(escape)
        {
            printf("Case #%d: NO\n", cnt++);
            continue;
        }
        printf("Case #%d: YES\n", cnt++);
    }
    return 0;
}

