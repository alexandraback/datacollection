#include <cstdio>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <set>
#include <algorithm>
#include <map>
#include <bitset>
#include <vector>
#include <queue>
#include <stack>
#include <utility>
#include <functional>
#include <sstream>
#include <list>
#include <complex>

#define maxlongint 2147483647
#define biglongint 2139062143
#define LL long long
#define ULL unsigned long long
#define p_b push_back
#define m_p make_pair
#define l_b lower_bound
#define w1 first
#define w2 second

using namespace std;

typedef pair<int,int> PII;
typedef pair<pair<int,int>,int> PIII;
typedef pair<pair<int,int>,pair<int,int> > PIIII;
typedef pair<double,double> PDD;
typedef pair<double,int> PDI;
typedef pair<string,int> PSI;
typedef pair<pair<double,double>,double> PDDD;
typedef pair<pair<double,double>,pair<double,double> > PDDDD;

char ch[5000005];
string ansst;
int tt,xc,yc,ans;

bool solve(int c)
{
    int x,y,ex,ey;
    x=xc,y=yc;
    for (int i=c;i>=1;i--)
    {
        ex=x;
        if (ex<0) ex=-ex;
        ey=y;
        if (ey<0) ey=-ey;
        if (ex>ey)
        {
            if (x>0) ch[i]='E',x-=i; else ch[i]='W',x+=i;
        }
        else
        {
            if (y>0) ch[i]='N',y-=i; else ch[i]='S',y+=i;
        }
        //if (c==6) cout<<x<<" "<<y<<endl;
    }
    if ((x==0)&&(y==0))
    {
        if (c<ans)
        {
            ans=c;
            ansst="";
            for (int i=1;i<=c;i++) ansst+=ch[i];
        }
        return true;
    }
    else
        return false;
}

void doit(int md)
{
    int left=1,right=1000000,mid;
    while (left<=right)
    {
        mid=(left+right)/2;
        if (solve(mid*4+md)) right=mid-1; else left=mid+1;
    }
}

int main()
{
    freopen("B.in","r",stdin);
    freopen("B.out","w",stdout);
    scanf("%d",&tt);
    for (int gb=1;gb<=tt;gb++)
    {
        scanf("%d %d",&xc,&yc);
        ans=maxlongint;ansst="";
        doit(0);
        doit(1);
        doit(2);
        doit(3);
        printf("Case #%d: ",gb);
        cout<<ansst<<endl;
    }

    return 0;
}
