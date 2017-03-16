
//~        Author : Sarvesh Mahajan                             
//               IIIT,Hyderabad                                   
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#ifndef ONLINE_JUDGE
//#define DEBUG
#endif

#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define clr(x) x.clear()
#define For(i,a,b) for(i=a;i<b;i++)
#define loop(i,b) for(i=0LL;i<b;i++)
#define Loop(i,b) for(i=1LL;i<=b;i++)
#define pi(n) cout<<n<<' '
#define si(n) cin>>n
typedef pair<int,int> PII;
typedef vector<PII> VPII;
typedef vector<int> VI;
typedef long long LL;
#define F first
#define S second
#define sz(x) (int) x.size()
#define pLL(x) cout<<x<<' '
#define fill(x,c) memset(x,c,sizeof(x))
#define LET(x,a) __typeof(a) x(a)
#define IFOR(i,a,b) for(LET(i,a);i!=(b);++i)
#define EACH(it,v) IFOR(it,v.begin(),v.end())
#ifdef DEBUG
#define DB(x)              cout<<__LINE__<<" :: "<<#x<< ": "<<x<<endl;
#define DB2(x, y)          cout<<__LINE__<<" :: "<<#x<< ": "<<x<<" | "<<#y<< ": "<<y<<endl;
#define DB3(x, y, z)       cout<<__LINE__<<" :: "<<#x<< ": "<<x<<" | "<<#y<< ": "<<y<<" | "<<#z<<": "<<z<<endl;
#else
#define DB(x)
#define DB2(x,y)
#define DB3(x,y,z)
#endif




int main()
{
#define int long long 
int n,t,m,l,k,ans,i,j,res=0LL,fl;
t=1LL;
cin>>(t);
int T=t;
Loop(t,T)
{
	int d,h,d1LL,h1LL,m1LL;
	cin>>n;
	if(n == 1LL)
	{
		cin>>d>>h>>m;
		printf("Case #%lld: %lld\n",t,0LL);
	}

	else
	{
		cin>>d>>h>>m;
		cin>>d1LL>>h1LL>>m1LL;
		if(m == m1LL)
		printf("Case #%lld: %lld\n",t,0LL);
		else
		{
			int large=max(m,m1LL);
			int small=min(m,m1LL);
			if(d<d1LL and m<m1LL)
		        printf("Case #%lld: %lld\n",t,0LL);
			else if(d1LL<d and m1LL<m)
		        printf("Case #%lld: %lld\n",t,0LL);
			// greater degree one is faster
			else
			{
				if(d<d1LL)
				{
					int reqd=720LL-(d1LL-d);
					DB(reqd)
					if(360LL*large>reqd*small)
		                        printf("Case #%lld: %lld\n",t,1LL);
					else
						printf("Case #%lld: %lld\n",t,0LL);
				}
				else
				{
					int reqd=720LL-(d-d1LL);
					DB(reqd)
					if(360LL*large>reqd*small)
		                        printf("Case #%lld: %lld\n",t,1LL);
					else
						printf("Case #%lld: %lld\n",t,0LL);

				}


			
			}


		}
	}
			



}
return 0;
}
