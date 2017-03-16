#include<cstdio>
using namespace std;

int main()
{
int t;
scanf("%d", &t);
for (int tt=1; tt<=t; tt++)
{
	int x, y;
	scanf("%d%d", &x, &y);
	printf("Case #%d: ", tt);
	if(x>=0) 
		for (int i=1; i<=x; i++)
			printf("WE");
	else
		for (int i=1; i<=-x; i++)
			printf("EW");
	if(y>=0) 
		for (int i=1; i<=y; i++)
			printf("SN");
	else
		for (int i=1; i<=-y; i++)
			printf("NS");
	printf("\n");	
		
	
	
	
	
			
}
return 0;
}
