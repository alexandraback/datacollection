#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <utility>
using namespace std;

int main(void)
{
	int t,x,r,c;
	scanf("%d",&t);
	for(int rep = 1;rep <= t;rep++)
	{
		scanf("%d%d%d",&x,&r,&c);
		if(x >= 7)
			printf("Case #%d: RICHARD\n", rep);
		else if((r*c) % x == 0 && r*c >= x*(x-1))
			printf("Case #%d: GABRIEL\n", rep);
		else
			printf("Case #%d: RICHARD\n", rep);
	}
}
