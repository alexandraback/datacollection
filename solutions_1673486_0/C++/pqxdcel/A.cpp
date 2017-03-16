// powered by xpd1
// on 2011-03-
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <ctime>
#include <cstring>
#include <ctype.h>
#include <memory>
#include <fstream>
#include <string>

#include <map>
#include <queue>
#include <stack>
#include <iomanip>
#include <vector>
#include <list>
#include <deque>
#include <set>
//#include <conio.h>
#define oo 2000000000
#define ol 200000000000000000ll
#define ooo 1E14
#define EPS 1E-10
/*#define dis(x1,y1,x2,y2)\
 (double)(sqrt( ((x1)-(x2))*((x1)-(x2)) + ((y1)-(y2))*((y1)-(y2)) ) )
#define disx(x,y) (double)(sqrt((x)*(x)+(y)*(y)))
#define dianji(x1,y1,x2,y2) (double)((x1)*(x2)+(y1)*(y2))
#define chaji(x1,y1,x2,y2) (double)((x1)*(y2)-(y1)*(x2))*/
using namespace std;
const double PI=acos((double)-1);
typedef long long LL;
int ts,ts2;
int n,m,A,B;
double pr [100005],wa[100005];
LL gcd(LL x,LL y){LL t;for(;y!=0;){t=x%y;x=y;y=t;}return x;}
int main()
{
  int i,j,k,t1,t2,t3,t4,t5,t,T,T2;
  double u1,u2,u3,u4,u5,ans;
  char c1,c2,c3;
  srand((unsigned)time(0));//srand(72888306);
  #ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
  #endif
  cin >>T;T2=T;
  for(;T--;)
  {
			scanf("%d%d",&A,&B);
			for(i=1;i<=A;i ++)scanf("%lf",&pr[i]);
			printf("Case #%d: ",T2-T);
			ans =B+2;
			wa[0]=0;
			u1=1;
			for(i=1;i<=A;i++)
		 {
				wa[i]=u1*(1-pr[i]);
				u1*=pr[i];
			}			
			wa[A+1]=u1;
			u1=0;
			for(i=A;i>=1;i--)
			{
			 u1+=wa[i]*(B-A+1+B+1);
			}
			u1+=wa[A+1]*(B-A+1);
			ans=min(ans,u1);
			for(i=1;i<=A;i++)
			{
				u1=u1+(1)*2 -wa[A-i+1]*(B+1);
				ans=min(u1,ans);
			}
			printf("%.6lf\n",ans);
		}
  return 0;
}
