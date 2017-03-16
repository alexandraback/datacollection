#include<bits/stdc++.h>
#define md 1000000007
#define ll  long long
#define gc getchar//_unlocked
using namespace std;

int main()
{
	
    int test;
	int r,c,x;
	int a[10]={0,1,1,2,2,3,3};
	scanf("%d",&test);
	for(int j=1;j<=test;j++){
		printf("Case #%d: ",j);
		scanf("%d%d%d",&x,&r,&c);
		//printf("%d %d %d\n",x,r,c);
		if(x>=7)
			printf("RICHARD\n");
		else
		{
			if( (r*c)%x)
				printf("RICHARD\n");
			else if( min(r,c)<a[x] )
				printf("RICHARD\n");
			else if( min(r,c)<=a[x] && x>3)
				printf("RICHARD\n");
			else
				printf("GABRIEL\n");
		}
		
		
	}
	
    
    return 0;
}