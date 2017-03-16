#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <string>
#include <cstdlib>
#include <set>
#include <map>
#include <algorithm>
#include <ctime>
using namespace std;


#define forn(i, n) for(int i = 0; i < n; i++)


int t, a, b;
double p[99999];
double best, now, cont, now2;
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> t;
    for(int test = 1; test <= t; test++)
    {
        best = 1000000000;
        cin >> a >> b;
        best = b + 2;
        now = 1;
        forn(i, a)
        {
            cin >> p[i];
            now *= p[i];
        }
        cont = (b + 1 - a) * now + (2 * b + 2 - a) * (1.0 - now);
        if(best > cont) best = cont;
        now2 = 1;
        forn(i, a - 1)
        {
            now2 *= p[i];
            best = min(best, now2 * ((a - i - 1) * 2 + b - a + 1) + (1.0 - now2) * ((a - i - 1) * 2 + b - a + 1 + b + 1));
            //cout <<  now2 << ' ' << now2 * ((a - i - 1) * 2.0 + b - a + 1) + (1.0 - now2) * ((a - i - 1) * 2.0 + b - a + 1.0 + b + 1.0) << endl;
        }
        printf("Case #%d: %.6f\n", test, best);
    }
}
