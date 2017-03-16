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
#include <ctime>

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

int TT,o;
LL xc,yc,zc,ee;

LL gcd(LL a,LL b)
{
    if (b==0) return a; else return gcd(b,a%b);
}

int main()
{
    freopen("A.in","r",stdin);
    freopen("A.out","w",stdout);
    scanf("%d",&TT);
    for (int gb=1;gb<=TT;gb++)
    {
        scanf("%I64d/%I64d",&xc,&yc);
        zc=gcd(xc,yc);
        xc/=zc,yc/=zc;
        ee=yc;
        while (ee%2==0) ee/=2;
        printf("Case #%d: ",gb);
        if (ee!=1) printf("impossible\n"); else
        {
            o=0;
            while (yc>xc)
            {
                ++o,yc/=2;
            }
            printf("%d\n",o);
        }
    }
    return 0;
}
