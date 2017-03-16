#include <iostream>
#include <stdio.h>
using namespace std;

int RevDigits(int k)
{
    int p=0;

    while(k>0)
    {
        p*=10;
        p+=k%10;
        k/=10;
    }

    return p;
}

int q[10000011];
int qL=0;
int dist[10000001];
bool TFO[10000001];

int main()
{
    freopen("A-small-attempt1.in","r",stdin);
    freopen("A-small-output.txt","w",stdout);

    int uk=1;
    int newnum;
    int t;
    int test;
    int n;
    int i;

    qL=1;
    q[1]=1;
    dist[1]=1;
    TFO[1]=true;

    while(uk<=qL)
    {
        newnum=q[uk]+1;

        if (newnum<10000000 && !TFO[newnum])
        {
            TFO[newnum]=true;
            qL++;
            q[qL]=newnum;
            dist[qL]=dist[uk]+1;
        }

        newnum=RevDigits(q[uk]);

        if (!TFO[newnum])
        {
            TFO[newnum]=true;
            qL++;
            q[qL]=newnum;
            dist[qL]=dist[uk]+1;
        }

        uk++;
    }

    scanf("%d",&t);

    for (test=1;test<=t;test++)
    {
        scanf("%d",&n);

        for (i=1;i<=qL;i++)
        {
            if (q[i]==n)
            {
                printf("Case #%d: %d\n",test,dist[i]);
                break;
            }
        }
    }

    return 0;
}
