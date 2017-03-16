#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <stdio.h>

using namespace std;

#define MAXP 1010

int main(void)
{
	int t;

	cin >> t;

	for (int i=1; i<=t; i++)
	{
		int d;
		vector <int> p;
		priority_queue <int> pqueue;
		int time;
		int hash[MAXP] = {0};

		cin >> d;

		for (int j=0; j<d; j++)
		{
			int pi;
			cin >> pi;

			p.push_back(pi);
		}

		for (int j=0; j<p.size(); j++)
		{
			hash[p[j]]++;
		}

		for (int j=0; j<MAXP; j++)
		{
			if (hash[j] > 0)
				pqueue.push(j);
		}

		time = 0;

		while (1)
		{
			int max;
			int cost;
			int gain;
			int nextmax;
			stack <int> tmpstack;
			int secondmax;

			max = pqueue.top();

			pqueue.pop();
			tmpstack.push(max);

			cost = hash[max];
			gain = max/2;

			nextmax = max;

			while (!pqueue.empty())
			{
				secondmax = pqueue.top();

				if (max != nextmax)
					cost += hash[nextmax];

				gain = min(max/2, max-secondmax);

				if (gain > cost)
					break;

				pqueue.pop();
				tmpstack.push(secondmax);

				nextmax = secondmax;
			}

			if (pqueue.empty() && (gain <= cost))
			{
				if (max != nextmax)
					cost += hash[nextmax];

				gain = min(max/2, max-0);
			}

			if (gain > cost)
			{
				if (hash[max - max/2] == 0)
					pqueue.push(max - max/2);
				if (hash[max - (max+1)/2] == 0)
					pqueue.push(max - (max+1)/2);

				hash[max - max/2] += cost;
				hash[max - (max+1)/2] += cost;

				time += cost;

				continue;
			}

		restore_queue:
			while (!tmpstack.empty())
			{
				pqueue.push(tmpstack.top());
				tmpstack.pop();
			}
			break;
		}

		if (!pqueue.empty())
			time += pqueue.top();

		printf("Case #%d: %d\n", i, time);

	}
	return 0;
}
