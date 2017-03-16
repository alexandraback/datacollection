
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
using namespace std;

#define PB push_back
#define MP make_pair

#define REP(i,n) for(i=0;i<(n);++i)
#define FOR(i,l,h) for(i=(l);i<=(h);++i)
#define FORD(i,h,l) for(i=(h);i>=(l);--i)

#define ZERO (1e-9)
#define INF (2100000000)
#define LLINF (9200000000000000000)

typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<double> VD;
typedef long long LL;
typedef pair<int,int> PII;

int n,v[222],p[222];
double leas,sum,sum2;

int cmp(const void *a,const void *b)
{
    return (*(int *)a)-(*(int *)b);
}

int main()
{
    int tc,ti,i,tn,sum3;
    freopen("A-large.in","r",stdin);
    freopen("A-large.out","w",stdout);
    scanf("%d",&tc);
    for(ti=1; ti<=tc; ti++)
    {
        sum=0;
        sum2=0;
        scanf("%d",&n);
        for(i=0; i<n; i++)
        {
            scanf("%d",p+i);
            sum2+=p[i];
        }
        sum3=sum2;
        sum2*=2;
        tn=n;
        while(fabs(sum2-sum)>1e-9)
        {
            memset(v,0,sizeof(v));
            sum=sum2;
            leas=sum2/tn;
            sum2=0;
            tn=0;
            for(i=0; i<n; i++)
            {
                if(leas-p[i]>1e-9)
                {
                    sum2+=2*p[i];
                    tn++;
                    v[i]=1;
                }
                else
                {
                    sum2+=p[i];
                }
            }
        }
        printf("Case #%d:",ti);
        for(i=0; i<n; i++)
        {
            if(v[i])printf(" %lf",(leas-p[i])/sum3*100);
            else printf(" %lf",0.0);
        }
        printf("\n");
    }
    return 0;
}
