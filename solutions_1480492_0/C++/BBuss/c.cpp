#include<cstdio>

using namespace std;

typedef struct {
    int s;
    double p;
    int l;
} car;

int main(void){

    int t, n;
    car c[8];

    scanf("%d", &t);

    for(int i = 1; i <= t; ++i){

        scanf("%d", &n);

        for(int j = 0; j < n; ++j){
            char l;
            scanf(" %c %d %lf", &l, &c[j].s, &c[j].p);
            if(l == 'L') c[j].l = 1;
            else c[j].l = 0;
        }

        double tmp = 0.0;

        while(1){

            double min_t;
            int  min_c1 = -1;//, min_c2;

            for(int j = 0; j < n; ++j){

                for(int k = 0; k < n; ++k){
                    if(k == j || c[j].l != c[k].l || c[j].p >= c[k].p || c[j].s <= c[k].s)continue;

                    double min = (double)(c[k].p + - c[j].p - 5)/(c[j].s - c[k].s);
                    if(min_c1 == -1 || min < min_t){
                        min_t = min;
                        min_c1 = j;
                        //min_c2 = k;
                    }
                }
            }

            if(min_c1 == -1) { printf("Case #%d: Possible\n", i); break; }

            tmp += min_t;

            for(int j = 0; j < n; ++j){
                c[j].p += c[j].s * min_t;
            }

            int j;

            //Car min_c1 needs to pass min_c2...
            for(j = 0; j < n; ++j){
                if(c[min_c1].l == c[j].l) continue;

                if(c[min_c1].p >= c[j].p + 5 || c[min_c1].p + 5 <= c[j].p){
                    //Ok...
                }
                else{
                    //Will collide...
                    break;
                }
            }

            if(j == n){
                c[min_c1].l++;
                if(c[min_c1].l == 2)c[min_c1].l = 0;
            }
            else{
                printf("Case #%d: %f\n", i, tmp);
                break;
            }

        }

    }
    


    return 0;
}
