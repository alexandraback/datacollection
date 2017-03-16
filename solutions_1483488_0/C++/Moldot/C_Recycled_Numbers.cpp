/*  Grader: Codejam - Qualification Round 2012
    C Recycled Numbers
    Varot Premtoon 14 Apr 2555 */

#include <cstdio>

int ab[10000000];

int sol(int cse)
{
    int i,j;
    int a,b;
    int x,y,num[10],n;
    long long sum = 0;
    scanf("%d %d",&a,&b);
    for(;a<=b;a++) {
        x = a;
        for(n=0;x>0;x/=10) num[n++] = x%10;
        for(j=0,y=0;j<n;j++) {
            for(i=j,x=0;i<j+n;i++) x = (x*10) + num[i%n];
            if(x>y) y = x;
        }
        //printf("%d = %d\n",a,y);
        ab[y]++;
    }
    for(i=0;i<1000000;i++) {
        sum += (long long)(ab[i]*(ab[i]-1)) / 2;
        ab[i] = 0;
    }
    printf("Case #%d: %I64d\n",cse,sum);
    return 0;
}


int main()
{
    int t,i;
    scanf("%d",&t);
    for(i=0;i<10000000;i++) ab[i] = 0;
    for(i=1;i<=t;i++) sol(i);
    return 0;
}
