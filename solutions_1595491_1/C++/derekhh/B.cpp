#include<stdio.h>
#include<algorithm>
using namespace std;

int t[100];

int main()
{
	int T,no=0;
	scanf("%d",&T);
	while(T--)
	{
		int n,s,p;
		scanf("%d%d%d",&n,&s,&p);
		for(int i=0;i<n;i++)
			scanf("%d",&t[i]);
		int cnt=0,rem=s;
		for(int i=0;i<n;i++)
		{
			if(t[i]>=p+max(0,p-1)+max(0,p-1))
				cnt++;
			else if(t[i]>=p+max(0,p-2)+max(0,p-2)&&rem>0)
				cnt++,rem--;
		}
		printf("Case #%d: %d\n",++no,cnt);
	}
}