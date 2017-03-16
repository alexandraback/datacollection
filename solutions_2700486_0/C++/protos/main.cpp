#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1000000 + 10;
const int I = 706 + 10;

int tc, n, x, y;

double res;

double dyn[I << 1][I << 1];

void input()
{
    scanf("%d %d %d", &n, &x, &y);
}

void dynamic(int i, int n)
{
    int ti, tn;
    dyn[0][0] = 1.0;
    
    for(tn = 1; tn <= n; tn++)
    {
        for(ti = 0; ti <= tn; ti++)
        {
            dyn[ti][tn - ti] = 0.0;
            if(2 * i < ti || 2 * i < (tn - ti))
            {
                continue;
            }
            if(ti != 0)
            {
                if(tn - ti == 2 * i)
                {
                    dyn[ti][tn - ti] += dyn[ti - 1][tn - ti];
                }
                else
                {
                    dyn[ti][tn - ti] += 0.5 * dyn[ti - 1][tn - ti];
                }
            }
            if(tn - ti != 0)
            {
                if(ti == 2 * i)
                {
                    dyn[ti][tn - ti] += dyn[ti][tn - ti - 1];
                }
                else
                {
                    dyn[ti][tn - ti] += 0.5 * dyn[ti][tn - ti - 1];
                }
            }
        }
    }
}

void process()
{
    int i, j;
    
    for(i = 1; 2 * i * i - i < n; i++);
    i--;
    
    if(abs(x) + y < 2 * i)
    {
        res = 1.0;
        return;
    }
    if(2 * i < abs(x) + y)
    {
        res = 0.0;
        return;
    }
    
    n -= 2 * i * i - i;
    if(2 * i + y + 1 <= n)
    {
        res = 1.0;
        return;
    }
    if((y + 1 <= 2 * i && n < y + 1) || y == 2 * i)
    {
        res = 0.0;
        return;
    }
    dynamic(i, n);
    res = 0.0;
    for(j = (y + 1); j <= min(2 * i, n); j++)
    {
        res += dyn[j][n - j];
    }
}

void output()
{
    printf("Case #%d: %.6lf\n", tc, res);
}

int main()
{
    int t;
    
    freopen("/Users/protos37/Downloads/B-small-attempt0.in", "r", stdin);
    freopen("/Users/protos37/Downloads/B-small-attempt0.out", "w", stdout);
    
    scanf("%d", &t);

    for(tc = 1; tc <= t; tc++)
    {
        input();
        process();
        output();
    }
}