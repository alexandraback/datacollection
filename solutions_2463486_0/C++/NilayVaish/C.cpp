#include<cstdio>

long long int R[100];
int CC;

bool palindrome(long long int A)
{
    long long int B = A;
    long long int C = 0;
    while(B > 0)
    {
        C = C * 10;
        C += (B % 10);
        B /= 10;
    }

    return (C == A);
}

void precompute()
{
    CC = 0;
    for(long long int i = 1; i <= 20000000LL; ++i)
    {
        if(palindrome(i) && palindrome(i*i))
        {
            R[CC] = i*i;
            CC++;
        }
    }
}

int main()
{
    precompute();
    int T;
    scanf("%d\n", &T);

    for(int ii = 1; ii <= T; ++ii)
    {
        long long int A, B;
        scanf("%lld %lld\n", &A, &B);
        int res = 0;
        for(int i = 0; i < CC; ++i) if(R[i] >= A && R[i] <= B) res++;
        printf("Case #%d: %d\n",ii, res);
    }
    return 0;
}
