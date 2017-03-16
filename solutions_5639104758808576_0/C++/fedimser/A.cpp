#include <bits/stdc++.h>
using namespace std;


char buf[2000];

int main()
{
	int t,n,j;
	
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	
	
	scanf("%d",&t);
	
	for(j=1;j<=t;j++)
	{
		scanf("%d",&n);
		int inv=0,stn=0,s,i;
		scanf("%s",buf);
		
		for(i=0;i<=n;i++)
		{
			s = buf[i]-'0';
			if(s!=0 && stn<i)
			{
				int r = i-stn;
				inv+=r;
				stn+=r; 
			}
			stn+=s;
		}
		printf("Case #%d: %d\n",j,inv);
	}
	
	


	return 0;
}
