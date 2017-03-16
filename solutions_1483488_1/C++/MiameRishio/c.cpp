#include <iostream>
using namespace std;

int nTestCase;
int n, m, ans;
int num_hash[3000000];

void init()
{
	scanf("%d %d", &n, &m);
}

int getBit(int x)
{
	int ans = 0;
	while (x > 0)
	{
		ans++;
		x /= 10;
	}
	return ans;
}
void process()
{
	ans = 0;
	int tmp;
	int a[8] = {1, 10, 100, 1000, 10000, 100000, 1000000};
	for (int i = n; i <= m; i++)
		num_hash[i] = 0;

	for (int i = n; i <= m; i++)
	{
		int bit = getBit(i);
		for (int j = 1; j < bit; j++)
		{
			//cout << i / a[bit - j] << endl;
			//cout << i % a[bit - j] * a[j] << endl;
			tmp = i % a[bit - j] * a[j] + i / a[bit - j];
			//cout << tmp;
			if (n <= tmp && tmp <= m && i < tmp)
			{
				if (num_hash[tmp] != i)
				{
					num_hash[tmp] = i;
					ans++;
				}
				//cout << i << " " << tmp << endl;
			}
		}
	}
}

int main()
{
	freopen("C-large.in", "r", stdin);
	freopen("C-large.out", "w", stdout);
	scanf("%d", &nTestCase);
	for (int i = 0; i < nTestCase; i++)
	{
		init();
		process();
		printf("Case #%d: %d\n", i + 1, ans);
	}
	return 0;
}