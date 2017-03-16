#include <iostream>
#include <cstring>
using namespace std;
int n,s,p,tol[150];
int main()
{
	int t,i,j;
	//freopen("d:\\gcj\\b.in","r",stdin);
	//freopen("d:\\gcj\\b.out","w",stdout);
	scanf("%d",&t);
	for(i=1;i<=t;i++)
	{
		scanf("%d%d%d",&n,&s,&p);
		int cnt=0;
		for(j=0;j<n;j++)
		{
			scanf("%d",&tol[j]);
			if(!p)
			{
				cnt++;
				continue;
			}
			if(!tol[j] && p)
				continue;
			if(tol[j]>=p*3-2)
				cnt++;
			if(tol[j]>=p*3-4 && tol[j]<=p*3-3 && s)
			{
				cnt++;
				s--;
			}
		}
		printf("Case #%d: ",i);
		printf("%d\n",cnt);
	}
	return 0;
}