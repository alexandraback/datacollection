#include <cstdio>
#include <set>
using namespace std;
bool isPowofTen(int n)
{
	while (n >= 10)
	{
		if (n % 10 != 0) return false;
		n /= 10;
	}
	if (n == 1) return true;
	return false;
}

void push(set<int>&container, int target)
{
	while (target > 0)
	{
		container.insert(target % 10);
		target /= 10;
	}
}

void solve(int answerCnt)
{
	set<int> container;
	set<int> past;
	int n; scanf("%d", &n);
	int mult = 1;
	push(container, n);
	while (true)
	{
		mult++;
		if (isPowofTen(mult))
		{
			if (container.size() == past.size())
			{
				printf("Case #%d: INSOMNIA\n", answerCnt); return;
			}
			else past = container;
		}
		push(container, n * mult);
		if (container.size() == 10)
		{
			printf("Case #%d: %d\n", answerCnt,mult*n); return;
		}
	}
}


int main()
{
	freopen("A-large.in", "r", stdin);
	freopen("output.txt", "w", stdout);
	int T; scanf("%d", &T);
	for (int i = 1; i <= T; i++)
	{
		solve(i);
	}
}