#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <cmath>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

#define N 1004
#define M 1003
#define ll long long
#define inf 1<<29
#define mod 1000000007
#define lson (id<<1)
#define rson (id<<1|1)

#define eps 1e-11
#define pii pair<int,int>
#define pdd pair<double,double>
#define It map<unsigned,string>::iterator
#define MP(i,j) make_pair(i,j)

int n,a[13211];
int tot=0;
int ok(double z,int k)
{
	double s=a[k]+z*tot;
	double da=0;
	for(int i=0;i<n;i++)
	{  
		if(i==k)continue;
		if(a[i]>s)continue;
		da+=(s-a[i])/tot;
	}
	if(da+z>1)return 1;
	return 0;
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
#endif

	int t,cas=1;
	cin>>t;
	while(t--)
	{
		tot=0;
		cin>>n;
		for(int i=0;i<n;i++)
			cin>>a[i],tot+=a[i];
		printf("Case #%d:",cas++);
		for(int i=0;i<n;i++)
		{
			double l=0,r=1,mid;
			for(int z=0;z<1001;z++)
			{
				mid=(l+r)/2;
				if(ok(mid,i))r=mid;
				else l=mid;
			}
			printf(" %.7lf",l*100);
		}
		cout<<endl;

	}
	return 0;
}

