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
void ot(int k)
{
	int fk=0;
	for(int z=0;z<n;z++)
	{
		if((1<<z)&k)
		{
			if(fk++)cout<<' ';
			cout<<a[z];
		}
	}
	cout<<endl;
}
int ok()
{
	for(int i=1;i<(1<<n);i++)
		for(int q=1;q<(1<<n);q++)
		{
			if(i&q)continue;
			int s1=0,s2=0;
			for(int z=0;z<n;z++)
			{
				if((1<<z)&i)s1+=a[z];
				if((1<<z)&q)s2+=a[z];
			}
			if(s1==s2)
			{
				ot(i);ot(q);
				return 1;
			}
		}
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
			cin>>a[i];
		printf("Case #%d:\n",cas++);
		if(!ok())puts("Impossible");
	}
	return 0;
}

