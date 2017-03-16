#include <cstdio>
#include <cstdlib>
#include <string.h>

using namespace std;

int count[50];
char s[4005];
int num[20];

int main()
{
    int T;
    scanf("%d", &T);

    for(int _T = 1; _T <= T; _T++)
    {
        scanf("%s", s);
        int l = strlen(s);

        for(int i = 0; i < 26; i++)
            count[i] = 0;
        for(int i = 0; i < 10; i++)
            num[i] = 0;

        for(int i = 0; i < l; i++)
        {
            count[s[i] - 'A']++;
        }

        int t;
        //ZERO
        t = count['Z' - 'A'];
        num[0] += t;
        count['Z' - 'A'] -= t;
        count['E' - 'A'] -= t;
        count['R' - 'A'] -= t;
        count['O' - 'A'] -= t;

        //TWO
        t = count['W' - 'A'];
        num[2] += t;
        count['T' - 'A'] -= t;
        count['W' - 'A'] -= t;
        count['O' - 'A'] -= t;

        //FOUR
        t = count['U' - 'A'];
        num[4] += t;
        count['F' - 'A'] -= t;
        count['O' - 'A'] -= t;
        count['U' - 'A'] -= t;
        count['R' - 'A'] -= t;

        //SIX
        t = count['X' - 'A'];
        num[6] += t;
        count['S' - 'A'] -= t;
        count['I' - 'A'] -= t;
        count['X' - 'A'] -= t;
        
        //EIGHT
        t = count['G' - 'A'];
        num[8] += t;
        count['E' - 'A'] -= t;
        count['I' - 'A'] -= t;
        count['G' - 'A'] -= t;
        count['H' - 'A'] -= t;
        count['T' - 'A'] -= t;

        //
        //ONE
        t = count['O' - 'A'];
        num[1] += t;
        count['O' - 'A'] -= t;
        count['N' - 'A'] -= t;
        count['E' - 'A'] -= t;

        //THREE
        t = count['T' - 'A'];
        num[3] += t;
        count['T' - 'A'] -= t;
        count['H' - 'A'] -= t;
        count['R' - 'A'] -= t;
        count['E' - 'A'] -= t;
        count['E' - 'A'] -= t;

        //FIVE
        t = count['F' - 'A'];
        num[5] += t;
        count['F' - 'A'] -= t;
        count['I' - 'A'] -= t;
        count['V' - 'A'] -= t;
        count['E' - 'A'] -= t;

        //SEVEN
        t = count['S' - 'A'];
        num[7] += t;
        count['S' - 'A'] -= t;
        count['E' - 'A'] -= t;
        count['V' - 'A'] -= t;
        count['E' - 'A'] -= t;
        count['N' - 'A'] -= t;

        //NINE
        t = count['I' - 'A'];
        num[9] += t;
        count['N' - 'A'] -= t;
        count['I' - 'A'] -= t;
        count['N' - 'A'] -= t;
        count['E' - 'A'] -= t;

        printf("Case #%d: ", _T);

        for (int i = 0; i < 10; ++i)
        {
            for (int j = 0; j < num[i]; ++j)
            {
                printf("%d", i);
            }
        }

        printf("\n");

    }

}