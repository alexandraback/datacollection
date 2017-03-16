#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<set>
#include<map>
#include<vector>
#include<string>
#include<queue>
using namespace std;


void Ver(int& s, int p)
{
	if(p == 0)
		return;
	int c = 0;
	while(c != p)
	{
		c += s++;
		printf("N");
		if(c == p)
			break;
		c -= s++;
		printf("S");
	}
}

void Hor(int& s, int p)
{
	if(p == 0)
		return;
	int c = 0;
	int d = 0;
	if(p > 0 && s <= p ||
		p < 0  && -s < p)
	{
		while(c != p)
		{
			c += s++;
			printf("E");
			if(c == p)
				break;
			c -= s++;
			printf("W");
		}
	}
	else
	{
		while(c != p)
		{
			c -= s++;
			printf("W");
			if(c == p)
				break;
			c += s++;
			printf("E");
		}
	}
}

int main()
{
	freopen("B.in", "r", stdin);
	freopen("B.out", "w", stdout);

	int T;
	int tc = 1; 
	scanf("%d", &T);

	while(T)
	{
		T--;
		printf("Case #%d: ", tc);
		tc++;

		int x, y;
		scanf("%d%d", &x, &y);
		int s = 1;
		Ver(s, y);
		Hor(s, x);
		printf("\n");
	}

	return 0;
}