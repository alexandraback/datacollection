#include <iostream>
#include <cstdio>

using namespace std;

int T;
double C, F, X;
double opt; double now; int num;

int main()
{
    //freopen("B-large.in", "r", stdin);
    //freopen("B-large.out", "w", stdout);

    scanf("%d", &T);

    for(int Ti = 1; Ti <= T; Ti++)
    {
        scanf("%lf %lf %lf", &C, &F, &X);

        num = 0; now = 0; opt = X/2;

        while(1)
        {
            if( opt < now+C/(2+num*F)+X/(2+num*F+F) ) break;
            opt = now+C/(2+num*F)+X/(2+num*F+F);
            now += C/(2+num*F);
            num++;
        }

        printf("Case #%d: %.7lf\n", Ti, opt);
    }
}
