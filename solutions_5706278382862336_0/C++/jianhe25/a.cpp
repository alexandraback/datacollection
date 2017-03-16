#include <stdio.h>
#include <iostream>
using namespace std;

long long a, b;
int calc() {
    if (a == 0)
        return -1;
    int round = 0;
    int firstRound = -1;
    while (true) { 
        a *= 2;
        round++;
        if (round > 40)
            return -1;
        if (a >= b) {
            if (firstRound == -1)
                firstRound = round;
            if (a == b) {
                return firstRound;
            }
            a -= b;                
        }
    }    
    return -1;
}
int main() {
    int test;
    cin >> test;
    for (int cas = 1; cas <= test; ++cas) {
        scanf("%lld/%lld", &a, &b);
        int result = calc();
        printf("Case #%d: ", cas);
        if (result == -1)
            puts("impossible");
        else
            printf("%d\n", result);
    }
}














