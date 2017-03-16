#include <iostream>
#include <cstdio>

#define MAX 99999
using namespace std;


double p[MAX];

int main(){
    int n, a, b;
    double x, product, minimum;
    scanf("%d", &n);
    for(int i = 0; i < n; i ++){
        scanf("%d %d", &a, &b);
        product = 1;
        for(int j = 0; j < a; j++){
            scanf("%lf", &x);
            product *= x;
            p[j] = product;
        }
        minimum = p[a-1] * (b-a+1) + (1-p[a-1])*(b-a+b+2);

        x = b+2;

        if(x < minimum) minimum = x;

        for(int j = 0; j < a; j++){
            if(a-j-2 < 0) break;
            x = p[a - j - 2] * ((j+1)*2 + b - a + 1) + (1 - p[a-j-2]) * ((j+1)*2 + b -a +1 +b+1);
            //if (j == 0) cout << x << endl;
            if(x < minimum) minimum = x;
        }

        printf("Case #%d: %lf\n", i+1, minimum);



    }

    return 0;
}
