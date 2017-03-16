/*
Google Code Jam 2016
Qualification Round
AUTHOR: Phawin Prongpaophan
TASK: Counting Sheep (Problem A)
*/

#include<stdio.h>
#include<algorithm>
#define LL long long
using namespace std;

LL n;
LL cur = 0;
bool ok[13];

bool ac()
{
    for(int i=0;i<10;i++)
        if(!ok[i]) return false;
    return true;
}

void reset()
{
    cur = 0;
    for(int i=0;i<10;i++) ok[i] = false;
    return;
}

void addit(LL x)
{
    while(x>0)
    {
        ok[x%10]= true;
        x/=10;
    }
    return;
}

void each(int tc)
{
    printf("Case #%d: ",tc);
    reset();
    scanf("%lld",&n);
    if(n==0) {printf("INSOMNIA\n"); return;}
    while(true)
    {
        cur+= n;
        addit(cur);
        if(ac())
        {
            printf("%lld\n",cur); return;
        }
    }
    return;
}



int main()
{
    freopen("InputA.in","r",stdin);
    freopen("OutputA.txt","w",stdout);
    int tcc; scanf("%d",&tcc);
    for(int tcnt=1;tcnt<=tcc;tcnt++)    each(tcnt);
    return 0;
}
