#include<cstdio>
#include<algorithm>

using namespace std;

int main(void){

    int t, a, b;
    double p, ps[100024];
    double minp;

    scanf("%d", &t);

    for(int i = 1; i <= t; ++i){

        scanf("%d %d", &a, &b);

        ps[0] = 1;

        minp = min(b+2, a + b + 1);

        for(int j = 1; j <= a; ++j){
            scanf("%lf", &p);
            ps[j] = ps[j-1] * p;

            double t1 = ((a-j) + (b - a + (a-j)) + 1);

            minp = min(minp, ps[j] * t1 + (1.0-ps[j]) * (t1 + b + 1));
        }

        printf("Case #%d: %.6f\n", i, minp);


    }




    return 0;
}
