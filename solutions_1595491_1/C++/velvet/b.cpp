#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int bestscore(int n)
{
	if (n%3==0) return n/3;
	else return n/3+1;
}
int surprising(int n)
{
	if (n==0) return 0;
	if (n%3==2) return n/3+2;
	else return n/3+1;
}
bool cmp(const int &a,const int &b)
{
	return a>b;
}
int main()
{
	int N,T,S,p,x,ans;
	int a[109];
	cin>>T;
	for (int cas=1;cas<=T;cas++)
	{
		ans=0;

		cin>>N>>S>>p;
		for (int i=0;i<N;i++) cin>>a[i];
		sort(a,a+N,cmp);

		for (int i=0;i<N;i++)
			if (bestscore(a[i])>=p) ans++;
			else if (surprising(a[i])>=p && S) ans++,S--;

		printf("Case #%d: %d\n",cas,ans);
	}
	return 0;
}
