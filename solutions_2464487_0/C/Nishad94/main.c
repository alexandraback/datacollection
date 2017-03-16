/*
ID: nishad.dawkhar94
PROG: bulleye
LANG: C
*/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

long long quad_solve(int a, int b, int c);

int main()
{
    FILE *in  = fopen ("test.in", "r");
    FILE *out = fopen ("test.out", "w");
    int tc, i=1;
    long long r,t,soln;
    long long a, b, c;
    fscanf(in,"%d",&tc);
    while(tc--)
    {
        fscanf(in,"%lli %lli",&r,&t);
        a = 2;
        b = ((2*r) - 1);
        c = (-1*t);
        soln = quad_solve(a,b,c);
        fprintf(out,"Case #%d: %lli\n",i++,soln);
    }
    return 0;
}

long long quad_solve(int a, int b, int c)
{
    long long result, x;
    //printf("a:%d b:%d c:%d\n",a,b,c);
    x = ((b*b) - (4*a*c));
   // printf("x = %lli\n",x);
    result = (-1*b) + (int)(sqrt(x));
    //printf("result*2a = %lli\n",result);
    result = result/(2*a);
    //printf("result = %lli\n",result);
    return result;
}
