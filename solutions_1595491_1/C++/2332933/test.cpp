#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define swap(a,b) a=a^b,b=a^b,a=a^b

int main()
{
//	freopen("1.txt", "r", stdin);
//	freopen("2.txt", "w", stdout);

	int i,j;
	int T;
	scanf("%d",&T);
	int n,s,p;
	int a,b,tmp;

	for (i=1;i<=T;i++)
	{
		scanf("%d%d%d",&n,&s,&p);
		a=0,b=0;
		for (j=0;j<n;j++)
		{
			scanf("%d",&tmp);
			if (tmp>=p*3-2)
				a++;
			else if (p>=2 && tmp>=p*3-4)
				b++;
		}
		printf("Case #%d: %d\n",i,a+min(s,b));
	}

	return 0;
}