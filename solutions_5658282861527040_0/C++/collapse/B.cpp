#include<cstdio>
#include<cstring>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;
int main()
{
	int a,b,k,t,ca=0,i,j,c=0;
	scanf("%d",&t);
	while(t--)
	{
		ca++;
		c=0;
		scanf("%d%d%d",&a,&b,&k);
		for (i=0;i<a;i++)
			for (j=0;j<b;j++)
				if ((i&j)<k)
					c++;
		printf("Case #%d: %d\n",ca,c);
	}
	return 0;
}
