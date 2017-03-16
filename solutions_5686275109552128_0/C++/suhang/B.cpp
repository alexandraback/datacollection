#include <set>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

multiset<int> heap;

int 	n,x,tmp,res,sum,tid;
int		a[1010];

int main()
{
	freopen("B-small-attempt1.in","r",stdin);
	freopen("B.out","w",stdout);
	int test;
	tid=0;

	for (scanf("%d",&test);test--;)
	{
		scanf("%d",&n);
		heap.clear();
		for (int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		res=1000;
		printf("Case #%d: ",++tid);
		for (int i=1;i<=1000;i++)
		{
			sum=0;
			for (int j=1;j<=n;j++)
				sum+=(a[j]+(i-1))/i-1;
			sum+=i;
			res=min(res,sum);
		}

		printf("%d\n",res);
	}	
}