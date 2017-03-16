#include <stdio.h>
#include <string.h>

int a[5][5];
char s[300000];
int mul[300000];

int transform_ijk(int x, int y)
{
    int sym = 1;
    if (x < 0) { sym = -sym; x = -x; }
    if (y < 0) { sym = -sym; y = -y; }
    return sym * a[x][y];
}

bool Work()
{
    long long  x;
    int l;
    scanf("%d%I64d", &l, &x);
    scanf("%s", s);
    for (int i = 0; i < l; i++)
    {
        int temp = 0;
        if (s[i] == 'i') { temp = 2; }
        if (s[i] == 'j') { temp = 3; }
        if (s[i] == 'k') { temp = 4; }
        if (i == 0) { mul[i] = temp; }
        else { mul[i] = transform_ijk(mul[i - 1], temp); }
    }

    if (mul[l - 1] == 1) { return false; } else
    if ((mul[l - 1] == -1) && (x % (long long)2 == (long long)0)) { return false; } else
    if ((mul[l - 1] != -1) && ((((x / (long long)2) % (long long)2 == (long long)0) && (x % (long long)2 == (long long)0)) ||(x % (long long)2 != (long long)0))) { return false; }
    long long temp = 15;
    if (x < temp) { temp = x; }
    for (int i = 2; i <= temp; i++)
        for (int j = 0; j < l; j++)
        {
            int temp = 0;
            if (s[j] == 'i') { temp = 2; }
            if (s[j] == 'j') { temp = 3; }
            if (s[j] == 'k') { temp = 4; }
            mul[(i - 1) * l + j] = transform_ijk(mul[(i - 1) * l + j - 1], temp);
        }

    bool Geti = false;
    l *= temp;
    for (int i = 0; i < l; i++)
    if (mul[i] == 2)
    {
        Geti = true;
    } else
    if (mul[i] == 4)
    {
        if (Geti) { return true; }
    }
    return false;
}

int main()
{
    a[1][1] = 1; a[1][2] = 2; a[1][3] = 3; a[1][4] = 4;
    a[2][1] = 2; a[2][2] = -1; a[2][3] = 4; a[2][4] = -3;
    a[3][1] = 3; a[3][2] = -4; a[3][3] = -1; a[3][4] = 2;
    a[4][1] = 4; a[4][2] = 3; a[4][3] = -2; a[4][4] = -1;

    freopen("C-small-attempt7.in", "r", stdin);
    freopen("c.out", "w", stdout);
    int test;
    scanf("%d", &test);
    for (int t = 1; t <= test; t++)
    {
        printf("Case #%d: ", t);
        if (Work()) { printf("YES\n"); }
        else { printf("NO\n"); }
    }

    return 0;
}
