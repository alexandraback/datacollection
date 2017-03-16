#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

int main()
{
    FILE * f1;
    FILE * f2;
    f1=fopen("a.in","r");
    f2=fopen("a.txt","w");
    int nn;
    fscanf(f1,"%d",&nn);
    for(int i=0;i<nn;i++)
    {
        int qcoin,coincnt,vmax,tot=0;
        int coins[102]={0,};

        fscanf(f1,"%d%d%d",&qcoin,&coincnt,&vmax);

        for(int j=0;j<coincnt;j++)
        {
            fscanf(f1,"%d",&coins[j]);
        }
        if(i==41)
        {
            printf("%d %d %d\n",qcoin,coincnt,vmax);

        for(int j=0;j<coincnt;j++)
        {
            printf("%d ",coins[j]);
        }
        }
        int now=qcoin;
        int cs=0;
        if(coins[0]==1){cs=1;}
        else {tot++;}
        int vc=0,vj=1;
        for(int j=cs;;j++)
        {
            if(now>=vmax){break;}
            int chk=0;

            if(j>=coincnt||now+1<coins[j])
            {
                tot++;
                j--;
                int tmp=now+1;
                for(int k=0;k<qcoin;k++)
            {
                now+=tmp;
                if(now>=vmax){chk=1;break;}
            }
            }
            else{
            for(int k=0;k<qcoin;k++)
            {
                now+=coins[j];
                if(now>=vmax){chk=1;break;}
            }
            }

            if(chk==1){break;}
        }

        fprintf(f2,"Case #%d: %d\n",i+1,tot);
    }
    return 0;
}
