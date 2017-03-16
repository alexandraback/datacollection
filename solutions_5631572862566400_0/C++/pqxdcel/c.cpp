// powered by xpd1  /i love shimokawa_mikuni and i haven't touch my devc for 3 months. 
// All of these left only broken history after 12.4.22. sacrifice for my  love.
// on 2016-04-09 
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
#include <utility>
#include <iomanip>
#define oo 2000000000
#define ol 200000000000000000ll
#define md 1000000007 
#include <map>
#include <queue>
#include <vector>
#include <list>
#include <set>
//#include <conio.h>
#define oo 2000000000
#define ol 200000000000000000ll //=2E17
#define ooo 1E14
#define EPS 1E-10
#define mp make_pair
#define pb push_back
#define eps EPS
#define mem(x,y) (memset((x),y,sizeof((x))))
#define debug(x) cout << #x<<" = "<<x<<endl;
#ifdef __int64
 #define fmt64 "%I64d"
#else 
 #define fmt64 "%lld"
#endif
#define fi first
#define se second
using namespace std;
using namespace rel_ops;
const double PI=acos((double)-1);
typedef long long LL;
typedef pair<int,int> pii;
typedef pair<LL,LL> pll;
int ts,ts2,ts3,ts4;
int n,m,h[10];
char a[1005];
LL gcd(LL x,LL y){LL t;for(;y!=0;){t=x%y;x=y;y=t;}return x;}
int ans,ha[1005];
int TWO[1005],TWOCNT;
int dist[1005],fir[1005],firT[1005];
int maxTWO[1005];
int ptn(int x,int y){if (x==y)return 1; else if (a[x]==y&&a[y]==x) return 2; else return 0;}
int main()
{
  int i,j,k,l,t1,t2,t3,t4,t5,t6,t7,t8,t9,t,nw;
  int tt1,tt2,tt3,tt4;
  double u1,u2,u3,u4,u5,u6,u7,u8,u9;
  char c1,c2,c3;
  srand((unsigned)time(0));//srand(72888306);
  #ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
  #endif
  int T,T2;
  cin>>T;
  for(T2=1;T2<=T;T2++)
  {
  	printf("Case #%d: ",T2);
  	cin>>n;
  	ans=0;TWOCNT=0;
  	for(i=1;i<=n;i++)
			 scanf("%d",&a[i]);
			mem(ha,0);mem(dist,0);mem(fir,0);mem(firT,0);mem(TWO,0);mem(maxTWO,0);
			for(i=1;i<=n;i++)
			{
				mem(ha,0);
				t2=i;
				for(t1=0;!ha[t2];)
				{
					ha[t2]=1;
					t2=a[t2];
				 t1++;
				}
				if (t2==i)
				 ans=max(ans,t1);
			}
			
				for(i=1;i<=n;i++)
				 if (!TWO[i]&&a[a[i]]==i)
				 {
				  TWO[i]=TWO[a[i]]=1,TWOCNT+=2;
				  firT[i]=i;firT[a[i]]=a[i];
					}
				ans=max(ans,TWOCNT);
				for(i=1;i<=n;i++)
				{
					for(j=1;j<=n;j++)
					{
						if (TWO[j]||dist[j]!=0)continue;
						if (TWO[a[j]])
						{
							dist[j]=1;
							fir[j]=j;
							firT[j]=a[j];
						}
						else if (dist[a[j]]!=0)
						{
							dist[j]=dist[a[j]]+1;
							fir[j]=fir[a[j]];
							firT[j]=firT[a[j]];
						}
						
					}
				}
				for(i=1;i<=n;i++)
				 for(j=i+1;j<=n;j++)
				 {
				 	if (i==j)continue;
				 	if (!ptn(firT[i],firT[j]) || firT[i]==firT[j])continue;
				 	if (TWO[i]&&TWO[j])maxTWO[firT[i]]=maxTWO[a[firT[i]]]=max(maxTWO[firT[i]],2);
						if (TWO[i] || TWO[j])
				 	{
				 		t2=ptn(firT[i],firT[j])+dist[i]+dist[j];
				 		maxTWO[firT[i]]=maxTWO[a[firT[i]]] = max(maxTWO[firT[i]],t2);
				 	}
				 	else
				 	{
				 		t2=ptn(firT[i],firT[j])+dist[i]+dist[j];
				 		if (fir[i]!=fir[j])
				 		{
				 			maxTWO[firT[i]]=maxTWO[a[firT[i]]] = max(maxTWO[firT[i]],t2);
				 		}
				 	}
		  	}
		  t1=0;
				for(i=1;i<=n;i++)
				{
					if (TWO[i] && a[i]>i)
					 t1+=maxTWO[i];
				}
				ans=max(ans,t1);
				cout<<ans<<endl;
		}
  return 0;
}
