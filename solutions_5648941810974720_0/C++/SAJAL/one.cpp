#include <bits/stdc++.h>

using namespace std;

#define sf scanf
#define pf printf
#define MAX 1000000007

char str[1000000];
int abc[28];
int num[12];

int main()
{
    freopen("input.txt" , "r" , stdin);
    freopen("output.in" , "w" , stdout);
    int t , len , cc = 0;
    sf("%d" , &t);
    while(t--)
    {
        sf("%s" , str);
        len = strlen(str);
        memset(abc , 0 , sizeof(abc));
        for(int i = 0 ; i < len ; ++i) abc[toupper(str[i]) - 'A']++;
        memset(num , 0 , sizeof(num));
        if(abc['Z' - 'A'] >= 1)
        {
            num[0] = abc['Z' - 'A'];
            abc['Z' - 'A'] -= num[0];
            abc['E' - 'A'] -= num[0];
            abc['R' - 'A'] -= num[0];
            abc['O' - 'A'] -= num[0];
        }
        if(abc['W' - 'A'] >= 1)
        {
            num[2] = abc['W' - 'A'];
            abc['T' - 'A'] -= num[2];
            abc['W' - 'A'] -= num[2];
            abc['O' - 'A'] -= num[2];
        }
        if(abc['G' - 'A'] >= 1)
        {
            num[8] = abc['G' - 'A'];
            abc['E' - 'A'] -= num[8];
            abc['I' - 'A'] -= num[8];
            abc['G' - 'A'] -= num[8];
            abc['H' - 'A'] -= num[8];
            abc['T' - 'A'] -= num[8];
        }
        if(abc['X' - 'A'] >= 1)
        {
            num[6] = abc['X' - 'A'];
            abc['S' - 'A'] -= num[6];
            abc['I' - 'A'] -= num[6];
            abc['X' - 'A'] -= num[6];
        }
        if(abc['U' - 'A'] >= 1)
        {
            num[4] = abc['U' - 'A'];
            abc['F' - 'A'] -= num[4];
            abc['O' - 'A'] -= num[4];
            abc['U' - 'A'] -= num[4];
            abc['R' - 'A'] -= num[4];
        }

        if(abc['H' - 'A'] >= 1)
        {
            num[3] = abc['H' - 'A'];
            abc['T' - 'A'] -= num[3];
            abc['H' - 'A'] -= num[3];
            abc['R' - 'A'] -= num[3];
            abc['E' - 'A'] -= num[3];
            abc['E' - 'A'] -= num[3];
        }
        if(abc['F' - 'A'] >= 1)
        {
            num[5] = abc['F' - 'A'];
            abc['F' - 'A'] -= num[5];
            abc['I' - 'A'] -= num[5];
            abc['V' - 'A'] -= num[5];
            abc['E' - 'A'] -= num[5];
        }
        if(abc['S' - 'A'] >= 1)
        {
            num[7] = abc['S' - 'A'];
            abc['S' - 'A'] -= num[7];
            abc['E' - 'A'] -= num[7];
            abc['V' - 'A'] -= num[7];
            abc['E' - 'A'] -= num[7];
            abc['N' - 'A'] -= num[7];
        }
        if(abc['O' - 'A'] >= 1)
        {
            num[1] = abc['O' - 'A'];
            abc['O' - 'A'] -= num[1];
            abc['N' - 'A'] -= num[1];
            abc['E' - 'A'] -= num[1];
        }
        if(abc['I' - 'A'] >= 1)
        {
            num[9] = abc['I' - 'A'];
            abc['N' - 'A'] -= num[9];
            abc['I' - 'A'] -= num[9];
            abc['N' - 'A'] -= num[9];
            abc['E' - 'A'] -= num[9];
        }
        pf("Case #%d: " , ++cc);
        for(int i = 0 ; i < 10 ; ++i)
        {
            if(num[i] > 0) while(num[i]--) pf("%d" , i);
        }
        pf("\n");
    }
    return 0;
}
