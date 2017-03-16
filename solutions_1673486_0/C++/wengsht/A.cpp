#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

const int MX = 100001;
int T, A, B;
double P[MX];
double result;
//#define HOME
//#define small
//#define large
int main()
{
#ifdef HOME
    freopen("1.txt", "r", stdin);
#endif
#ifdef small
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("out", "w", stdout);
#endif
#ifdef large
    freopen("1.txt","r",stdin);
    freopen("out", "w", stdout);
#endif

    scanf("%d", &T);
    int _case = 1;
    while(T--)
    {
        scanf("%d %d", &A, &B);

        for(int i = 1;i <= A;i++)
            scanf("%lf", P+i);
        P[0] = 1;

        result = B+2;

        double AB = A+B;
        double ABB = AB+B;

        double good = 1;

        for(int i = 0;i <= A;i++)
        {
            good *= P[i];

            double tmp = good * (AB-i-i+1) + (1-good) * (ABB-i-i+2);

            if(tmp < result) result = tmp;
        }

        printf("Case #%d: %.6lf\n", _case++, result);
    }
}
