#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
typedef long long Int;

Int ABS(Int a)
{
    if (a<0LL)
    return -a;
    else
    return a;
}

int t;
char A[21];
char B[21];
int n;

Int vA,vB;

Int mindif=-1;
Int minvA,minvB;

char curA[21];
char curB[21];

char ansA[21];
char ansB[21];

void GetDif()
{
    int i;

    vA=0;
    vB=0;

    for (i=1;i<=n;i++)
    {
        vA*=10LL;
        vA+=(Int)(curA[i]-'0');

        vB*=10LL;
        vB+=(Int)(curB[i]-'0');
    }

    return;
}

void Solve(int k,int status)
{
    int i,v;

    if (k==n+1)
    {
        GetDif();

        if (mindif==-1 || ABS(vA-vB)<mindif || (ABS(vA-vB)==mindif && make_pair(vA,vB)<make_pair(minvA,minvB)) )
        {
            mindif=ABS(vA-vB);

            minvA=vA;
            minvB=vB;

            for (i=1;i<=n;i++)
            {
                ansA[i]=curA[i];
                ansB[i]=curB[i];
            }
        }

        return;
    }

    if (status==0)
    {
        if (A[k]=='?' && B[k]=='?')
        {
            curA[k]='0';
            curB[k]='0';

            Solve(k+1,0);

            curA[k]='0';
            curB[k]='1';

            Solve(k+1,1);

            curA[k]='1';
            curB[k]='0';

            Solve(k+1,2);
        }
        else if (A[k]=='?')
        {
            curB[k]=B[k];
            v=B[k]-'0';

            curA[k]=B[k];

            Solve(k+1,0);

            if (v-1>=0)
            {
                curA[k]=(v-1)+'0';

                Solve(k+1,1);
            }

            if (v+1<=9)
            {
                curA[k]=(v+1)+'0';

                Solve(k+1,2);
            }
        }
        else if (B[k]=='?')
        {
            curA[k]=A[k];
            v=A[k]-'0';

            curB[k]=A[k];

            Solve(k+1,0);

            if (v-1>=0)
            {
                curB[k]=(v-1)+'0';

                Solve(k+1,2);
            }

            if (v+1<=9)
            {
                curB[k]=(v+1)+'0';

                Solve(k+1,1);
            }
        }
        else
        {
            curA[k]=A[k];
            curB[k]=B[k];

            if (A[k]==B[k])
            Solve(k+1,0);
            else if (A[k]<B[k])
            Solve(k+1,1);
            else
            Solve(k+1,2);
        }
    }
    else if (status==1)
    {
        if (A[k]=='?')
        curA[k]='9';
        else
        curA[k]=A[k];

        if (B[k]=='?')
        curB[k]='0';
        else
        curB[k]=B[k];

        Solve(k+1,status);
    }
    else
    {
        if (A[k]=='?')
        curA[k]='0';
        else
        curA[k]=A[k];

        if (B[k]=='?')
        curB[k]='9';
        else
        curB[k]=B[k];

        Solve(k+1,status);
    }

    return;
}

int main()
{
    freopen("B-large.in","r",stdin);
    freopen("B-large.out","w",stdout);

    int test;
    int i;

    scanf("%d",&t);

    for (test=1;test<=t;test++)
    {
        mindif=-1;

        scanf("%s",A+1);
        scanf("%s",B+1);
        n=strlen(A+1);

        Solve(1,0);

        printf("Case #%d: ",test);

        for (i=1;i<=n;i++)
        {
            printf("%c",ansA[i]);
        }
        printf(" ");
        for (i=1;i<=n;i++)
        {
            printf("%c",ansB[i]);
        }
        printf("\n");
    }

    return 0;
}
