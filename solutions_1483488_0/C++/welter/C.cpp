#include <iostream>
#include <cstdio>
#include <set>

using namespace std;

int a, b;
int pow10[10];
set< pair<int, int> > counter;

int digits(int number) {

    int res = 0;

    while (number) {
        number /= 10;
        res++;
    }

    return res;
}

int recycle(int number, int dig) {

    int r = number % 10;
    return r * pow10[dig-1] + number / 10;
}

void check(int number) {

    int dig = digits(number);
    int starting = number;

    for (int i = 0; i < dig - 1; ++i) {

        number = recycle(number, dig);

        if (digits(number) != dig || number == starting)
            continue;

        if (number >= a && number <= b)
            counter.insert( make_pair( min(number, starting), max(number, starting) ) );
    }
}

void init() {

    pow10[0] = 1;

    for (int i = 1; i < 10; ++i)
        pow10[i] = pow10[i-1] * 10;
}

int main() {

    int tests;

    init();

    scanf("%d", &tests);

    for (int i = 0; i < tests; ++i) {

        scanf("%d %d", &a, &b);
        
        for (int j = a; j <= b; ++j)
            check(j);

        printf("Case #%d: %d\n", i + 1, counter.size());
        counter.clear();
    }

    return 0;
}