#include <cstdio>
#include <algorithm>
#include <set>

using namespace std;

int ile[250], w[10];
char t[2005];

int main ()
{
    int a,b,c,d,e,f,g,n,z;

    scanf ("%d", &z);

    for (a=1; a<=z; a++)
    {
        scanf ("%s", t);

        for (b=0; t[b]; b++)
            ile[t[b]]++;

        while (ile['Z'])
        {
            ile['Z']--;
            ile['E']--;
            ile['R']--;
            ile['O']--;
            w[0]++;
        }

        while (ile['W'])
        {
            ile['T']--;
            ile['W']--;
            ile['O']--;
            w[2]++;
        }

        while (ile['X'])
        {
            ile['S']--;
            ile['I']--;
            ile['X']--;
            w[6]++;
        }

        while (ile['G'])
        {
            ile['E']--;
            ile['I']--;
            ile['G']--;
            ile['H']--;
            ile['T']--;
            w[8]++;
        }

        while (ile['S'])
        {
            ile['S']--;
            ile['E']--;
            ile['V']--;
            ile['E']--;
            ile['N']--;
            w[7]++;
        }

        while (ile['V'])
        {
            ile['F']--;
            ile['I']--;
            ile['V']--;
            ile['E']--;
            w[5]++;
        }

        while (ile['F'])
        {
            ile['F']--;
            ile['O']--;
            ile['U']--;
            ile['R']--;
            w[4]++;
        }

        while (ile['H'])
        {
            ile['T']--;
            ile['H']--;
            ile['R']--;
            ile['E']--;
            ile['E']--;
            w[3]++;
        }

        while (ile['O'])
        {
            ile['O']--;
            ile['N']--;
            ile['E']--;
            w[1]++;
        }

        while (ile['N'])
        {
            ile['N']--;
            ile['I']--;
            ile['N']--;
            ile['E']--;
            w[9]++;
        }

        printf ("Case #%d: ", a);

        for (b=0; b<10; b++)
            for (; w[b]; w[b]--)
                printf ("%d", b);

        printf ("\n");
    }

    return 0;
}
