#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> reduce(int num, int n)
{
	vector<int> v;
	while(num > 0)
	{
		v.push_back(num/n);
		num -= num/n;
		n--;	
	}

	return v;
}

int main(int argc, char const *argv[])
{
	int t, d, arr[1005], c;
	scanf("%d", &t);

	for(int i = 1; i <= t; i++)
	{
		scanf("%d", &d);
		for(int j = 0; j < d; j++)
			scanf("%d", &arr[j]);
	
		vector<int> diners(arr, arr+d);
		vector<int> times;
		make_heap(diners.begin(), diners.end());
		c = 0;

		while(diners.front() != 0)
		{
			times.push_back(diners.front()+c);

			if(int(sqrt(diners.front())) > 1)
			{
				int front = diners.front();
				pop_heap(diners.begin(), diners.end());
				diners.pop_back();

				vector<int> v;
				if(diners.empty() or int(sqrt(front)) > diners.front())
					v = reduce(front, int(sqrt(front)));
				else
					v = reduce(front, 2);

				for(int j = 0; j < v.size(); j++)
				{
					diners.push_back(v[j]);
					push_heap(diners.begin(), diners.end());
				}

				c += (v.size()-1);
			}

/*			if(diners.front()%2 == 0)
			{
				int temp = diners.front();
				pop_heap(diners.begin(), diners.end());
				diners.pop_back();
				diners.push_back(temp/2);
				push_heap(diners.begin(), diners.end());
				diners.push_back(temp/2);
				push_heap(diners.begin(), diners.end());
			}
*/
			else
			{
				for(int j = 0; j < diners.size(); j++)
					diners[j] -= 1;

				c++;
			}
		}

		int min_time = 2000000000;
		for(int j = 0; j < times.size(); j++)
			if(times[j] < min_time)
				min_time = times[j];

		printf("Case #%d: %d\n", i, min_time);
	}

	return 0;
}