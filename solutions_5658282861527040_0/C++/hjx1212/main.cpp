#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int main()
{
	freopen("E:/in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int T,t,a,b,k,i,j,s;
	for(scanf("%d",&T),t=1;t<=T;t++)
	{
		scanf("%d%d%d",&a,&b,&k);
		s=0;
		for(i=0;i<a;i++)
		for(j=0;j<b;j++)
			if((i&j)<k)
				s++;
		printf("Case #%d: %d\n",t,s);
	}
	return 0;
}
