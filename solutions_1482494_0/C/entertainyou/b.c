#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

struct game
{
    int a;
    int b;
    /* 0: unvisited, 1: 1star, >1: 2star */
    int visited;
};

typedef struct game * gamep;

int game_cmp_a(const void *a, const void *b)
{
    gamep *gap, *gbp, ga, gb;
    gap = (gamep *)a;
    gbp = (gamep *)b;

    ga = *gap;
    gb = *gbp;

    if (ga->a > gb->a)
        return 1;
    else if (ga->a == gb->a)
    {
        return ga->b - gb->b;
    }
    else
        return -1;
}

int game_cmp_b(const void *a, const void *b)
{
    gamep *gap, *gbp, ga, gb;
    gap = (gamep *)a;
    gbp = (gamep *)b;

    ga = *gap;
    gb = *gbp;

    if (ga->b > gb->b)
        return 1;
    else if (ga->b == gb->b)
    {
        return ga->a - gb->a;
    }
    else
        return -1;
}

int solve(int n, struct game *games)
{

    gamep *a, *b;
    int i, j, tot, ret, valid;

    a = malloc(sizeof(struct game *) * n);
    b = malloc(sizeof(struct game *) * n);

    for (i = 0; i < n; ++i)
    {
        struct game *g = &games[i];
        a[i] = g;
        b[i] = g;
    }

    qsort(a, n, sizeof(gamep), game_cmp_a);
    qsort(b, n, sizeof(gamep), game_cmp_b);

    tot = 0;
    i = 0;
    j = 0;
    ret = 0;
    valid = 1;
    while (j < n)
    {
        if (tot >= b[j]->b)
        {

            if (b[j]->visited == 0)
            {
                tot += 2;
                ret += 1;
                b[j]->visited = 2;
            }
            else if (b[j]->visited == 1)
            {
                tot += 1;
                ret += 1;
                b[j]->visited = 2;
            }
            j += 1;
        }else if (i < n && tot >= a[i]->a)
        {
            if (a[i]->visited == 0)
            {
                tot += 1;
                ret += 1;
                a[j]->visited = 1;
            }

            i += 1;
        }else
        {
            valid = 0;
            break;
        }
    }
    free(a);
    free(b);

    if (valid)
        return ret;
    else
        return -1;
}

int main(int argc, char *argv[])
{
    int i, t;
    scanf("%d", &t);

    for (i = 0; i < t; ++i)
    {
        int j, n, ret;
        struct game *games;
        scanf("%d", &n);

        games = malloc(sizeof(struct game) * n);
        for (j = 0; j < n; ++j)
        {
            scanf("%d %d", &games[j].a, &games[j].b);
            games[j].visited = 0;
        }

        ret = solve(n, games);
        if (ret < 0)
            printf("Case #%d: Too Bad\n", i + 1);
        else
            printf("Case #%d: %d\n", i + 1, ret);
    }
    return 0;
}
