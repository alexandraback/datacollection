#include<cstdio>
using namespace std;
char ch[1003];
int n;
int check(int x)
{ // printf("Checking for %d \n",x);
	int np=x;
	for(int i=0;i<=n;i++)
	{
		int tmp=ch[i]-'0';
		if(i>np && tmp>0) return 0;
		np+=tmp;
	}
	// printf("reing 1 \n",x);
	
	return 1;
}
int main()
{
	int ntc; scanf("%d",&ntc);
	for(int tc=1;tc<=ntc;tc++)
	{
		printf("Case #%d: ",tc);
		 scanf("%d",&n);
		scanf("%s",&ch);
		int b=0,e=20005;
		int mid;
		while(b<=e)
		{
			int mid=(b+e)/2;
			if(check(mid)) e=mid-1;
			else b=mid+1;
		}
		
		printf("%d\n",e+1);
		
		
	}
}
