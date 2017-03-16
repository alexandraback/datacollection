#include <iostream>
#include <stdio.h>

using namespace std;

void process(void) {
    double c, f, x, ct, rate = 2, result = 0;
    scanf("%lf %lf %lf", &c, &f, &x);
    ct = c / rate;

    while(x > (c/f * (rate+f))) {
        result += ct;
        rate += f;
        // cout << ct << " traded for new rate " << rate << endl;
        ct = c / rate;
    }
    result += x/rate;
    printf("%.7lf\n", result);

}

int main(void)
{
    int T;
    scanf("%d", &T);
    for(int i=1;i<=T;i++) {
        printf("Case #%d: ", i);
        process();
    }
}