// RandomUsername (Nikola Jovanovic)
// GCJ 2016 1B
// B

#include <bits/stdc++.h>
#define DBG false
#define debug(x) if(DBG) printf("(ln %d) %s = %d\n", __LINE__, #x, x);
#define lld long long
#define ff(i,a,b) for(int i=a; i<=b; i++)
#define fb(i,a,b) for(int i=a; i>=b; i--)
#define par pair<int, int>
#define fi first
#define se second
#define mid (l+r)/2
#define INF 1000000000
#define MAXN 30

using namespace std;

int t;
char c[MAXN];
char j[MAXN];
int n;
/*
void DFS(int i, int dir)
{
    //dir = 0 OK
    //dir = 1 C NAMESTI DA BUDE VECI
    //dir = -1 C NAMESTI DA BUDE MANJI
    if(i == n)
    {
        // end
        return;
    }
    if(dir == 0)
    {
        // try to be the same
        if(c[i] == '?' && j[i] == '?')
        {
            c[i] = '0';
            j[i] = '0';
            DFS(i+1, 0);
        }
        else if(c[i] == '?')
        {
            c[i] = j[i];
            DFS(i+1, 0);
        }
        else if(j[i] == '?')
        {
            j[i] = c[i];
            DFS(i+1, 0);
        }
        else
        {
            if(c[i] == j[i])
                DFS(i+1, 0);
            else if(c[i] < j[i])
                DFS(i+1, 1);
            else
                DFS(i+1, -1);
        }
    }
    else if(dir == 1)
    {
        // NAMESTI DA C BUDE STO VECI DA UBLAZIS RAZLIKU KOJA POSTOJI
        if(c[i] == '?' && j[i] == '?')
        {
            c[i] = '9';
            j[i] = '0';
            DFS(i+1, 1);
        }
        else if(c[i] == '?')
        {
            c[i] = '9';
            DFS(i+1, 1);
        }
        else if(j[i] == '?')
        {
            j[i] = '0';
            DFS(i+1, 1);
        }
        else
        {
            DFS(i+1, 1);
        }
    }
    else
    {
        // NAMESTI DA C BUDE STO manji DA UBLAZIS RAZLIKU KOJA POSTOJI
        if(c[i] == '?' && j[i] == '?')
        {
            c[i] = '0';
            j[i] = '9';
            DFS(i+1, -1);
        }
        else if(c[i] == '?')
        {
            c[i] = '0';
            DFS(i+1, -1);
        }
        else if(j[i] == '?')
        {
            j[i] = '9';
            DFS(i+1, -1);
        }
        else
        {
            DFS(i+1, -1);
        }
    }
}
*/

struct sol
{
    int c;
    int j;
    int diff;
};

sol best;

void eval(int a, int b, int x, int d, int e, int f)
{
    int C = 0;
    C *= 10;
    C += (c[0] == '?') ? a : (c[0] - '0');
    if(n > 1){
        C *= 10;
        C += (c[1] == '?') ? b : (c[1] - '0');
    }
    if(n > 2){
        C *= 10;
        C += (c[2] == '?') ? x : (c[2] - '0');
    }
    int J = 0;
    J *= 10;
    J += (j[0] == '?') ? d : (j[0] - '0');
    if(n > 1){
        J *= 10;
        J += (j[1] == '?') ? e : (j[1] - '0');
    }
    if(n > 2){
        J *= 10;
        J += (j[2] == '?') ? f : (j[2] - '0');
    }


    int scor = round(abs(J - C));
    if(scor < best.diff || (scor == best.diff && C < best.c) ||
     (scor == best.diff && C == best.c && J < best.j)    )
    {
        best.diff = scor;
        best.c = C;
        best.j = J;
    }
}

void solve()
{
    best.diff = 10000000;
    ff(a, 0, 9)
    {
        ff(b, 0, 9)
        {
            ff(x, 0, 9)
            {
                ff(d, 0, 9)
                {
                    ff(e, 0, 9)
                    {
                        ff(f, 0, 9)
                        {
                            eval(a,b,x,d,e,f);
                        }
                    }
                }
            }
        }
    }
}

int main()
{
    freopen("B-small-attempt0.in", "r", stdin);
    freopen("B.out", "w", stdout);
    scanf("%d", &t);
    ff(tt, 1, t)
    {
        scanf("%s", c);
        scanf("%s", j);
        n = strlen(c);
        solve();
        if(n == 1)
            printf("Case #%d: %01d %01d\n", tt, best.c, best.j);
        if(n == 2)
            printf("Case #%d: %02d %02d\n", tt, best.c, best.j);
        if(n == 3)
            printf("Case #%d: %03d %03d\n", tt, best.c, best.j);
    }
    return 0;
}