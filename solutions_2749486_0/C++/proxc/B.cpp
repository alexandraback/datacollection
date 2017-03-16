#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

#define MOD 1000000007LL
#define LL long long
#define ULL unsigned long long
#define LD long double
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(x) ((x)<0?-(x):(x))
#define si(n) scanf("%d",&n)
#define sf(n) scanf("%f",&n)
#define sl(n) scanf("%lld",&n)
#define slu(n) scanf("%llu",&n)
#define sd(n) scanf("%lf",&n)
#define ss(n) scanf("%s",n)
#define pnl printf("\n")
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define FORR(i,n) for(int i=(n);i>=0;i--)
#define DB(x) cout<<"\n"<<#x<<" = "<<(x)<<"\n";
#define CL(a,b) memset(a,b,sizeof(a))
#define GOLD ((1+sqrt(5))/2)
const double PI=3.14159265358979323846264338327950288419716939937510582097494459230;
void swaps (char *x,char *y)
{
    char temp;
    temp=*x;
    *x=*y;
    *y=temp;
}
void swapi(int *a,int *b)
{
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
ULL gcd(ULL a,ULL b)
{
    if(a==0)return b;
    if(b==0)return a;
    if(a==1||b==1)return 1;
    if(a==b)return a;
    if(a>b)return gcd(b,a%b);
    else return gcd(a,b%a);
}

int compare(const void*a,const void*b)
{
    return (*(long long*)a-*(long long*)b);
}
int main()
{
    //freopen("B-trial.txt","r",stdin);
    freopen("B-small-attempt0.in","r",stdin);
    freopen("B-small-attempt0.out","w",stdout);

    int testcase;
    scanf("%d",&testcase);

    for (int caseId=1; caseId<=testcase; caseId++)
    {
        printf("Case #%d: ",caseId);
        int x,y,count=1,xprev=0,yprev=0;
        scanf("%d%d",&x,&y);

        while(x!=xprev)
        {
            if(x-xprev >0)
            {
                xprev+=count;
                count++;
                printf("E");
            }
            else
            {
                xprev+=count;
                printf("E");
                count++;
                xprev-=count;
                printf("W");
                count++;
            }
        }
        while(y!=yprev)
        {
            if(y-yprev >0)
            {
                yprev-=count;
                printf("S");
                count++;
                yprev+=count;
                printf("N");
                count++;
            }
            else
            {
                yprev+=count;
                printf("N");
                count++;
                yprev-=count;
                printf("S");
                count++;
            }
        }
        printf("\n");
    }
    return 0;
}

