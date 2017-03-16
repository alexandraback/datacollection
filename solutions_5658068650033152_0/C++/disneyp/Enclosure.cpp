#include <iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,k;
int a[100];
int ans=1000000;
void calc()
{
	for(int i=0;i<m-1;i++) if(a[i]-a[i+1]>2 || a[i]-a[i+1]<-2) return;
	//for(int i=0;i<m;i++) cout << a[i] << " ";
	//cout << endl;
	int st,e;
	int total=0;
	int sum=0;
	for(int i=0;i<m;i++) sum+=a[i];
	if(sum<k) return;
	for(int i=0;i<m;i++) if(a[i]!=0)
	{
		st=i+1;
		total+=a[i];
		break;
	}
	for(int i=m-1;i>=0;i--) if(a[i]!=0)
	{
		e=i-1;
		if(st-1!=e+1) total+=a[i];
		break;
	}
	for(int i=st;i<=e;i++) total+=2;
	ans=min(ans,total);
	return;
}
void go(int ind)
{
	if(ind==m)
	{
		calc();return;
	}
	for(int i=0;i<=n;i++)
	{
		a[ind]=i;
		go(ind+1);
	}
}
int main()
{
	freopen("C.in","r",stdin);
	freopen("C.out","w",stdout);
	int t;
	cin >> t;
	for(int i=0;i<t;i++)
	{
		ans=1000000;
		cin >> n >> m >> k;
		if(k<=4) ans=k;
		else
		{
			if(n<m) swap(n,m);
			go(0);
		}
		printf("Case #%d: %d\n",i+1,ans);
	}
}