#include <iostream>
#include <queue>
#include <cstdio>

using namespace std;

struct diner
{
	int p;
	int help;
	bool operator<(const diner& d) const
	{
		return (p / help + (p % help > 0)) <(d.p/d.help + (d.p % d.help > 0));
	}
};

int val(diner d)
{
	return (d.p/d.help + (d.p % d.help > 0));
}

int min(int a, int b)
{
	if (a < b)
		return a;
	return b;
}

int main()
{
	int cases, d;
	cin >> cases;
	for (int i = 0; i < cases; i++)
	{
		cin >> d;
		priority_queue<diner> q;
		int temp;
		for (int j = 0; j < d; j++)
		{
			cin >> temp;
			diner stuff = {temp, 1};
			q.push(stuff);
		}
		int minMin = val(q.top());
		int currMin = 0;
		while (val(q.top()) > 2)
		{
			diner stuff = q.top();
			q.pop();
			stuff.help++;
			currMin++;
			q.push(stuff);
			minMin = min(minMin, currMin + val(q.top()));
		}
		printf("Case #%d: %d\n", i + 1, minMin);
	}
}