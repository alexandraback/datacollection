#include<stdio.h>
#include<algorithm>

using namespace std;

int osmos(int m[], int index, int n, long long a)
{
	if(a<=1)
		return n-index;
	int i=index;
	while(i<n && a>m[i])
		a+=m[i++];
	if(i>=n)
		return 0;
	int add=0;
	while(a<=m[i])
	{
		a+=(a-1);
		++add;
	}
	add+=osmos(m,i,n,a);
	return add<(n-i)?add:(n-i);
}

int main()
{
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	int T,n;
	long long A;
	int motes[1000];
	scanf("%d",&T);
	for(int c=1;c<=T;c++)
	{
		scanf("%lld %d",&A, &n);
		for(int i=0;i<n;i++)
			scanf("%d",&motes[i]);
		sort(motes,motes+n);
		printf("Case #%d: %d\n",c,osmos(motes,0,n,A));
	}
	return 0;
}