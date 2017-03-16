#include <cassert>
#include <cstdio>
#include <algorithm>


bool solve(int x, int a, int b)
{
	if(a > b) std::swap(a, b);

	if(x == 1) return false;
	if((a * b) % x != 0) return true;
	if(x == 2) return false;

	if(1 + ((x - 1) / 2) > a) return true;
	if((a * b) / x == 1) return true;
	
	if(x == 3) return false;
	
	if(x == 4) return (a == 2); // ??
		
	assert(false);
}

int main()
{
	//for(int x = 1; x <= 4; x++)
	//	for(int b = 1; b <= 4; b++)
	//		for(int a = 1; a <= b; a++)
	//			solve(x, a, b);


	freopen("input.txt", "r", stdin);

	int tn;
	scanf("%i", &tn);
	
	for(int test = 1; test <= tn; test++)
	{
		int x, a, b;
		scanf("%i %i %i", &x, &a, &b);
		
		bool res = solve(x, a, b);
		printf("Case #%i: %s\n", test, res ? "RICHARD" : "GABRIEL");
	}
	
	return 0;
}

