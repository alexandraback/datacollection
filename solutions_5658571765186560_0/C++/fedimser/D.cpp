#include <bits/stdc++.h>
using namespace std;


int p[1000];
 

int main()
{
	int T,j;
	
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	
	scanf("%d",&T);
	
	for(j=1;j<=T;j++)
	{
		int x,a,b;
		
		scanf("%d %d %d",&x, &a, &b);
		if(a>b)swap(a,b);
		
		if((a*b)%x!=0) {printf("Case #%d: RICHARD\n",j);continue;}
		
		if(x==1 || x==2)
		{
			printf("Case #%d: GABRIEL\n",j);
		} 
		else if(x==3)
		{
			if(a>1) printf("Case #%d: GABRIEL\n",j);
			else printf("Case #%d: RICHARD\n",j);
		}
		else if(x==4)
		{
			if(a>=3 && b>=4) printf("Case #%d: GABRIEL\n",j);
			else printf("Case #%d: RICHARD\n",j);
		}
				
		
	}
	
	


	return 0;
}
