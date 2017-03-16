#include <cstdio>
#include <algorithm>
#include <set>
#define scanf(args...) scanf(args) ? : 0
using namespace std;
const int MAX=1e3+14;
int n;
long double a[MAX];
long double b[MAX];
int de_war()
{
	int w=0;
	set<long double> c;
	for(int i=0;i<n;i++)
		c.insert(b[i]);
	set<long double>::iterator it;
	for(int i=0;i<n;i++)
	{
		if(a[i]>*c.begin())
		{
			c.erase(c.begin());
			w++;
		}
		else
		{
			it=c.end();
			it--;
			c.erase(it);
		}
	}
	c.clear();
	return w;
}
int war()
{
	int w=0;
	set<long double> c;
	for(int i=0;i<n;i++)
		c.insert(b[i]);
	set<long double>::iterator it;
	for(int i=0;i<n;i++)
	{
		it=c.lower_bound(a[i]);
		if(it!=c.end())
			c.erase(it);
		else w++;
	}
	c.clear();
	return w;
}
void debug()
{
	for(int i=0;i<n;i++)
		printf("%.3Lf ",a[i]);
	printf("\n");
	for(int i=0;i<n;i++)
		printf("%.3Lf ",b[i]);
	printf("\n");
}
void solve()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%Lf",&a[i]);
	for(int i=0;i<n;i++)
		scanf("%Lf",&b[i]);
	sort(a,a+n);
	sort(b,b+n);
	//debug();
	int d=de_war();
	int w=war();
	printf("%d %d\n",d,w);
}
int main()
{
	int t;
	scanf("%d",&t);
	for(int i=1;i<=t;i++)
	{
		printf("Case #%d: ",i);
		solve();
	}
}