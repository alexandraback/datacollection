#pragma comment(linker, "/STACK:850000000")
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<set>
#include<map>
#include<cstring>
#include<string>
#include<cmath>
#include<complex>
#include<ctime>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pii;
typedef vector<ll> vi;
typedef vi::iterator vit;
typedef vector<pii> vpi;

#define sq(x) (x)*(x)
#define all(x) (x).begin(),(x).end()
#define cl(x) memset(x,0,sizeof(x))
#define LL "%I64d"
#define RLL(x) scanf(LL,&(x))

double Cs[3500][3500];

double C(int n, int k)
{
	if(k>n)
		return 0.;
	return Cs[n-k][k];
}

void test(int t)
{
	int n,x,y;
	scanf("%d%d%d",&n,&x,&y);
	int k=0;
	int n1=n;
	while(k+k+1<=n1)
	{
		n1-=(k+k+1);
		k+=2;
	}
	k-=2;
	double answ=0.0;
	if(x+y<=k && y-x<=k)
		answ = 1.0;
	else
		if(x+y>k+2 || y-x>k+2 || x==0)
			answ=0.0;
		else
		{
			answ = 0;
			cl(Cs);
			Cs[0][0]=1;
			for(int i=0; i<n1; ++i)
				for(int j=0; j<=k+2; ++j)
				{
					if(i-j<=k+2)
					{
						if(j<k+2 && i-j<k+2)
						{
							Cs[i+1][j]+=0.5*Cs[i][j];
							Cs[i+1][j+1]+=0.5*Cs[i][j];
						}
						else
							if(j==k+2)
								Cs[i+1][j]+=Cs[i][j];
							else
								Cs[i+1][j+1]+=Cs[i][j];
					}
				}
			for(int i=y+1; i<=k+2; ++i)
				answ+=Cs[n1][i];
		}
	printf("Case #%d: %.8lf\n",t,answ);
}

int main()
{
	freopen("b.in","r",stdin);freopen("b.out","w",stdout);
	/*for(int i=0; i<3000; ++i)
		for(int j=0; j<3000; ++j)
			if(i==0)
				if(j==0)
					Cs[i][j]=1;
				else
					Cs[i][j]=Cs[i][j-1]*0.5;
			else
				if(j==0)
					Cs[i][j]=Cs[i-1][j]*0.5;
			else
				Cs[i][j]=(Cs[i-1][j]+Cs[i][j-1])*0.5;*/
	int n;
	cin>>n;
	for(int i=1; i<=n; ++i)
		test(i);
	return 0;
}