#include <cstdio>

const int EMPTY = -1;
const int MSS = 10; // max set size

struct set
{
	int content[MSS];
	
	set()
	{
		for (int i = 0; i < MSS; i++)
			content[i] = EMPTY;
	}
	
	int is_in_set(int element)
	{
		for (int i = 0; i < MSS; i++)
			if (content[i] == element)
				return i;
		return EMPTY;
	}
	
	void insert(int element)
	{
		if (is_in_set(element) != EMPTY) return;
		for (int i = 0; i < MSS; i++)
			if (content[i] == EMPTY)
			{
				content[i] = element;
				return;
			}
	}
	
	void erase(int element)
	{
		int which = is_in_set(element);
		if (which == EMPTY) return;
		content[which] = EMPTY;
	}
	
	void clear()
	{
		for (int i = 0; i < MSS; i++)
			content[i] = EMPTY;
	}
};

int pow_10[7] = {1, 10, 100, 1000, 10000, 100000, 1000000};

// max length of A and B is 7
int length(int x)
{
	int p = 1;
	int result;
	for (result = 1; x >= p; result++)
		p *= 10;
	return result-1;
}

int cycle(int x, int l, int digits) // digits must be in set {1, 2, ..., l-1}, l is length(x)
{
	return (pow_10[l-digits]*(x%pow_10[digits]) + (x/pow_10[digits])); // 10^(l-digits) * (x mod 10^digits) + (x / 10^digits)
}

int main()
{
	int z;
	scanf("%d", &z);
	for (int nr = 1; nr <= z; nr++)
	{
		int A, B;
		scanf("%d%d", &A, &B);
		int len = length(A);
		int answer = 0;
		if (len == 1)
			answer = 0;
		else
		{
			set S;
			for (int n = A; n < B; n++)
			{
				// check for all cycles of n
				for (int digs = 1; digs < len; digs++)
				{
					int m = cycle(n, len, digs);
					if (length(m) == len && m > n && m <= B) // check for leading zeros
					{
						if (S.is_in_set(m) == EMPTY)
						{
							S.insert(m);
							answer++;
						}
					}
				}
				S.clear();
			}
		}
		printf("Case #%d: %d\n", nr, answer);
	}
	return 0;
}
