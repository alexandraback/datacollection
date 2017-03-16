#include <cstdio>
#include <algorithm>

using namespace std;

int przyp()
{
	int d;
	scanf("%d", &d);
	vector<int> p;
	for(int i = 0; i < d; i++)
	{
		int x;
		scanf("%d", &x);
		p.emplace_back(x);
	}
	int wyn = 5000;
	for(int i = 1; i <= 1000; i++)
	{
		int l = i;
		for(int j : p)
			l += (j + i - 1) / i - 1;
		wyn = min(wyn, l);
	}
	return wyn;
}

int main()
{
	int t;
	scanf("%d", &t);
	for(int i = 1; i <= t; i++)
		printf("Case #%d: %d\n", i, przyp());
	return 0;
}
