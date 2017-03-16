//Mateusz Janczura
#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
#include <stack>
#include <cstdlib>
#include <ctime>
using namespace std;
stack <char> glo;
int x, y;
bool rek(int a, int b, int l)
{
	if(l > 30) return false;
	if(a == x && b == y) 
		return true;
	
	int k = rand() % 3;
	if(k == 0)
	{	
		if(rek(a + l, b, l + 1)) 
		{
			glo.push('E');
			return true;
		}
		else if(rek(a - l, b, l + 1))
		{
			glo.push('W');
			return true;
		}
		else if(rek(a, b + l, l + 1))
		{
			glo.push('N');
			return true;
		}
		else if(rek(a, b - l, l + 1)) 
		{
			glo.push('S');
			return true;
		}
	}
	else if(k == 1)
	{	
		
		if(rek(a - l, b, l + 1))
		{
			glo.push('W');
			return true;
		}
		if(rek(a + l, b, l + 1)) 
		{
			glo.push('E');
			return true;
		}
		if(rek(a, b - l, l + 1)) 
		{
			glo.push('S');
			return true;
		}
		if(rek(a, b + l, l + 1))
		{
			glo.push('N');
			return true;
		}
	}
	else if(k == 2)
	{	 
		if(rek(a, b - l, l + 1)) 
		{
			glo.push('S');
			return true;
		}
		if(rek(a + l, b, l + 1)) 
		{
			glo.push('E');
			return true;
		}
		if(rek(a, b + l, l + 1))
		{
			glo.push('N');
			return true;
		}
		if(rek(a - l, b, l + 1))
		{
			glo.push('W');
			return true;
		}
	}
	else if(k == 3)
	{	
		
		if(rek(a, b + l, l + 1))
		{
			glo.push('N');
			return true;
		}
		if(rek(a, b - l, l + 1)) 
		{
			glo.push('S');
			return true;
		}
		if(rek(a + l, b, l + 1)) 
		{
			glo.push('E');
			return true;
		}
		if(rek(a - l, b, l + 1))
		{
			glo.push('W');
			return true;
		}
	}
	return false;
}
int main()
{
	srand(time(0));
	int Z, li;
	scanf("%d", &Z);
	for(li = 1; li <= Z; li++)
	{
		scanf("%d %d", &x, &y);
		printf("Case #%d: ", li);
		rek(0, 0, 1);
		while(!glo.empty())
		{
			printf("%c", glo.top());
			glo.pop();
		}
		puts("");
	}
	return 0;
}
