#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <queue>
#include <cstdio>
#include <set>
#include <map>
#include <cstdlib>
#include <cstring>
#include <stack>
#include <cassert>
#include <limits.h>

typedef unsigned long long ULL;
typedef long long LL;

#define MIN(a,b) (a<b?a:b)
#define MAX(a,b) (a>b?a:b)
#define ABS(a) ((a>0)?a:-a)

#define SZ(a) ((int)a.size())
#define PB(a) push_back(a)
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define REP(i,n) FOR(i,0,(int)(n-1))
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
#define printv(v) REP(i,SZ(v))printf("%d ",v[i]);
#define mp(a,b) make_pair(a,b)
#define PII pair<int,int>
#define MOD 1000000007
using namespace std;
int main()
{
    int t,n,m,i,j,k;
    int ctr=0;
    freopen("B-small-attempt0.in","r",stdin);
    freopen("out.txt","w",stdout);
    scanf("%d",&t);
    while(t--)
    {
        ctr++;
        scanf("%d %d",&n,&m);

        printf("Case #%d: ",ctr);

        while(n!=0)
        {
            if(n>0)
            {
                printf("WE");
                n--;
            }
            else
            {
                printf("EW");
                n++;
            }
        }

        while(m!=0)
        {
            if(m>0)
            {
                printf("SN");
                m--;
            }
            else
            {
                printf("NS");
                m++;
            }
        }

        printf("\n");
    }
    return 0;
}
