/*
Google Code Jam 2016
Round 1A
AUTHOR: Phawin Prongpaophan
*/

#include<stdio.h>
#include<algorithm>
using namespace std;

int n;
int c[3333];

void each(int tc)
{

    for(int i=0;i<3000;i++) c[i] = 0;
    scanf("%d",&n);
    for(int i=1;i<=2*n-1;i++)
    {
        for(int j=0;j<n;j++)
        {
            int w; scanf("%d",&w);
            c[w]++;
        }
    }
    printf("Case #%d: ",tc);
    for(int i=1;i<=2500;i++)
    {
        if(c[i]%2!=0) printf("%d ",i);
    }
    printf("\n");
    return;
}

int main()
{
    freopen("RankIn.in","r",stdin);
    freopen("RankOut.txt","w",stdout);
    int tcc; scanf("%d",&tcc);
    for(int tcnt=1;tcnt<=tcc;tcnt++)    each(tcnt);
    return 0;
}

