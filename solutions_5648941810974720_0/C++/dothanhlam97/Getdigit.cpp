#include <bits/stdc++.h>

#define fi(a,b,c) for(int a=b; a<=c; a++)
#define fd(a,b,c) for(int a=b; a>=c; a--)

using namespace std;

int dd[300], a[30];

int tcase;
string S;

int main()
{
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
    scanf("%d\n" , &tcase);
    fi(t, 1, tcase)
    {
        for (char x = 'A'; x<= 'Z'; x++) dd[x] = 0;
        fi(i, 0, 9) a[i] = 0;
        char x;
        while (scanf("%c", &x) && x!= '\n')
            dd[x]++;


        a[2] = dd['W'];
        dd['T'] -= a[2]; dd['O'] -= a[2];

        a[0] = dd['Z'];
        dd['E'] -= a[0]; dd['R'] -= a[0]; dd['O'] -= a[0];

        a[6] = dd['X'];
        dd['S'] -= a[6]; dd['I'] -= a[6];

        a[7] = dd['S'];
        dd['E'] -= 2*a[7]; dd['V'] -= a[7]; dd['N'] -= a[7];

        a[5] = dd['V'];
        dd['F'] -= a[5]; dd['I'] -= a[5]; dd['E'] -= a[5];

        a[4] = dd['F'];
        dd['O'] -= a[4]; dd['U'] -= a[4]; dd['R'] -= a[4];

        a[3] = dd['R'];
        dd['T'] -= a[3]; dd['H'] -= a[3]; dd['E'] -= a[3] * 2;

        a[8] = dd['T'];
        dd['E'] -= a[8]; dd['I'] -= a[8]; dd['G'] -= a[8]; dd['H'] -= a[8];

        a[9] = dd['I'];
        a[1] = dd['O'];

    printf("Case #%d: ", t);

        fi(i, 0, 9)
        fi(j, 1, a[i]) cout <<i;
        cout <<endl;
    }

}
