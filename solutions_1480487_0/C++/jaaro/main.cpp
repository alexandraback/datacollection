#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <set>
#include <boost/lexical_cast.hpp>
using namespace std;

int N, A[211], sum;

bool guaranteed_win(int x, double value, double left)
{
    for(int i=0; i<N; i++) if (x != i) {
        if (A[i] < value) left -= value - A[i];
    }
    return left < 0;
}

double calc(int x) {
    double min = 0, max = 1;
    for(int i = 0; i<100; i++) {
        double med = (min + max) / 2;
        double sumX = A[x] + med * sum;

        if (guaranteed_win(x, sumX, (1 - med) * sum)) max = med;
        else min = med;
    }
    return min;
}

int main()
{
    int numberOfCases;
    scanf("%d",&numberOfCases);
    for(int testNo=1; testNo<=numberOfCases; testNo++) {
        scanf("%d",&N);
        sum = 0;
        for(int i=0; i<N; i++) {
            scanf("%d",&A[i]);
            sum += A[i];
        }

        printf("Case #%d:", testNo);

        for(int i=0; i<N; i++) {
            printf(" %.6lf", 100 * calc(i));
        }

        puts("");
    }
}
