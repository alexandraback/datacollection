#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
using namespace std;

#define PB push_back
#define MP make_pair

#define REP(i,n) for(i=0;i<(n);++i)
#define FOR(i,l,h) for(i=(l);i<=(h);++i)
#define FORD(i,h,l) for(i=(h);i>=(l);--i)

#define maxm 1002000
#define maxceng 1000
//const double expp=1e-7;
//#define maxnumber 10000000

typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<double> VD;
typedef long long LL;
typedef pair<int,int> PII;

int p[maxm][5],sum[maxceng];
long double c[3010][3010];

int main()
{
	freopen("B-small-attempt2.in","r",stdin);
    freopen("output.txt","w",stdout);
	
	sum[0]=1;
	int ceng=0,s=1;
	for (int i=1;sum[i-1]<=1000000;i++)
	{
		s+=4;
		sum[i]=sum[i-1]+s;
		ceng++;
	}
	
	//for (int i=0;i<=ceng;i++)
	//	cout<<sum[i]<<" ";
	//cout<<sum[ceng]<<" "<<ceng<<endl;
	
	int m=0;
	for (int i=0;m<=1000000;i++)
	{
		int p1=-2*i;
		int p2=0;
		int m1=0;
		for (int j=1;j<=i+i+1;j++)
		{
			m++;
			m1++;
			p[m][1]=p1;
			p[m][2]=p2;
			p[m][3]=m1;
			p1++;
			p2++;
		}
		p2-=2;
		for (int j=1;j<=i+i;j++)
		{
			m++;
			m1++;
			p[m][1]=p1;
			p[m][2]=p2;
			p[m][3]=sum[i]-m+1;
			p1++;
			p2--;
		}
	}
	
	//for (int i=1;i<=m;i++)
	//	cout<<p[i][1]<<" "<<p[i][2]<<" "<<p[i][3]<<endl;
	
	for (int i=0;i<=3000;i++)
		c[0][i]=1;
	for (int i=1;i<=3000;i++)
		for (int j=1;j<=i;j++)
			c[j][i]=c[j][i-1]+c[j-1][i-1];
	
	int T;
	scanf("%d",&T);
	for (int TT=1;TT<=T;TT++)
	{
		printf("Case #%d: ",TT);
		int x,y,n;
		cin>>n>>x>>y;
		int cc=0;
		while (sum[cc]<=n)
		{
			cc++;
		}
		n-=sum[cc-1];
		bool flag=false;
		for (int i=1;i<=sum[cc-1];i++)
			if (p[i][1]==x && p[i][2]==y)
				flag=true;
		if (flag) 
		{
			cout<<"1.0\n";
			continue;
		}
		int d;
		flag=false;
		for (int i=sum[cc-1]+1;i<=sum[cc];i++)
			if (p[i][1]==x && p[i][2]==y)
			{
				d=p[i][3];
				flag=true;
			}
		if ((flag==false) || n<d || x==0)
		{
			cout<<"0.0\n";
			continue;
		}
		int g=sum[cc]-sum[cc-1];
		//cout<<g<<" "<<d<<" "<<n<<" ";
		long double ans1=0,ans2=0;
		for (int i=d;i<=min(g/2,n);i++)
			ans1+=c[i][n];
		for (int i=max(0,n-g/2);i<=min(g/2,n);i++)
			ans2+=c[i][n];
		cout<<ans1/ans2<<endl;
	}
	
    //fclose(stdin);
    //fclose(stdout);
    return 0;
}
