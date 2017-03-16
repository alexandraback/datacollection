#include<stdio.h>
#include<vector>
using namespace std;
bool gen(int sum,int w,vector<int> &v,vector<int> &c,int &n,int &m,int &k)
{
	//if(c[m-1]==1)
	//	printf("c=%d sum=%d\n",v[m-1],sum);
	if(sum==w)
		return 1;
	for(int i=0;i<m;i++)
		if(c[i]<n)
		{
			c[i]++;
			bool x = gen(sum+v[i],w,v,c,n,m,k);
			c[i]--;
			if(x==1)	return 1;
		}
	return 0;
}
int main()
{
	freopen("C-small-attempt4.in","r",stdin);
	freopen("C-small-attempt4.txt","w",stdout);
	int t;
	scanf("%d",&t);
	for(int a=1;a<=t;a++)
	{
		int n,m,k;
		scanf("%d%d%d",&n,&m,&k);
		vector<int> v;
		for(int i=0;i<m;i++)
		{	
			int x;
			scanf("%d",&x);
			v.push_back(x);
		}
		vector<int> c(m,0);
		int out=0;
		for(int i=1;i<=k;i++)
		{
			bool x = gen(0,i,v,c,n,m,k);
			if(!x)
			{
				//printf("ch=%d\n",i);
				v.push_back(i);
				c.push_back(0);
				m++;
				out++;
			}
		}
		printf("Case #%d: %d\n",a,out);
	}
}
