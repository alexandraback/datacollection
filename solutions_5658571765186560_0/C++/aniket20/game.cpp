#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
	int t,x,r,c,l1,r1,i,cnt=1;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d %d",&x,&r,&c);
		if(((r*c)%x)!=0)
		{
			printf("Case #%d: RICHARD\n",cnt);
			cnt++;
			continue;
		}
		if(x==2 || x==1)
		{
			printf("Case #%d: GABRIEL\n",cnt);
			cnt++;
			continue;
		}
		if(x==3)
		{
			if((r==2 && c==3)||(r==3 && c==2)||(r==3 && c==3)||(r==3 && c==4)||(r==4 && c==3))
			{
				printf("Case #%d: GABRIEL\n",cnt);
			}
			else
			{
				printf("Case #%d: RICHARD\n",cnt);
			}
			cnt++;
			continue;
		}
		if(x==4)
		{
			if((r==3 && c==4)||(r==4 && c==3)||(r==4 && c==4))
			{
				printf("Case #%d: GABRIEL\n",cnt);
			}
			else
			{
				printf("Case #%d: RICHARD\n",cnt);
			}
			cnt++;
			continue;
		}
	}
	return 0;
}
