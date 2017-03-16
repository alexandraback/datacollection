/*
Google Code Jam 2016
Round 1C
AUTHOR: Phawin Prongpaophan
*/

#include<stdio.h>
#include<algorithm>
using namespace std;

int j,p,s,k;

void each(int tc)
{
    scanf("%d%d%d%d",&j,&p,&s,&k);
    printf("Case #%d: ",tc);
    if(k==1)
    {
        printf("%d\n",p);
        for(int i=1;i<=p;i++) printf("1 %d %d\n",i,i);
    }
    if(k>=3)
    {
        printf("%d\n",j*p*s);
        for(int a1=1;a1<=j;a1++)
            for(int a2=1;a2<=p;a2++)
                for(int a3=1;a3<=s;a3++)
                    printf("%d %d %d\n",a1,a2,a3);
        return;
    }
    if(k==2)
    {
        s = min(2,s);
        printf("%d\n",j*p*s);
        for(int a1=1;a1<=j;a1++)
            for(int a2=1;a2<=p;a2++)
                for(int a3=1;a3<=s;a3++)
                    printf("%d %d %d\n",a1,a2,a3);
        return;
    }

    return;
}

int main()
{
    freopen("Cin.in","r",stdin);
    freopen("Cout.txt","w",stdout);
    int tcc; scanf("%d",&tcc);
    for(int tcnt=1;tcnt<=tcc;tcnt++)    each(tcnt);
    return 0;
}
