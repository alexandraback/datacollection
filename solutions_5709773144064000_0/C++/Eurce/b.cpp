#include<cmath>
#include<queue>
#include<cstdio>
#include<cstring>
using namespace std;

#define eps 1e-8
#define M 1000000

int t,el;
double c,f,x,minti;

struct E
{
    double cp,ti;
}e[M];

void adde(double cp,double ti)
{
    e[el].cp=cp; e[el].ti=ti; el++;
}

void init()
{
    el=0;
    minti=1e30;
}

void solve()
{
    int i,j,k,l;
    double cp,ti;
    queue<int>Q;
    Q.push(el);
    adde(2,0);
    while(!Q.empty())
    {
        i=Q.front(); Q.pop();
        cp=e[i].cp; ti=e[i].ti;
        if(ti>minti-eps)
            continue;
        minti=min(minti,ti+x/cp);
        Q.push(el);
        adde(cp+f,ti+c/cp);
    }
    printf("Case #%d: %.7lf\n",++t,minti);
}

int main()
{
    scanf("%*d");
    while(~scanf("%lf%lf%lf",&c,&f,&x))
    {
        init();
        solve();
    }
    return 0;
}
