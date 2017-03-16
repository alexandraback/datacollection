#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
int test,a,ans;
int main()
{
	freopen("A-large.in","r",stdin);
	freopen("A2.out","w",stdout);
	cin>>test;
	for (int nmb=1;nmb<=test;nmb++)
	{
		scanf("%d",&a);
		if (!a) printf("Case #%d: INSOMNIA\n",nmb);
		else
		{
			ans=0;
			for (int i=1;;i++)
			{
				int temp=a*i;
				while (temp)
				{
					ans|=(1<<(temp%10));
					temp/=10;
				}
				if (ans==1023)
				{
					printf("Case #%d: %d\n",nmb,i*a);
					break;
				}
			}
		}
	}
	return 0;
}
