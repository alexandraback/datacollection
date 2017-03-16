/*
    By Yemeli Tasse Cyrille
    http://yemelitc.org
    Date: 11 May 2014
*/


#include<stdio.h>

long long gcd (long long P, long long Q)
{
    if(Q==0) return P;
    return gcd (Q, P%Q);
}

int main()
{
    int i, j;
    int Case, T;
    char string[100];

    int ans;
    long long f, P, Q;

    FILE *output = fopen("A-small-attempt0.out", "w");
    FILE *input = fopen("A-small-attempt0.in", "r");
    fscanf(input, "%d", &T);

    for(Case=1; Case<=T; Case++)
    {
        fscanf(input, "%lld/%lld", &P, &Q);
        //printf("P=%lld Q=%lld\n", P, Q);

        if(P>Q)
        {
            fprintf(output, "Case #%d: impossible\n", Case);
            printf("Case #%d: impossible\n", Case);
            continue;
        }

        if(P==Q || P==0)
        {
            fprintf(output, "Case #%d: 1\n", Case);
            printf("Case #%d: 1\n", Case);
            continue;
        }
        
        f = gcd(P, Q);
        P /= f;
        Q /= f;
        //printf("f=%lld Q=%lld\n", f, Q);
        
        for(i=0, f=Q; f%2 == 0; f/=2, i++);     // Q = 2^k, get k

        f /= 2;
        if(f != 0)              // if Q != 2^k, then is invalid
        {
            fprintf(output, "Case #%d: impossible\n", Case);
            printf("Case #%d: impossible\n", Case);
            continue;
        }

        for(j=0, f=P; f != 0; f/=2, j++);       // get number of digits of P

        ans = i+1-j;

        if(ans==0) ans=1;
        fprintf(output, "Case #%d: %d\n", Case, ans);
        printf("Case #%d: %d\n", Case, ans);
    }

    fclose(input);
    fclose(output);
}

