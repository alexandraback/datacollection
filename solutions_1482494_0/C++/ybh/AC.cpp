#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

#define PB push_back

#define MAXN 20

typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<double> VD;
typedef long long LL;

struct Data1
{
	int x,y;
}a[MAXN];
struct Data2
{
	int x,y,z;
}b[MAXN];
int c[MAXN];

bool cmp(const Data1 &i , const Data1 &j)
{
	if (i.x<j.x) return true;
	else
	{
		if (i.x==j.x && i.y>j.y) return true;
		else return false;
	}
}

bool cmp2(const Data2 &i , const Data2 &j)
{
	if (i.y<j.y) return true;
	else return false;
}

int main()
{
	freopen("B-small-attempt0.in","r",stdin);
	freopen("output.txt","w",stdout);
	
	int TT;
	cin>>TT;
	for (int T=1;T<=TT;T++)
	{
		bool ansbool=true;
		int n,ans=0;
		cin>>n;
		for (int i=1;i<=n;i++)
		{
			cin>>a[i].x>>a[i].y;
		}
		sort(a+1,a+n+1,cmp);
		for (int i=1;i<=n;i++)
		{
			b[i].x=a[i].x;
			b[i].y=a[i].y;
			b[i].z=i;
			c[i]=0;
		}
		sort(b+1,b+n+1,cmp2);
		int g=0,p=1;
		
			while (p<=n && b[p].y<=g)
			{
				g+=2-c[b[p].z];
				c[b[p].z]=2;
				ans++;
				p++;
			}
			
		while (p<=n)
		{
			int flag=0,mm=-1;
			for (int i=1;i<=n && a[i].x<=g;i++)
			{
				if (c[i]==0 && a[i].y>mm)
				{
					flag=i;
					mm=a[i].y;
				}
			}
			if (flag==0)
			{
				ansbool=false;
				break;
			}
			c[flag]=1;
			g++;
			ans++;
			while (p<=n && b[p].y<=g)
			{
				g+=2-c[b[p].z];
				c[b[p].z]=2;
				ans++;
				p++;
			}
		}
		if (ansbool) cout<<"Case #"<<T<<": "<<ans<<'\n';
		else cout<<"Case #"<<T<<": Too Bad"<<'\n';
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
