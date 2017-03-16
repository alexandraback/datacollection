#include<cstdio>
#include<cstring>
#include<cmath>
#include<cctype>
#include<cstdlib>
#include<cctype>
#include<ctime>

#include<algorithm>
#include<iostream>
#include<vector>
#include<stack>
#include<list>
#include<queue>
#include<deque>
#include<set>
#include<bitset>
#include<map>

#define VI vector<int>
#define VD vector<double>
#define PII pair<int,int>
#define PDD pair<double,double>
#define VII vector<PII >
#define VDD vector<PDD >
#define STI stack<int>
#define STD stack<double>
#define STII stack<PII >
#define STDD stack<PDD >

#define pb push_back
#define pf push_front
#define clr clear
#define res resize
#define ass assign
#define fir first
#define sec second

#define For(i,a,b) for(int i=a;i<=b;i++)
#define Dor(i,a,b) for(int i=a;i>=b;i--)
#define Fill(a,b) memset(a,b,sizeof(a))
#define Max(a,b) ((a)>(b)?(a):(b))
#define Min(a,b) ((a)<(b)?(a):(b))

const int N=1010;
const int M=100010;
const int inf=1061109567;
const double eps=1e-10;
const double dinf=1e10;
const double Pi=3.14159265358;

typedef long long LL;

using namespace std;

int n,x,y;
double f[N][N];

double calc1(int x,int y,int t)
{
	Fill(f,0);
	f[0][0]=1;
	For(i,0,t-1) For(j,0,i)
	{
		f[j+1][i-j]+=f[j][i-j]*0.50000000;
		f[j][i-j+1]+=f[j][i-j]*0.50000000;
	}
	double ans=0.000000;
	For(i,y+1,t) ans+=f[i][t-i];
	//cout<<"y="<<y<<"  ans="<<ans<<endl;
	return ans;
}

double calc2(int x,int y,int t,int h)
{
	Fill(f,0);
	f[0][0]=1;
	For(i,0,t)
	{
		int tmp=min(i,h-2);
		int st=0;
		if (i>h-2) st=i-h+2;
		For(j,st,tmp)
		{
			f[j+1][i-j]+=f[j][i-j]*0.50000000;
			f[j][i-j+1]+=f[j][i-j]*0.50000000;
		}
		if (i>h-2)
		{
			f[h-1][i-h+2]+=f[h-1][i-h+1];
			f[i-h+2][h-1]+=f[i-h+1][h-1];
		}
	}
	double ans=0.000000;
	For(i,y+1,h-1) ans+=f[i][t-i];
	return ans;
}

int main()
{
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	int T,cas=1;
	cin>>T;
	while (cas<=T)
	{
		printf("Case #%d: ",cas);
		cas++;
		cin>>n;
		cin>>x>>y;
		x=abs(x);
		y=abs(y);
		//cout<<"x"<<x<<"  y"<<y<<endl;
		int p=0,s=0;
		while (s<=n)
		{
			s+=p*4+1;
			p++;
		}
		if (x+y>2*p-2) printf("0.0\n");
		if (x+y<2*p-2) printf("1.0\n");
		if (x+y!=2*p-2) continue;
		else
		{
			//printf("wbpneuhg\n");
			int tmp=n-(s-(p*4-3));
			//cout<<"tmp="<<tmp<<endl;
			if (tmp<2*p-1)
				if (tmp<=y)
					printf("0.0\n");
				else
					printf("%.8lf\n",calc1(x,y,tmp));
			else
				if (tmp-2*p+2>y)
					printf("1.0\n");
				else
					printf("%.8lf\n",calc2(x,y,tmp,2*p-1));
		}

	}
	return 0;
}
