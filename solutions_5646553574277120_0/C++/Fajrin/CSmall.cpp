#include "cstdio"
#include "cstring"

using namespace std;

int main(void)
{
	int t;
	scanf("%d", &t);
	for(int test = 1;test<=t;test++)
	{
		int ans = 0;
		bool there[32];
		memset(there, false, sizeof(there));
		
		int c,d,v;
		scanf("%d%d%d", &c, &d, &v);
		for(int i=0;i<d;i++)
		{
			int x;
			scanf("%d", &x);
			there[x] = true;
		}

		int buff = 0;
		int lol = 1;

		while(buff < v)
		{
			buff += lol;
			ans += !there[lol];
			lol++;
		}

		printf("Case #%d: %d\n", test, ans);
	}	
	return 0;
}

