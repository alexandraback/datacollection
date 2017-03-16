#include <cstdio>
#include <algorithm>
#include <cstdlib>

using namespace std;

#define N 200
#define EPS 1e-9

int t, n;

long double res[N];
int c[N];
int sum;

bool isOk(long double v, int j){
    int counter = 0;
    int points = 0;

    for(int i = 0; i < n; i++){
        if(i == j){
            continue;
        }
        if(c[i] < c[j] + v * sum){
            points += c[i];
            counter++;
        }
    }


 //   printf("%Lf > %Lf\n",(points + (1-v)*sum), counter * (c[j] + v*sum));

    return (points + (1-v)*sum) < counter * (c[j] + v*sum);

}

long double abs2(long double a){
    if(a > 0){
        return a;
    }
    else{
        return -a;
    }
}

int main(){

    scanf("%d", &t);

    for(int i = 0; i < t; i++){
        scanf("%d", &n);

        sum = 0;
        for(int j = 0; j < n; j++){
            scanf("%d", c + j);
            sum += c[j];
        }


        for(int j = 0; j < n; j++){
            long double p = 0.0, k = 1.0;
            while(abs2(p - k) > EPS){
                long double h = (p + k)/2;
                if(isOk(h, j)){
                    k = h - EPS;
                }
                else{
                    p = h + EPS;
                }
            }

            res[j] = p;
        }

        printf("Case #%d:", i + 1);
        for(int j = 0; j < n; j++){
            printf(" %Lf", res[j] * 100);
        }
        printf("\n");
    }


    return 0;
}
