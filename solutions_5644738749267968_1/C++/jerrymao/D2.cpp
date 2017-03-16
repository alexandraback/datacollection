#include <cstdio>
#include <algorithm>
#include <list>

using namespace std;

list<double> naomi, ken;
char __input[64];
int t;
int n;

int war()
{
	list<double>::iterator it=naomi.begin();
	list<double>::iterator it2=ken.begin();
	int ans = 0;
	while (it != naomi.end() && it2 != ken.end())
	{
		if (*it < *it2)
		{
			it++; it2++;
		} else
		{
			ans++; it2++;
		}
	}
	return ans;
}

int deceit()
{
	list<double>::iterator it=naomi.begin();
	list<double>::iterator it2=ken.begin();
	int ans = 0, current = 0;
	while (it != naomi.end() && it2 != ken.end())
	{
		if (*it > *it2)
		{
			it++; it2++;
		} else
		{
			current++; it++;
		}
		if (current > ans)
			ans = current;
	}
	return ans;
}

int main()
{
	printf("Input file = "); fflush(stdout);
	scanf("%s", __input);
	freopen(__input, "r", stdin);
	freopen("out.D.txt", "w", stdout);

	scanf("%d", &t);
	for (int _ = 1;_ <= t;_++)
	{
		printf("Case #%d: ", _);
		scanf("%d", &n);
		naomi.clear(); ken.clear();
		for (int i = 0;i < n;i++)
		{
			double temp;
			scanf("%lf", &temp);
			naomi.push_back(temp);
		}
		for (int i = 0;i < n;i++)
		{
			double temp;
			scanf("%lf", &temp);
			ken.push_back(temp);
		}
		naomi.sort(); ken.sort();
		printf("%d %d\n", n-deceit(), war());
	}

	return 0;
}
