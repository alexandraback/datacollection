/*
 Qualification Round 2012 : Problem C. Recycled Numbers
*/

#include <stdio.h>
#include <iostream>
#include <math.h>

using namespace std;

int rotate(int i,int l,int a,int b)
{
    int out=0;
    int t=i;
    int p=pow(10.0,l);

    do {
        int d=t%10;
        t=t/10;
        t=p*d + t;
        if (t>i && t<=b) {
            out++;
        }
    } while (t!=i);
    return out;
}

int solve(int a,int b)
{
    int res=0;
    if (a>=10 && a<b) {
        int l=(int)floor(log10(a));
        int i;
        for (i=a; i<=b; i++) {
            if (int j=rotate(i,l,a,b)) {
                res+=j;
            }
        }

    }

    return res;
}

int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++) {
        int out=0,A,B;
        printf("Case #%d: ",i+1);
        scanf("%d%d",&A,&B);
        out=solve(A,B);
        printf("%d\n",out);
    }
    return 0;
}