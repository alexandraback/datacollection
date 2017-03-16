#include<stdio.h>
#include<string.h>
int ispal (long long n)
{
    int a[101];
    int i, size;
    for (i=0; i<101; i++)
    a[i]=-1;
    i=0;
    while (n>0)
    {
          a[i++]=n%10;
          n/=10;
    }
    for (i=0; i<101; i++)
        if (a[i]==-1)
        {
           size=i;
           break;
        }
    int flag = 1;
    for (i=0; i<size/2; i++)
        if (a[i]!=a[size-1-i])
           flag = 0;
    if (flag == 1)
       return 1;
    return 0;
}
long long solve1 (long long a, long long b)
{
    long long i, count;
    count =0;
    for (i=a; i<b+1; i++)
    {
        if (ispal(i) && ispal(i*i))
        count++;
    }
    return count;
}

long long solve (long long A, long long B)
{
    long long a = sqrt(A);
    if (a*a < A) a++;
    long long b = sqrt(B);
    return solve1(a,b);
} 
int main ()
{
    FILE *fp1, *fp2;
    fp1 = fopen("C-small-attempt0.in", "r");
    fp2 = fopen("ans3.txt", "w");
    int i,T;
    long long A,B, ret;
    fscanf(fp1, "%d", &T);
    for (i=1; i<T+1; i++)
    {
        if (i>1) fprintf(fp2, "\n");
        fscanf(fp1, "%lld %lld", &A, &B);
        ret = solve(A, B);
        fprintf(fp2, "Case #%d: %lld", i, ret);
    }
    fclose(fp1);
    fclose(fp2);
} 
