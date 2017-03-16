#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int cuenta(int N)
{
    if (N<=20) {
        return N;
    }
    if ((N%10)==0)
        return 1 + cuenta(N-1);
    // go to 10...01
    char digits[20];
    sprintf(digits,"%d",N);
    int L=0;
    int base=1;
    while (N>base) {
        base*=10;
        L++;
    }
    // 10...01
    int total = cuenta((base/10)-1) + 2;
    // left side
    int left = 0;
    int i=0;
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
    int right = 0;
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
    int N;
    scanf("%d\n",&T);
    for (int t=1;t<=T;t++) {
        scanf("%d", &N);
        printf("Case #%d: %d\n", t, cuenta(N));
    }
    return 0;
}
