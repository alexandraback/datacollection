#include <stdio.h>
#include<string.h>
#include <deque>
int main()
{
	using namespace std;
	freopen( "A-small-attempt0.in", "r", stdin );
	freopen( "output.txt", "w", stdout );
	int n,t,i,sum,lol,len;
	deque<char> rsv;
	char a[1001];
//	bool rsv;
	scanf("%d",&t);
	for(lol=1;lol<=t;lol++)
	{
		scanf(" %s",&a[0]);
		n=strlen(a);
		rsv.push_back(a[0]);
		for(i=1;i<n;i++)
		{
			if(a[i]>=rsv[0])
			rsv.push_front(a[i]);
			else 
			rsv.push_back(a[i]);
		}
		printf("Case #%d: ",lol);
		for(i=0;i<n;i++)
		{
			printf("%c",rsv[i]);
		}
		printf("\n");
		rsv.clear();
	}
	return 0;
}
		
