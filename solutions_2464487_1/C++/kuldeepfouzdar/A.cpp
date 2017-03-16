#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<fstream>
#include<cstdlib>
#include<cassert>
#include<vector>
#include<algorithm>
#include<stack>
#include<set>
#include<map>
#include<math.h>
#include<ctime>
#define LL long long
#define ULL unsigned long long
#define L long
#define VCTP vector<pair<LL,LL> >
#define PII pair<LL,LL>
#define PDD pair<double,double>
#define F first
#define S second
#define FOR(i,lb,ub) for(i=lb;i<=ub;i++)
#define RFOR(i,ub,lb) for(i=ub;i>=lb;i--)
#define FORS(it,v) for(it=v.begin();it!=v.end();it++)
#define st_clk double st=clock();
#define end_clk double en=clock();
#define show_time cout<<"\tTIME="<<(en-st)/CLOCKS_PER_SEC<<endl;
#define sc(n) scanf("%d",&n)
#define scst(n) scanf("%s",n)
#define f_in(st) freopen(st,"r",stdin);
#define f_out(st) freopen(st,"w",stdout);
LL gcd(LL a, LL b) { return b?gcd(b,a%b):a; }
using namespace std;
 #ifndef ONLINE_JUDGE
inline int getchar_unlocked() { return getchar(); }
#endif
template <class T>
inline void r_f(T &p)
{
         char c;
         while ((c=getchar_unlocked()) < 48 || c > 57);
         p=c-48;
         while ((c=getchar_unlocked()) >= 48 && c <= 57) p=p*10+c-48;
}

int main()
{
     #ifndef ONLINE_JUDGE
     f_in("A-large.in");
     f_out("out.txt");
     #endif
     int t,k=1,i,j;
     cin>>t;
     while (t--)
     {
     	cout<<"Case #"<<k++<<": ";
     	LL r,t,outer,inner,used,n=1;
     	cin>>r>>t;
     	LL a=r*2+1;
     	LL val;
     	while(1)
     	{
     		 val=n*n*2+n*(a-2)-t;
     		 //cout<<"\t"<<val<<endl;
     		if (val>0)
     			break;
     		n*=2;
     	}
     	LL low=n/2,high=n;
     	while(high-low>1000)
     	{
     		LL n=(high+low)/2;
     		val=n*n*2+n*(a-2)-t;
     		if (val==0)
     		{
     			goto end;
     		}
     		if (val<0)
     		{
     			low=n;
     		}
     		if (val>0)
     		{
     			high=n;
     		}
     		
     		//cout<<"\t\t"<<val<<endl;
     	}
     	n=high;
     	val=n*n*2+n*(a-2)-t;
     	while (val>0)
     	{
     		n--;
     		val=n*n*2+n*(a-2)-t;
     	}
     	end:
     	cout<<n<<endl;
     }
return 0;
}

