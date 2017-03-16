#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;

long long n, m;
char s[120010];
char aux[120010];

int op[4][4] =
{
    {0, 1, 2, 3},
    {1, 0, 3, 2},
    {2, 3, 0, 1},
    {3, 2, 1, 0}
};

int sop[4][4] =
{
    {1, 1, 1, 1},
    {1, -1, 1, -1},
    {1, -1, -1, 1},
    {1, 1, -1, -1}
};

int a[120010];
int sa[120010];


void citire()
{
    scanf("%lld %lld\n", &n, &m);
    gets(s);
    for(int i = 0; i < n; i++)
        if(s[i] == '1') s[i] = 'h';
    scanf("\n");

    for(int i = 0; i < 3; i++)
    {
        strcpy(aux, s);
        strcat(s, aux);
    }
}


int solve()
{
    a[0] = s[0] - 'h';
    sa[0] = 1;
    int caut;
    if(a[0] == 1) caut = 3;
    else caut = 1;

    for(int i = 1; i < n * min((long long int)8, m); i++)
    {
        a[i] = op[a[i-1]][s[i]-'h'];
        sa[i] = sop[a[i-1]][s[i]-'h'] * sa[i-1];
        if(caut <= 3 && a[i] == caut && sa[i] == 1)
            caut+=2;
    }

    if(caut <= 3)
        return 0;

    if(a[n-1] == 0 && sa[n-1] == 1) return 0;
    if(a[n-1] == 0 && sa[n-1] == -1)
        if(m % 2 == 1) return 1;
        else return 0;

    if(m % 4 == 2) return 1;

    return 0;
}

int main()
{
    freopen("f.in", "r", stdin);
    freopen("f.out", "w", stdout);

    int t;
    scanf("%d\n", &t);
    for(int q = 1; q <= t; q++)
    {
        citire();
        if(solve())
            printf("Case #%d: YES\n", q);
        else
            printf("Case #%d: NO\n", q);
    }
    return 0;
}
