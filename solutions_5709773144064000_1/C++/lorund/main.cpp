#include <cstdio>

int T;
double C, F, X;

int main()
{
    freopen("txt.in", "r", stdin);
    freopen("txt.out", "w", stdout);

    scanf("%d", &T);
    for (int t=1; t<=T; ++t){
        double min, prod=2, temp=0;

        scanf("%lf %lf %lf", &C, &F, &X);
        min = X;
        printf("Case #%d: ", t);
        for (int i=0; i<X; ++i){
            if (X/prod+temp < min){
                min = X/prod+temp;
            }
            temp += C/prod;
            prod += F;
        }
        printf("%.7f\n", min);
    }
    return 0;
}

