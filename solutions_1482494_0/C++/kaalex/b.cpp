//Aleksander "kaalex" Kramarz

#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cstring>
#include <queue>
#include <cmath>
#define f first
#define s second
using namespace std;

int z, a[1005], b[1005], t[1005], n;

int main()
{
	scanf("%d",&z);
	for(int i = 1; i <= z; i++)
	{
		scanf("%d",&n);
		for(int j = 0; j < n; j++)
		{
			t[j] = 0;
			scanf("%d%d",a+j,b+j);
		}
		int s = 0, res = 0;
		bool c = true;
		while(c)
		{
			c = false;
			for(int j = 0; j < n; j++)
				if(t[j] < 2 && s >= b[j])
				{
					s += 2-t[j];
					t[j] = 2;
					res++;
					c = true;
					break;
				}
			if(c)
				continue;
			for(int j = 0; j < n; j++)
				if(t[j] < 1 && s >= a[j])
				{
					s++;
					t[j] = 1;
					res++;
					c = true;
					break;
				}
		}
		c=true;		
		for(int j = 0; j < n; j++)
			if(t[j] < 2)
				c = false;
		printf("Case #%d: ",i);
		c?printf("%d\n",res):printf("Too Bad\n");
	}
}
