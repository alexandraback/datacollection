#include <iostream>
#include <algorithm>


using namespace std;

int tab[1000000];

int main()
{
	ios_base::sync_with_stdio(0);
	int t, start, n, counter, current, mult, temp;
	cin >> t;
	for (int i = 1; i <= t; i++)
	{
		counter = 0;
		cin >> start >> n;
		for (int j = 0; j < n; j++)
			cin >> tab[j];

		sort(tab, tab+n);
		current = start;
		for (int j = 0; j < n; j++)
		{
			if (tab[j] < current)
				current += tab[j];
			else
			{
				mult = 0;
				temp = current;
				while (true)
				{
					if (tab[j] >= temp)
					{
						temp += temp - 1;
						mult++;
					}
					else break;
					if (temp <= 1)
					{
						mult = 999999999;
						break;
					}
				}
				if (mult >= n - j)
				{
					counter += n - j;
					break;
				}
				else
				{
					current = temp + tab[j];
					counter += mult;
				}
			}
		}
		cout << "Case #" << i << ": " << counter << endl;
	}
	return 0;
}