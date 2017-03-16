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
int n,S,p,a[105];
LL gcd(LL x,LL y){LL t;for(;y!=0;){t=x%y;x=y;y=t;}return x;}
int main()
{
  int i,j,k,t1,t2,t3,t4,t5,t,T,T2;
  double u1,u2,u3,u4,u5;
  char c1,c2,c3;
  srand((unsigned)time(0));//srand(72888306);
  #ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
  #endif
  cin >>(T2);T=T2;
  for(;T--;)
  {
			cin >>n >>S>>p;
			for(i=1;i<=n;i++)
			 scanf("%d",&a[i]);
			sort(a+1,a+n+1);
			int cnt =0;
			if (T==1)
			 ts=0;
			for(i=n;i>=1;i--)
			{
				if (p*3-2<=a[i])cnt ++;
				else if (a[i]>=p &&p+(p-2)*2<=a[i] &&S)cnt ++,S--;
				
			}
			
			printf("Case #%d: %d\n",T2-T,cnt);

		}
  
  return 0;
}
