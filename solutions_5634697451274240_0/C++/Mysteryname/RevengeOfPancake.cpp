/*
Google Code Jam 2016
Qualification Round
AUTHOR: Phawin Prongpaophan
TASK: Revenge of the Pancakes (Problem B)
*/

#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

char pan[111];
int n;

int getans(int bot,char want)
{
    if(bot==0)
    {
        if(pan[bot]==want) return 0; else return 1;
    }
    //Normal
    if(pan[bot]==want) return getans(bot-1,want);
    else return (1+getans(bot-1,pan[bot]));
}

void each(int tc)
{
    printf("Case #%d: ",tc);
    scanf("%s",pan);
    n = strlen(pan);
    printf("%d\n",getans(n-1,'+'));
    return;
}

int main()
{
    freopen("InputB.in","r",stdin);
    freopen("OutputB.txt","w",stdout);
    int tcc; scanf("%d",&tcc);
    for(int tcnt=1;tcnt<=tcc;tcnt++)    each(tcnt);
    return 0;
}

