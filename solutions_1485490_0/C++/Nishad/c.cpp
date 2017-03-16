#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int max_n;

int func(vector<int> boxes, vector<int> toys, int n)
{
	if (boxes.size() <= 1 || toys.size() <= 1)
	{
		if (n > max_n)
			max_n = n;
		return n;
	}

	int mn = min(boxes[0], toys[0]);

	if (mn > 0)
	{
		if (boxes[1] == toys[1])
		{
			n += mn;
			boxes[0] -= mn;
			toys[0] -= mn;
			return func(boxes, toys, n);
		}
		else
		{
			boxes[0] -= mn;
			func(boxes, toys, n);

			boxes[0] += mn;
			toys[0] -= mn;
			func(boxes, toys, n);
		}
	}
	else
	{
		if (boxes[0] == 0)
		{
			vector<int> new_boxes;
			for (int i = 2; i < boxes.size(); i++)
				new_boxes.push_back(boxes[i]);

			return func(new_boxes, toys, n);
		}
		else if (toys[0] == 0)
		{
			vector<int> new_toys;
			for (int i = 2; i < toys.size(); i++)
				new_toys.push_back(toys[i]);

			return func(boxes, new_toys, n);
		}
	}

	return n;
}

int main()
{
	int c, t;

	cin >> t;
	for (c = 0; c < t; c++)
	{
		int n, m;

		cin >> n >> m;
		vector<int> boxes(2*n), toys(2*m);

		for (int i = 0; i < 2*n; i++)
		{
			cin >> boxes[i];
		}

		for (int i = 0; i < 2*m; i++)
		{
			cin >> toys[i];
		}

		max_n = 0;
		func(boxes, toys, 0);

		cout << "Case #" << (c+1) << ": " << max_n << endl;
	}

	return 0;
}
