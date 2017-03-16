#include <bits/stdc++.h>

using namespace std;

#define FILE_IO

int f[30];
char s[2005];
int v[30];

int main()
{
    #ifdef FILE_IO
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    #endif

    int T;
    scanf("%d\n", &T);
    for(int t = 1; t <= T; t++)
    {
        gets(s + 1);
        int N = strlen(s + 1);
        memset(f, 0, sizeof(f));
        for(int i = 1; i <= N; i++)
            f[ s[i] - 'A' ]++;

        v[0] = f['Z' - 'A'];
        v[2] = f['W' - 'A'];
        v[4] = f['U' - 'A'];
        v[6] = f['X' - 'A'];
        v[8] = f['G' - 'A'];
        v[3] = f['T' - 'A'] - v[2] - v[8];
        v[5] = f['F' - 'A'] - v[4];
        v[9] = f['I' - 'A'] - v[5] - v[6] - v[8];
        v[7] = f['S' - 'A'] - v[6];
        v[1] = f['O' - 'A'] - v[0] - v[2] - v[4];

        printf("Case #%d: ", t);
        for(int i = 0; i <= 9; i++)
            while(v[i]--)
                printf("%d", i);
        printf("\n");
    }

    return 0;
}
