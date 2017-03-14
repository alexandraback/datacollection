#include<stdio.h>
#include<string.h>

char mat[50][50];
int x, y;
int resp;
int steps[200];
int stepssize;

int gcd(int a, int b)
{
    if (a < 0) a = -a;
    if (b < 0) b = -b;
    if (a == 0) return b;
    if (a > b) return gcd(b, a);
    return gcd(b % a, a);
}

void calculateSteps(int dx, int dy)
{
    //printf("%d %d\n", dx, dy);
    stepssize = dx + dy;
    if ((dx % 2) == 1 && (dy % 2) == 1)
    {
        stepssize--;
    }
    int pxl = dy;
    int pyl = dx;
    for (int i = 0; i < stepssize; i++)
    {
        if (pxl < pyl)
        {
            steps[i] = 0;
            pyl -= pxl;
            pxl = 2 * dy;
        }
        else if (pxl > pyl)
        {
            steps[i] = 1;
            pxl -= pyl;
            pyl = 2 * dx;
        }
        else
        {
            steps[i] = 2;
            pxl = 2 * dy;
            pyl = 2 * dx;
        }
        //printf(" %d", steps[i]);
    }
    //printf("\n");
}

void testRay(int dx, int dy, int dirx, int diry, int tries)
{
    int px = x;
    int py = y;
    //printf(" %d %d\n", dx * dirx, dy * diry);
    for (int i = 0; i < tries; i++)
    {
        for (int j = 0; j < stepssize; j++)
        {
            switch(steps[j])
            {
                case 0:
                {
                    if (mat[px + dirx][py] == '#')
                    {
                        dirx = -dirx;
                    }
                    else
                    {
                        px = px + dirx;
                    }
                    break;
                }
                case 1:
                {
                    if (mat[px][py + diry] == '#')
                    {
                        diry = -diry;
                    }
                    else
                    {
                        py = py + diry;
                    }
                    break;
                }
                case 2:
                {
                    int nx = px + dirx;
                    int ny = py + diry;
                    if (mat[nx][ny] == '#')
                    {
                        if (mat[px][ny] == '#')
                        {
                            if (mat[nx][py] == '#')
                            {
                                dirx = -dirx;
                                diry = -diry;
                            }
                            else
                            {
                                diry = -diry;
                                px = nx;
                            }
                        }
                        else
                        {
                            if (mat[nx][py] == '#')
                            {
                                dirx = -dirx;
                                py = ny;
                            }
                            else
                            {
                                return;
                            }
                        }
                    }
                    else
                    {
                        px = px + dirx;
                        py = py + diry;
                    }
                    break;
                }
            }
        }
        if (px == x && py == y)
        {
            resp++;
            //printf("    %d\n", i + 1);
            return;
        }
    }
}

int main()
{
    int teste;
    scanf("%d\n", &teste);
    for (int t = 0; t < teste; t++)
    {
        int n, m, d;
        int i, j;
        scanf("%d %d %d", &n, &m, &d);
        //printf("%d %d %d\n", n, m, d);
        for (i = 0; i < n; i++)
        {
            scanf("%s", mat[i]);
            //printf("%s\n", mat[i]);
            for (j = 0; j < m; j++)
            {
                if (mat[i][j] == 'X')
                {
                    mat[i][j] = '.';
                    x = i;
                    y = j;
                }
            }
        }
        resp = 0;
        calculateSteps(1, 0);
        testRay(1, 0, 1, 1, d);
        testRay(1, 0, -1, 1, d);
        calculateSteps(0, 1);
        testRay(0, 1, 1, 1, d);
        testRay(0, 1, 1, -1, d);
        for (i = 1; i < d; i++)
        {
            for (j = 1; j < d; j++)
            {
                if (gcd(i,j) > 1) continue;
                int sqrd = i * i + j * j;
                int tries = 0;
                while (tries * tries * sqrd <= d * d)
                {
                    tries++;
                }
                tries--;
                if (tries > 0)
                {
                    calculateSteps(i, j);
                    testRay(i, j, 1, 1, tries);
                    testRay(i, j, 1, -1, tries);
                    testRay(i, j, -1, 1, tries);
                    testRay(i, j, -1, -1, tries);
                }
            }
        }
        printf("Case #%d: %d\n", t + 1, resp);
    }
    return 0;
}

