#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

typedef pair<int,int> Pair ; 

int a[102] ; 

int main()
{
	int t;
	int n , s, p ; 
	int i ; 
	int curr = 0;
	int ans ;
	int val ; 
	int total = 1 ;
	scanf("%d",&t);

	while(t--)
	{
		curr = 0 ; 
		ans = 0 ; 
		scanf("%d%d%d",&n,&s,&p);
		for(i = 0 ; i < n ; i++)
			scanf("%d",&a[i]);
		curr = s ; 

		for(i = 0 ; i < n; i++)
		{
			if(a[i] == 0)
			{
				if(p == 0)
					ans++;
			}
			else if(a[i] == 1)
			{
				if( p <= 1)
					ans++ ; 
			}
			else
			{
				if(a[i] % 3 == 0)
					val = a[i]/3 ; 
				else if(a[i] % 3 == 1)
					val = (a[i] - 1)/3 + 1; 
				else 
					val = (a[i] - 2)/3 + 1 ;
				if(val >= p)
					ans ++ ; 
				else
				{
					if(curr > 0)
					{
						if(a[i] % 3 == 0)
							val = (a[i] - 3)/3 + 2 ; 
						else if(a[i] % 3 == 1)
							val = (a[i] - 4)/3 + 2 ; 
						else
							val = (a[i] - 2)/3 + 2 ; 
						if(val >= p)
						{
							ans++;
							curr -- ; 
						}
					}
				}
			}
		}
		printf("Case #%d: %d\n",total++,ans);
	}
	return 0;
}
