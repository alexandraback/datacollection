#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
using namespace std;
int a[200];
void getAns(const int Case)
{
	int C,D,V,ans=0,L=0;
	long long sum=0;
	scanf("%d%d%d",&C,&D,&V);
	for(int i=0;i<D;++i)
		scanf("%d",&a[i]);
	sort(a,a+D);
	a[D]=V+1;
	for(int i=0;i<=D;++i)
	{
		while(sum<a[i]-1)
		{
			++ans;
			sum+=(sum+1)*C;
		}
		sum+=a[i]*C;
	}
	printf("Case #%d: %d\n",Case,ans);
}
int main()
{
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	int T;
	scanf("%d",&T);
	for(int i=0;i<T;++i)
		getAns(i+1);
	return 0;
}