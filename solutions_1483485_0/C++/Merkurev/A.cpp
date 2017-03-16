#include <iostream>
using namespace std;

char c;
char q[30]={
	'y','h','e','s','o','c','v','x','d','u','i'
	,
	'g','l','b','k','r','z','t','n','w','j','p','f','m','a','q'
};

void main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);

	int ntest=1;
	int n;
	scanf("%d",&n);
	bool b=false;
	while (true)
	{
		if (scanf("%c",&c)<=0)
			break;
		if (c=='\n')
		{
			
			b=true;
			
			continue;
		}
		if (b==true)
		{
			if (ntest>1)
				printf("\n");
			printf("Case #%d: ",ntest++);
			b=false;
		}
		if (c==' ')
		{
			printf(" ");
			continue;
		}
		else
			printf("%c",q[c-'a']);
	}
	printf("\n");
}