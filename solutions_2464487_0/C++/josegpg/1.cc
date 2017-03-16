#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <map>

using namespace std;
long long r, t;
int test;

main () {
    long long res = 0;
    int proximo, resto;
    scanf("%d", &test);
    for(int i = 0; i < test; i++) {
        scanf("%lld %lld", &r, &t);
        res = 0;
        resto = t;
        proximo = ((r+1)*(r+1) - r*r);
        while (t >= proximo) {
            res++;
            t -= proximo;
            proximo += 4;
        }
        printf("Case #%d: %lld\n", i+1, res);
    }
}
