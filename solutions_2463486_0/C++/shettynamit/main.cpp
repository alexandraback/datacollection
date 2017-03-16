#include <iostream>
#include <cstdio>
#include <cmath>
#define LIM 10000000
using namespace std;

typedef long long LL;
int S[LIM+1];

int isPalin(LL x)
{
    int digs[20],c=0;
    LL y = x;
    while(y>0)
    {
        digs[c]=y%10;
        c++;
        y/=10;
    }
    int s=0;
    c--;
    while(c>s)
    {
        if(digs[c]!=digs[s])
            return 0;
        s++;
        c--;
    }
    return 1;
}

void init(int lim) {
    LL i;
    S[0]=0;
    for(i=1;i<=lim;i++)
    {
        S[i]=S[i-1];
        if(isPalin(i*i)&&isPalin(i))
            S[i]++;
    }
}

int main()
{
    int a,b;
    int t;
    init(LIM);
    freopen("small.in","r",stdin);
    freopen("small.out","w",stdout);
    scanf("%d",&t);
    for(int casenum=1;casenum<=t;casenum++)
    {
        scanf("%d%d",&a,&b);
        //printf("Case #%d: %d %d %d %d %d\n",casenum,(int)sqrt(b+0.1),(int)sqrt(a-0.1),S[(int)sqrt(b+0.1)],S[(int)sqrt(a-0.1)],S[(int)sqrt(b+0.1)]-S[(int)sqrt(a-0.1)]);
        printf("Case #%d: %d\n",casenum,S[(int)sqrt(b+0.1)]-S[(int)sqrt(a-0.1)]);
    }
    return 0;
}
