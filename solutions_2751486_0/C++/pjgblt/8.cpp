#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool test(string name, int start, int end, int n)
{
	int counter;
	int i;
	int maxCounter = 0;
	
	counter = 0;
	for (i = start; i <= end; i++)
	{
		if (name[i] == 'a' || name[i] == 'e' || name[i] == 'i' || name[i] == 'o' || name[i] == 'u')
		{
			counter = 0;
		}
		else
		{
			counter++;
		}
		maxCounter = max(maxCounter, counter);
	}
	
	return (maxCounter >= n);
}

int main()
{
	string name;
	int n;
	int cases;
	int c;
	int i, j;
	int l;
	int result;
	
	cin >> cases;
	for (c = 1; c <= cases; c++)
	{
		result = 0;
		cout << "Case #" << c << ": ";
		
		cin >> name;
		cin >> n;
		l = name.length();
		
		for (i = 0; i < l; i++)
		{
			for (j = i; j < l; j++)
			{
				if (test(name, i, j, n))
				{
					result++;
				}
			}
		}
		
		cout << result;
		cout << endl;
	}
	
	return 0;
}