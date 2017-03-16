# include <cstring>
# include <cstdlib>
# include <cstdio>
# include <iostream>
# include <map>
using namespace std;
# define N 2000500
int trans[N];
map <int ,int >tt;
void solve (void)
{
	int max,num[10],now,x,tot;
	num[0]=1;
	for (int i=1;i<=6;i++)
		num[i]=num[i-1]*10;
	for (int i=1;i<=2000000;i++)
	{
		now=x=max=i;
		tot=0;
		while (x)
		{
			tot++;
			x/=10;
		}
		for (int j=1;j<tot;j++)
		{
			now=now/10+(now%10)*num[tot-1];
			if (now>max)
				max=now;
		}
		trans[i]=max;
	}
}
int main (void)
{
	solve ();
	int t,a,b,ys=0;
	freopen("C-small-attempt0.in","r",stdin);
	freopen("C-small-attempt0.out","w",stdout);
	cin>>t;
	while (t--)
	{
		cin>>a>>b;
		tt.clear();
		for (int i=a;i<=b;i++)
			tt[trans[i]]++;
		map<int,int> ::iterator iter;
		long long ans=0;
		for (iter=tt.begin();iter!=tt.end();iter++)
			ans+=iter->second*(iter->second-1)/2;
		printf("Case #%d: ",++ys);
		cout<<ans<<endl;
	}
	return 0;
}
