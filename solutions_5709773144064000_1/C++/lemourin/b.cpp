#include <cstdio>
#define scanf(args...) (scanf(args) ? : 0)

int main() {
    int t;
    scanf("%d", &t);
    
    for (int test=1; test<=t; test++) {
        double c, f, x;
        scanf("%lf%lf%lf", &c, &f, &x);

        double current = 0, speed = 2, time = 0;
        while (true) {
            current += c;
            time += c/speed;
            
            double t1 = (x-current)/speed;
            double t2 = (x-current+c)/(speed+f);

            if (t1 < t2) {
                time += t1;
                break;
            }
            else {
                current -= c;
                speed += f;
            }
        }

        printf("Case #%d: %.8lf\n", test, time);
    }
}
