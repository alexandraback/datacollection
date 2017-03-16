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
void swaps (char *x,char *y){char temp;temp=*x;*x=*y;*y=temp;}
void swapi(int *a,int *b){int temp;temp=*a;*a=*b;*b=temp;}
ULL gcd(ULL a,ULL b){if(a==0)return b;if(b==0)return a;if(a==1||b==1)return 1;
if(a==b)return a;if(a>b)return gcd(b,a%b);else return gcd(a,b%a);}

int compare(const void*a,const void*b)
{
    return (*(long long*)a-*(long long*)b);
}

int check(char A[],int n,int i,int j)
{
      int ret_val=0;
      int found=0;
      int temp=i;
      while(i<=j)
      {
          if(A[i]!='a' && A[i]!='e' && A[i]!='i' && A[i]!='o' && A[i]!='u')
            {
                found++;
            }
          else
            {
                found=0;
            }
         if(found==n)
            {
                ret_val=1;
                break;
            }
        i++;
      }
     // for(i=temp;i<=j;i++)
     // {
     //     fprintf(stderr,"%c",A[i]);
    //  }
    //  fprintf(stderr,"\n %d\n",ret_val);
      return ret_val;
}
int main()
{

    freopen("A-small-attempt0.in","r",stdin);
    freopen("A-small-attempt0.out","w",stdout);
   // freopen("A-trial.txt","r",stdin);
  //  freopen("A-small-attempt1.out","w",stdout);

    int testcase;
    scanf("%d",&testcase);
    for (int caseId=1; caseId<=testcase; caseId++)
    {
        printf("Case #%d: ",caseId);
        char A[105];
        int n;
        scanf("%s%d",A,&n);
        int i;
        i=0;
        int len;
        len=strlen(A);
        unsigned long long ans=0;
        for(i=0;i<=len-n;i++)
        {
            int j;
            for(j=i+n-1;j<len;j++)
            {
                ans=ans+check(A,n,i,j);
            }
        }
        printf("%llu\n",ans);
    }
    return 0;
}

