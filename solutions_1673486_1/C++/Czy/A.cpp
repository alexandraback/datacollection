#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

const int MX = 100001;
int T, a, b;
double P[MX];
double res;
int cas = 1;
int main()
{
	//freopen("out.txt","w", stdout);
    scanf("%d", &T);
    
    while(T--)
    {
        scanf("%d %d", &a, &b);
        for(int i = 1;i <= a;i++)
            scanf("%lf", P+i);
        P[0] = 1;

        res = b+2;
 
        double ab = a+b;
        double abb = ab+b;

        double good = 1;

        for(int i = 0;i <= a;i++)
        {
            good *= P[i];

            double tmp = good * (ab-i-i+1) + (1-good) * (abb-i-i+2);

            if(tmp < res) res = tmp;
        }

        printf("Case #%d: %.6lf\n", cas++, res);
    }
}
