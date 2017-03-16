#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
#include<algorithm>
#include<string>
#include<stack>
#include<cstring>
#include<utility>
#include<cmath>
#include<queue>
#include<cstdlib>

using namespace std;

#define LL long long
#define REP(i,a,b) for(int i = a;i<b;i++)
#define REP0(i,b) REP(i,0,b)
#define PB(x) push_back(x)
#define MP(x,y) make_pair(x,y)
#define MAXN 1000000000000000LL
vector<LL>FAIR;
vector<LL>::iterator vit;

bool isPALIN(LL x)
{
    LL temp = x;
    LL sum = 0;
    while(temp)
    {
        int r = temp%10;
        sum = sum * 10 +r;
        temp/=10;
    }
    if(x == sum)
        return true;
    else
        return false;
}



void PREPROCESS()
{
    LL inc = 3;
    for(LL i = 1;i<MAXN;)
    {
        if(isPALIN(i) && isPALIN((LL)sqrt(i)))
            FAIR.PB(i);
        i = i+inc;
        inc +=2;
    }
//    for(vit = FAIR.begin();vit!=FAIR.end();vit++)
//        cout<<*vit<<endl;
}



int main()
{

    freopen("C-small-attempt0.in","r",stdin);
    freopen("C-small-attempt0.out","w",stdout);
    PREPROCESS();
    int CASES,TEST = 0;
    LL A,B,total;
    scanf("%d",&CASES);
    while(TEST<CASES)
    {
        total = 0;
        scanf("%lld %lld",&A,&B);
        vit = FAIR.begin();
        while(*vit<A)vit++;
        for(;*vit<=B;vit++)
        {
            total++;
        }
        printf("Case #%d: %lld\n",TEST+1,total);
        TEST++;
    }
}
