#include <cassert>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>


int parse(char c)
{
	switch(c)
	{
	case '1': return 0;
	case 'i': return 1;
	case 'j': return 2;
	case 'k': return 3;
	default:
		assert(false);
	}
}

std::string show(int x)
{
	static const char * table[] = {"1", "i", "j", "k"};
	return std::string(x > 3 ? "-" : "") + std::string(table[x & 3]);
}

int mul(int a, int b)
{
	assert(a < 8 && b < 8);
	
	static int table[4][4] = {
		{0, 1, 2, 3},
		{1, 4, 3, 6},
		{2, 7, 4, 1},
		{3, 2, 5, 4}
	};

	return (a & 4) ^ (b & 4) ^ table[a & 3][b & 3];
}

int power(int x, long long p)
{
	int r = 0;
	for( ; p > 0; p /= 2)
	{
		if(p & 1)
			r = mul(r, x);
		x = mul(x, x);
	}
	return r;
}


bool solve(const std::vector<int> & f, long long x)
{
	const int n = (int)f.size();
	
	int prod = 0;
	for(int i = 0; i < n; i++)
		prod = mul(prod, f[i]);

	{
		const int target = mul(mul(parse('i'), parse('j')), parse('k'));
		if(power(prod, x) != target || n * x < 3)
			return false;
	}

	int carry = 0, step = 0;
	int target[] = { parse('i'), parse('j'), -1 };

	for(long long xi = 0; xi < std::min(x, 16LL); xi++)
		for(int i = 0; i < n; i++)
		{
			carry = mul(carry, f[i]);
			if(carry == target[step])
			{
				carry = 0;
				step++;
			}
		}

	return step > 1;
}

int main()
{
	//for(int i = 0; i < 4; i++)
	//{
	//	for(int j = 0; j < 4; j++)
	//		printf("%s ", show(mul(i, j)).c_str());
	//	printf("\n");
	//}

	freopen("input.txt", "r", stdin);

	int tn;
	scanf("%i\n", &tn);

	for(int test = 1; test <= tn; test++)
	{
		int l;
		long long x;
		scanf("%i %lli\n", &l, &x);

		char buf[1 << 16];
		scanf("%s\n", buf);
		assert((int)strlen(buf) == l);

		std::vector<int> f;
		for(int i = 0; i < l; i++)
			f.push_back(parse(buf[i]));
			
		assert(f.size() == strlen(buf));

		bool res = solve(f, x);

		printf("Case #%i: %s", test, res ? "YES" : "NO");
		if(test < tn)
			printf("\n");
	}

	return 0;
}

