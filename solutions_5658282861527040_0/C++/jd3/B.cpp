#include<iostream>
#include<cstdio>

using namespace std;


int main()
{
	int a,b;
	int k;
	int t;
	
	scanf("%d",&t);
	for(int x = 1 ; x <= t ; x++)
	{
		int ans = 0;
		scanf("%d%d%d",&a,&b,&k);
		 	
		for(int i = 0 ; i < a ; i++)
			for(int j = 0 ; j < b ; j++)
				if((i&j) < k)
					ans++;
					
		printf("Case #%d: %d\n",x,ans);
	}
	return 0;
}

