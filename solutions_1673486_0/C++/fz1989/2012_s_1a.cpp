#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cmath>
using namespace std;
int T, A, B;
double p[100000], mul[100000];

double calc(double mul[], int i , int A, int B) {
       double tmp = B - A + 1 + i * 2;
       return tmp * mul[A - i] + (1- mul[A - i]) * (tmp + B + 1);

}


int main()
{
    scanf("%d", &T);
    freopen("test.out", "w",stdout);
    for (int cas = 1; cas <= T; cas++) {
        scanf("%d %d", &A, &B);
        mul[0]= 1.0;
        for (int i = 0; i < A; i++) {
            scanf("%lf", p + i);
            mul[i + 1] = mul[i] * p[i]; 
        }
        double ret = 1e20;
        for (int i = 0; i <= A; i++) {
            ret = min(ret, calc(mul, i, A, B));
        }
        printf("Case #%d: %.6lf\n",cas, min(ret, B + 2.0));
    }
}
