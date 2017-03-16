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
int n,m;
char ss[100005],mp[50]=" yhesocvxduiglbkrztnwjpfmaq";
LL gcd(LL x,LL y){LL t;for(;y!=0;){t=x%y;x=y;y=t;}return x;}
int main()
{
  int i,j,k,t1,t2,t3,t4,t5,t,T;
  double u1,u2,u3,u4,u5;
  char c1,c2,c3;
  srand((unsigned)time(0));//srand(72888306);
  #ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
  #endif
  cin >>T;
  scanf("%c",&c1);int T2=T;
  for(;T--;)
  {
			fgets(ss,500,stdin);
			t1=strlen(ss);
			for(i=0;i<t1;i++)
			{
			 if (ss[i]>96)ss[i]=mp[ss[i]-96];
			}
			printf("Case #%d: ",T2-T);
			cout <<ss;
		}
  return 0;
}
