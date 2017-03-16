#include<bits/stdc++.h>

using namespace std;

int N, sol[10], ap[30];
char sir[2016];

int getap (char c)
{
    return ap[c - 'A'];
}

int main ()
{
freopen ("input", "r", stdin);
freopen ("output", "w", stdout);

int Tests;
scanf ("%d\n", &Tests);
for (int test_id = 1; test_id <= Tests; test_id ++)
{
    printf ("Case #%d: ", test_id);
    gets (sir + 1), N = strlen (sir + 1);
    for (int i=0; i<26; i++)
        ap[i] = 0;
    for (int i=1; i<=N; i++)
        ap[sir[i] - 'A'] ++;
    sol[0] = getap ('Z'), sol[6] = getap ('X'), sol[4] = getap ('U'), sol[2] = getap ('W'), sol[8] = getap ('G');
    sol[7] = getap ('S') - sol[6], sol[5] = getap ('F') - sol[4], sol[3] = getap ('H') - sol[8];
    sol[1] = getap ('O') - sol[0] - sol[2] - sol[4], sol[9] = getap ('I') - sol[5] - sol[6] - sol[8];
    for (int i=0; i<10; i++)
        for (int j=1; j<=sol[i]; j++)
            printf ("%d", i);
    printf ("\n");
}

return 0;
}
