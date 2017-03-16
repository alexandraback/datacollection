#include <stdlib.h>
#include <cstdio>
#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
#include <deque>
#define FOR(x,z) for(int x=0;x<(z);++x)
#define DS(i) fprintf(stderr, "DEBUG: %s\n",i);
#define DI(i) fprintf(stderr, "DEBUG: %d\n",i);
#define DF(i) fprintf(stderr, "DEBUG: %f\n",i);
#define LL long long
#define ULL unsigned long long
using namespace std;
int X,Y,minimum;
LL sum(int a1, int a2)
{
    return ((a1+a2)*(a2-a1+1)/2);
}
int ilekr(int a, int odl)
{
    int i=0,odl_t=a;

    while(1)
    {
        if(odl_t>odl)
        {
            i++;
            break;
        }
        if(odl_t==odl)
            break;
        i++;
        odl_t+=i+a;
    }
    return i;
}
void wczytaj()
{
    scanf("%d %d", &X, &Y);
}
void wykonaj()
{
    string wynik="";
    minimum=ilekr(0,abs(X)+abs(Y));
    //if(sum(1,minimum)%2&&!((abs(X)+abs(Y))%2))
    //   minimum++;
    int tmpA, tmpB,opcja1;
    if(abs(X)>abs(Y))
    {
        tmpA=abs(X);
        tmpB=abs(Y);
        opcja1=0;
    }
    else
    {
        tmpB=abs(X);
        tmpA=abs(Y);
        opcja1=1;
    }
    // w A wieksze
    vector<int> odp(minimum);

    //1,2 +- A, 3,4 +- B
    int odl=0,i=minimum;
    while(odl<tmpA&&i>0)
    {
        if(odl+i<=tmpA)
        {
            odl+=i;
            odp[i-1]=1;
        }
        i--;
    }
    odl=0;
    i=minimum;
    while(i>0)
    {
        if(odp[i-1]==0)
        {
            odp[i-1]=3;
            odl+=i;
        }
        i--;
    }
    int odlmax=odl;
    i=minimum;
    while(1)
    {
        i=odp.size();
        while(i>0)
        {
            if(odl==tmpB)
                break;
            if(odp[i-1]==3&&odl-2*i>=tmpB)
            {
                odp[i-1]=4;
                odl-=2*i;
            }
            i--;
        }
        if(odl==tmpB)break;
        FOR(j,odp.size())
            if(odp[j]==4)
                odp[j]=3;
        odp.push_back(3);
        odlmax+=odp.size();
        odl=odlmax;
    }
    /*if(odl!=tmpB)
    {
        odp.push_back(3);
        odp.push_back(4);
    }*/
    /*fprintf(stderr, "odp\n");
    FOR(j,odp.size())
    {
        fprintf(stderr, "%d, ", odp[j]);
    }
    fprintf(stderr, "\n");
    */int o;
    //opcja1=0 A-X b-Y
    if(opcja1==1)
    FOR(j,odp.size())
    {
        odp[j]+=1;
        odp[j]%=4;
        odp[j]++;
    }
    if(X<0)
    FOR(j,odp.size())
    {
        if(odp[j]==1)
            odp[j]=2;
        else if(odp[j]==2)
            odp[j]=1;
    }
    if(Y<0)
    FOR(j,odp.size())
    {
        if(odp[j]==3)
            odp[j]=4;
        else if(odp[j]==4)
            odp[j]=3;
    }
    FOR(j,odp.size())
    {
        o=odp[j];
        switch(o)
        {
        case 1:
            wynik+='E';
            break;
        case 2:
            wynik+='W';
            break;
        case 3:
            wynik+='N';
            break;
        case 4:
            wynik+='S';
            break;
        };
    }
    printf("%s\n", wynik.c_str());
    odp.clear();
}
int main()
{
    int T;
    scanf("%d",&T);
    for(int t=1;t<=T;t++)
    {
        wczytaj();
        DI(t)
        printf("Case #%d: ",t);
        wykonaj();
    }
    return 0;
}
