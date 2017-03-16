#include <cassert>
#include <cstdio>
#include <algorithm>


bool solve(int x, int a, int b)
{
	if(a > b) std::swap(a, b);
	const int t = a * b;

	if(x == 1) return false;
	if(t % x != 0) return true;
	if(x == 2) return false;
	
	const int h = 1 + ((x - 1) / 2);
	const int w = 1 + (x - h);
	assert(h <= w);

	if(h > a) return true;
	if(t == x) return true;
	if(x == 3) return false;
	
	if(a == h)
	{
		for(int p = 0; p < w; p++)
		{
			bool ok = false;
			for(int i = 0; i <= b - w; i++)
			{
				int left = i * a + p * (a - 1);
				if(left % x == 0)
					ok = true;
			}
			
			if(!ok)
				return true;
		}
	}
	
	return false;
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

