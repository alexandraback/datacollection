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
LL gcd(LL x,LL y){LL t;for(;y!=0;){t=x%y;x=y;y=t;}return x;}
struct LEV
{
	 int a,b;
	 bool friend operator <(LEV a,LEV b)
	 {
			return a.b<b.b;
		}
}lv[1005];
int yi[1005],yib[1005];
int main()
{
  int i,j,k,t1,t2,t3,t4,t5,t,T,T2,tag;
  double u1,u2,u3,u4,u5;
  char c1,c2,c3;
  srand((unsigned)time(0));//srand(72888306);
  #ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
  #endif
  cin >>T;T2=T;
  for(;T--;)
  {
			printf("Case #%d: ",T2-T);
			if (T2-T ==16)
			 ts=0;
			scanf("%d",&n);
			for(i=1;i<=n;i++)
			 scanf("%d%d",&lv[i].a,&lv[i].b);
			sort(lv+1,lv+n+1);
			t1=0;
			memset(yi,0,sizeof(yi));memset(yib,0,sizeof(yib));
			
			for(i=0;i<=n;i++)
			{
				if (i)
				{
						for(j=n;j>=1;j--)
						 if (!yi[j] && !yib[j] &&t1>=lv[j].a)
						 {
								yi[j]=1;t1+=1;break;
							}
						if (j<1)
						{
							i=oo;break;
						}
				}
				  tag=0;
								for(j=1;j<=n;j++)
								 if (!yib[j] && t1>=lv[j].b)
								 {
										tag=1;yib[j]=1; t1+=2-yi[j];
									}
									/*
								if (tag)
								{
									i--;
									continue;
								}
								*/
								
				t2=t1;
				for(j=1;j<=n;j++)
				{
					if (yib[j]) continue;
					if (t2<lv[j].b)break;
					t2+= 2-yi[j];
				}
				if (j>n){printf("%d\n",i+n); break; }
			}
			if (i>n) printf("Too Bad\n",i+n);
		}
  return 0;
}
