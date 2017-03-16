#include<cstdio>
#include<cstring>
#include<vector>
#include<deque>
#include<utility>
#include<algorithm>
#define LL long long int
#define Lf long double
#define s(n) scanf("%d",&n)
#define sl(n) scanf("%lld",&n)
#define F(i,a,b) for(i=a;i<=b;i++)
using namespace std;
long double j[300],x;
int n;
bool check(Lf y,int in)
{
	int i;
	Lf tmp,rem=100.0-y;
	vector<Lf> d;
	F(i,1,n)
	{
		if (i==in)
			continue;
		d.push_back(j[i]);
	}
	sort(d.begin(),d.end());
	F(i,0,d.size()-1)
	{
		tmp  = ((j[in]-d[i])*100 + x*y)/x;
		if (tmp < 0)
			continue;
		else if (tmp > rem)
			return true;
		else
			rem -= tmp;
	}
	return false;
}
long double search(Lf l,Lf h,int in)
{
	Lf m = (l+h)/2.0,p;
	if (h < l)
		return -1;
	if (h-l <= 0.000001)
		return l;
	if (check(m,in))
	{
		p = search(l,m-0.000001,in);
		if (p < 0)
			return m;
		else
			return p;
	}
	else
		return search(m+0.000001,h,in);
}
int main()
{
	int t,ca=0,i,k;
	Lf y[300],tmp;
	s(t);
	while(t--)
	{
		ca++;
		s(n);
		x = 0;
		F(i,1,n)
		{
			scanf("%Lf",&j[i]);
			x = x + j[i];
		}
		F(i,1,n)
			y[i] = search(0,100,i);
		printf("Case #%d:\n",ca);
		F(i,1,n-1)
			printf("%.6Lf ",y[i]);
		printf("%.6Lf\n",y[n]);
	}
	return 0;
}
