#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;
#define maxn 1010
int n,m;
long long ans;
struct node
{
	long long x;
	int id;
}a[maxn],b[maxn],aa[maxn];
void f()
{
	int i,j;
	for(i=0;i<=m;i++)
	{
		for(j=1;j<=n;j++)
			aa[j]=a[j];
		long long tmp=0;
		for(j=1;j<=i;j++)
		{
			if(aa[1].id==b[j].id)
			{
				if(aa[1].x>=b[j].x)
				{
					aa[1].x-=b[j].x;
					tmp+=b[j].x;
				}
				else
				{
					tmp+=aa[1].x;
					aa[1].x=0;
				}
			}
		}
		for(j=i+1;j<=m;j++)
		{
			if(aa[2].id==b[j].id)
			{
				if(aa[2].x>=b[j].x)
				{
					aa[2].x-=b[j].x;
					tmp+=b[j].x;
				}
				else
				{
					tmp+=aa[2].x;
					aa[2].x=0;	
				}
			}
		}
		ans=max(ans,tmp);
	}
}
int main()
{
	int i,j,ncase,x,y,tt=0;
	freopen("C-small-attempt3.in", "r", stdin);
	freopen("C-small-attempt3.out", "w", stdout);
	scanf("%d",&ncase);
	while(ncase--)
	{
		scanf("%d %d",&n,&m);
	//	cout<<n<<" "<<m<<endl;
		for(i=1;i<=n;i++)
		{
			cin>>a[i].x>>a[i].id;
	//		cout<<a[i].x<<" "<<a[i].id<<endl;
		}
	//	cout<<"---------------------------"<<endl;
		for(i=1;i<=m;i++)
		{
			cin>>b[i].x>>b[i].id;
	//		cout<<b[i].x<<" "<<b[i].id<<endl;
		}
		ans=0;
		if(n==1)
		{
			aa[1]=a[1];
			for(i=1;i<=m;i++)
				if(b[i].id==aa[1].id)
					ans+=min(aa[1].x,b[i].x),aa[1].x-=min(aa[1].x,b[i].x);
		}
		else if(n==2)
		{
			if(a[1].id==a[2].id)
			{
				aa[1]=a[1]; aa[1].x+=a[1].x;
				for(i=1;i<=m;i++)
					if(b[i].id==a[1].id)
						ans+=min(aa[1].x,b[i].x),aa[1].x-=min(aa[1].x,b[i].x);
			}
			else
			{
				for(i=0;i<=m;i++)
				{
					for(j=1;j<=n;j++)
						aa[j]=a[j];
					long long tmp=0;
					for(j=1;j<=i;j++)
					{
						if(aa[1].id==b[j].id)
						{
							if(aa[1].x>=b[j].x)
							{
								aa[1].x-=b[j].x;
								tmp+=b[j].x;
							}	
							else
							{
								tmp+=aa[1].x;
								aa[1].x=0;
							}
						}
					}
					for(j=i+1;j<=m;j++)
					{
						if(aa[2].id==b[j].id)
						{
							if(aa[2].x>=b[j].x)
							{
								aa[2].x-=b[j].x;
								tmp+=b[j].x;
							}
							else
							{
								tmp+=aa[2].x;
								aa[2].x=0;
							}
						}
					}
					ans=max(ans,tmp);
				}
			}
		}
		else
		{
			if(a[1].id==a[2].id==a[3].id)
			{
				a[1].x+=a[2].x,a[1].x+=a[3].x;
				aa[1]=a[1];
				for(i=1;i<=m;i++)
					if(b[i].id==a[1].id)
						ans+=min(aa[1].x,b[i].x),aa[1].x-=min(aa[1].x,b[i].x);
			}
			else if(a[1].id==a[2].id)
			{
				a[1].x+=a[2].x;a[2]=a[3];n=2;
				f();
			}else if(a[2].id==a[3].id)
			{
				a[2].x+=a[3].x; n=2;
				f();
			}else if(a[1].x==a[3].x)
			{
				for(i=0;i<=m;i++)
				{
					for(j=i;j<=m;j++)
					{
						long long tmp=0;
						for(int ii=1;ii<=n;ii++)
							aa[ii]=a[ii];
						for(int ii=0;ii<=i;ii++)
						{
							if(b[ii].id==aa[1].id)
							{
								tmp+=min(aa[1].x,b[ii].x);
								aa[1].x-=min(aa[1].x,b[ii].x);
							}
						}
						for(int ii=i+1;ii<=j;ii++)
						{
							if(b[ii].id==aa[2].id)
							{
								tmp+=min(aa[2].x,b[ii].x);
								aa[2].x-=min(aa[2].x,b[ii].x);
							}
						}
						for(int ii=j+1;ii<=m;ii++)
						{
							if(b[ii].id==aa[3].id)
							{
								tmp+=min(aa[3].x,b[ii].x);
								aa[3].x-=min(aa[3].x,b[ii].x);
							}
						}
						ans=max(ans,tmp);
					}
				}
				for(i=1;i<=3;i++) aa[i]=a[i];
				aa[1].x+=aa[3].x;
				long long tmp=0;
				for(i=1;i<=m;i++)
					if(b[i].id==a[1].id)
						tmp+=min(aa[1].x,b[i].x),aa[1].x-=min(aa[1].x,b[i].x);
				ans=max(ans,tmp);
			}
			else
			{
				for(i=0;i<=m;i++)
				{
					for(j=i;j<=m;j++)
					{
						long long tmp=0;
						for(int ii=1;ii<=n;ii++)
							aa[ii]=a[ii];
						for(int ii=0;ii<=i;ii++)
						{
							if(b[ii].id==aa[1].id)
							{
								tmp+=min(aa[1].x,b[ii].x);
								aa[1].x-=min(aa[1].x,b[ii].x);
							}
						}
						for(int ii=i+1;ii<=j;ii++)
						{
							if(b[ii].id==aa[2].id)
							{
								tmp+=min(aa[2].x,b[ii].x);
								aa[2].x-=min(aa[2].x,b[ii].x);
							}
						}
						for(int ii=j+1;ii<=m;ii++)
						{
							if(b[ii].id==aa[3].id)
							{
								tmp+=min(aa[3].x,b[ii].x);
								aa[3].x-=min(aa[3].x,b[ii].x);
							}
						}
						ans=max(ans,tmp);
					}
				}
			}
		}
		cout<<"Case #"<<++tt<<": "<<ans<<endl;
	}
	return 0;
}
