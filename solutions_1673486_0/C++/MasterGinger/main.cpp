#include <stdio.h>
#include <memory.h>
double min(double a, double b) {
    return a < b ? a : b;
}
int main() {
    int t, a, b;
    double p[100000], result, correctP;
    double keepTyping = 0.0, pressEnter = 0.0, pressBackspace[100000];
    scanf("%d", &t);
    for (int nt = 1; nt <= t; nt++) {
        keepTyping = 0.0;
        pressEnter = 0.0;
        memset(pressBackspace, 0, sizeof(pressBackspace));
        correctP = 1.0;
        scanf("%d%d", &a, &b);
        for (int i = 0; i < a; i++) {
            scanf("%lf", &p[i]);
            correctP *= p[i];
        }
        
        int upper = 1 << a;

        for (int i = 0; i < upper; i++) {
            int temp = i, counter = a;
            double currentP = 1.0;
            while (counter-- > 0) {
                if (temp % 2 == 0) {
                    currentP *= p[counter];
                }
                else {
                    currentP *= 1.0 - p[counter];
                }
                
                temp /= 2;
            }
            
            // keep typing
            if (i != 0) {
                keepTyping += currentP * (double)(b - a + 1 + b + 1);
            }
            else {
                keepTyping += currentP * (double)(b - a + 1);
            }
            // backspace
            for (int j = 1; j <= a; j++) {
                if ((i >> j) == 0) { // correct
                    pressBackspace[j - 1] += currentP * (double)(j + b - (a - j) + 1);
                }
                else {
                    pressBackspace[j - 1] += currentP * (double)(j + b - (a - j) + 1 + b + 1);
                }
            }
            
            // hit enter
            if (i != 0) {
                pressEnter += currentP * (1 + b + 1);
            }
            else {
                if (a == b) {
                    pressEnter += currentP * 1.0;
                }
                else {
                    pressEnter += currentP * (1 + b + 1);
                }
            }
        }
        result = min(keepTyping, pressEnter);
        for (int j = 0; j < a; j++) {
            result = min(result, pressBackspace[j]);
        }
        
        printf("Case #%d: %.06lf\n", nt, result);
    }
    return 0;
}
