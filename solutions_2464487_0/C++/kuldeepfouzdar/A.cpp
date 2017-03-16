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
     f_in("A-small-attempt0.in");
     f_out("out.txt");
     #endif
     int t,k=1,i,j;
     cin>>t;
     while (t--)
     {
     	cout<<"Case #"<<k++<<": ";
     	LL r,t,outer,inner,used,ans=0;
     	cin>>r>>t;
     	outer=r+1;
     	inner=r;
     	while(1)
     	{
     		used=(outer-inner)*(outer+inner);
     		if (used>t)
     			break;
     		ans++;
     		t-=used;
     		inner+=2;
     		outer+=2;
     	}
     	cout<<ans<<endl;
     }
return 0;
}

