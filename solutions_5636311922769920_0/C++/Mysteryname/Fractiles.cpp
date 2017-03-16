/*
Google Code Jam 2016
Qualification Round
AUTHOR: Phawin Prongpaophan
TASK: Fractiles (Problem D)
*/

#include<stdio.h>
#include<algorithm>
#define LL long long
using namespace std;

LL k,c,s;
int selection[350];
LL pow[123];

void genpow()
{
    pow[0] = 1;
    pow[1] = k;
    for(int i=2;i<c;i++) pow[i] = pow[i-1]*k;
}

LL givemenum(int l)
{
    //printf("GiveMe <%d,%d>\n",l,l+c-1);
    LL ret = 0;
    for(int i=0;i<c;i++)
    {
        ret += selection[l+i]*pow[i];
    }
    return ret+1; //1-based index
}

void each(int tc)
{
    scanf("%lld%lld%lld",&k,&c,&s);
    printf("Case #%d: ",tc);
    if(c*s<k)
    {
        printf("IMPOSSIBLE\n"); return;
    }
    //Answer Exist
    //printf("POSSIBLE\n");
    //Set Selection
    for(int i=1;i<=k;i++) selection[i] = i-1;
    for(int i=k+1;i<350;i++) selection[i] = 0;
    genpow();
    //Go!
    int fidx = 1;
    while(true)
    {
        if(fidx>k) break;
        printf("%lld ",givemenum(fidx));
        fidx+=c;
    }
    printf("\n");
    return;
}

int main()
{
    freopen("InputD.in","r",stdin);
    freopen("OutputD.txt","w",stdout);
    int tcc; scanf("%d",&tcc);
    for(int tcnt=1;tcnt<=tcc;tcnt++)    each(tcnt);
    return 0;
}

