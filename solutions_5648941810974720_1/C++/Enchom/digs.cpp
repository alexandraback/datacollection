#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

int ctr[511];
char S[21111];
int n;
int t;

int number[11];

void Remove(string s,int val)
{
    int i;

    for (i=0;i<s.length();i++)
    {
        ctr[ s[i] ]-=val;
    }

    return;
}

int main()
{
    freopen("A-large.in","r",stdin);
    freopen("A-large.out","w",stdout);

    int test;
    int i,j;
    int val;

    scanf("%d",&t);

    for (test=1;test<=t;test++)
    {
        scanf("%s",S+1);
        n=strlen(S+1);
        memset(ctr,0,sizeof(ctr));
        memset(number,0,sizeof(number));

        for (i=1;i<=n;i++)
        {
            ctr[ S[i] ]++;
        }

        number[0]=ctr['Z'];
        Remove("ZERO",number[0]);

        number[6]=ctr['X'];
        Remove("SIX",number[6]);

        number[2]=ctr['W'];
        Remove("TWO",number[2]);

        number[8]=ctr['G'];
        Remove("EIGHT",number[8]);

        number[4]=ctr['U'];
        Remove("FOUR",number[4]);

        number[3]=ctr['R'];
        Remove("THREE",number[3]);

        number[5]=ctr['F'];
        Remove("FIVE",number[5]);

        number[1]=ctr['O'];
        Remove("ONE",number[1]);

        number[7]=ctr['S'];
        Remove("SEVEN",number[7]);

        number[9]=ctr['I'];
        Remove("NINE",number[9]);

        printf("Case #%d: ",test);
        for (i=0;i<=9;i++)
        {
            for (j=1;j<=number[i];j++)
            {
                printf("%d",i);
            }
        }
        printf("\n");
    }

    return 0;
}
