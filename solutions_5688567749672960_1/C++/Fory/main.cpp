#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int64_t cuenta(int64_t N)
{
    if (N<=20) {
        return N;
    }
    if ((N%10)==0)
        return 1 + cuenta(N-1);
    // go to 10...01
    char digits[20];
    sprintf(digits,"%lld",N);
    int64_t L=0;
    int64_t base=1;
    while (N>base) {
        base*=10;
        L++;
    }
    // 10...01
    int64_t total = cuenta((base/10)-1) + 2;
    // left side
    int64_t left = 0;
    int64_t i=0;
    base = 1;
    while (i<(L/2)) {
        left += base*(digits[i]-'0');
        base*=10;
        i++;
    }
    left-=1;
    total += left;
    // swap
    if (left!=0)
        total++;
    int64_t right = 0;
    while (i<L)
    {
        right*=10;
        right+=(digits[i]-'0');
        i++;
    }
    right-=1;
    return total+right;
}

int main()
{
    int T;
    int64_t N;
    cin >> T;
    for (int t=1;t<=T;t++) {
        cin >> N;
        printf("Case #%d: %d\n", t, cuenta(N));
    }
    return 0;
}
