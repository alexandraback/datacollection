#include <stdio.h>
#include <limits.h>

const int numbers[]=
{
    1,
    2,
    3,
    11,
    22,
    101,
    111,
    121,
    202,
    212,
    1001,
    1111,
    2002,
    10001,
    10101,
    10201,
    11011,
    11111,
    11211,
    20002,
    20102,
    100001,
    101101,
    110011,
    111111,
    200002,
    1000001,
    1001001,
    1002001,
    1010101,
    1011101,
    1012101,
    1100011,
    1101011,
    1102011,
    1110111,
    1111111,
    2000002,
    2001002
};

long long squ[100];

int bis(long long a)
{
    int i;
    for(i=0; i<=sizeof(numbers)/sizeof(int); i++) {
        if(squ[i]>a) return i-1;
    }
    return sizeof(numbers)/sizeof(int);
}

int main()
{
    int T, Tcnt=0;
    int i;
    for(i=0; i<sizeof(numbers)/sizeof(int); i++) {
        squ[i]=(long long)numbers[i]*numbers[i];
    }
    squ[i]=LLONG_MAX;
    for(scanf("%d", &T); T; T--) {
        long long a, b;
        scanf("%lld%lld", &a, &b);
        printf("Case #%d: %d\n", ++Tcnt, bis(b)-bis(a-1));
    }
    return 0;
}
