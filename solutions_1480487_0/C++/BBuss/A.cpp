#include<cstdio>

using namespace std;

int sum;
int p[256];

inline bool isOk(int a, int b, double pa, double pb){

    double sc_a = p[a] + sum * pa;
    double sc_b = p[b] + sum * pb;

    //printf("%d %d, %.6f, %.6f %.6f\n", a, b, pa, sc_a, sc_b);

    return (sc_a >= sc_b);
}

int main(void){

    int t, n, pt;

    scanf("%d", &t);

    for(int i = 1; i <= t; ++i){

        sum = 0;
        scanf("%d", &n);

        for(int j = 0; j < n; ++j){

            scanf("%d", &pt);
            p[j] = pt;
            sum += pt;

        }

        printf("Case #%d:", i);

        //printf("\nsum = %d\n", sum);

        for(int j = 0; j < n; ++j){

            double sb = 0.0, eb = 1.0;
            double m;

            for(int z = 0; z < 1000; ++z){ 


                m = (sb + eb)/2.0;
                //printf("(%.6f)->", m);

                double om2 = (double)(1.0-m);

                double tr = p[j] + sum * m;
                double sm = 0.0;

                for(int k = 0; k < n; ++k){
                    if(k == j) continue;

                    double trt = (double)(tr - p[k])/sum;
                    if(trt >= 0) sm += trt;
                }

                if(sm <= om2){ //Tem que aumentar a %
                    sb = m;
                }
                else{
                    eb = m;
                }

            }

            printf(" %.6f", m * 100.0);

        }

        printf("\n");

    }

    return 0;
}
