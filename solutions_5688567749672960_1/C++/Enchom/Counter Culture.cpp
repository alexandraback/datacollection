#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
typedef long long Int;

int t;
Int n;

Int Digs[21];
int L=0;

int main()
{
    freopen("A-large.in","r",stdin);
    freopen("A-large-output.txt","w",stdout);

    int i;
    int test;
    int D;
    int cut;
    Int moves,p1,p2;
    Int FirstNum,SecondNum;

    scanf("%d",&t);

    for (test=1;test<=t;test++)
    {
        scanf("%lld",&n);

        L=0;
        while(n>0)
        {
            L++;
            Digs[L]=n%10;
            n/=10;
        }

        reverse(Digs+1,Digs+1+L);

        if (L==1)
        {
            printf("Case #%d: %lld\n",test,Digs[1]);
            continue;
        }

        moves=10;
        p1=9;
        p2=10;
        for (D=2;D<L;D++)
        {
            moves+=p1+p2;

            if (p1<p2)
            {
                p1*=10LL;
                p1+=9LL;
            }
            else
            {
                p2*=10LL;
            }
        }

        cut=L/2;

        FirstNum=0;
        SecondNum=0;
        for (i=cut;i>=1;i--)
        {
            FirstNum*=10LL;
            FirstNum+=(Int)Digs[i];
        }
        for (i=cut+1;i<=L;i++)
        {
            SecondNum*=10LL;
            SecondNum+=(Int)Digs[i];
        }

        if (FirstNum==1) ///no flips
        {
            moves+=SecondNum;
        }
        else if (SecondNum!=0)
        {
            moves+=FirstNum+SecondNum;
        }
        else
        {
            Digs[1]--;

            p1=0;
            for (i=1;i<=L;i++)
            {
                p1*=10LL;
                p1+=(Int)Digs[i];
            }

            Digs[1]++;

            ///

            FirstNum=0;
            SecondNum=0;
            for (i=cut+1;i<=L;i++)
            {
                Digs[i]=9LL;
                SecondNum*=10LL;
                SecondNum+=(Int)Digs[i];
            }

            Digs[cut]--;
            for (i=cut;i>=1;i--)
            {
                if (Digs[i]<0)
                {
                    Digs[i]+=10LL;
                    Digs[i-1]--;
                }

                FirstNum*=10LL;
                FirstNum+=(Int)Digs[i];
            }

            p2=FirstNum+SecondNum+1LL;

            if (p1<p2)
            moves+=p1;
            else
            moves+=p2;
        }

        printf("Case #%d: %lld\n",test,moves);
    }

    return 0;
}
