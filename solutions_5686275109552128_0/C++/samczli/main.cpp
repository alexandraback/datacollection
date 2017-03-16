#include <vector>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <queue>
#include <stack>
#include <assert.h>
#include <functional>
using namespace std;

static int minTimeGlobal = 0;


int minTime2(priority_queue<int> &queue, int timePast)
{
	if (queue.top() <= 2)
		return timePast + queue.top();

	priority_queue<int> q2 = queue;
	int *front = &(q2.top());
	for (int i = 0; i < q2.size(); ++i)
	{
		*(front + i) = *(front + i) - 1;
	}
	int time1 = minTime2(q2, timePast + 1);
	
	int left = queue.top() >> 1;
	int right = queue.top() - left;
	queue.pop();
	if (left > 0)
		queue.push(left);
	if (right > 0)
		queue.push(right);

	int time2 = minTime2(queue, timePast + 1);
	int val = time1 < time2 ? time1 : time2;
	return val;
}


inline int minTime(priority_queue<int> &queue, int timePast)
{
	if (queue.empty())
		return timePast;
	if (timePast >= minTimeGlobal)
		return minTimeGlobal;
	if (queue.top() == 1)
		return timePast + 1;

	int val1 = queue.top() + timePast;
	if (val1 < minTimeGlobal)
		minTimeGlobal = val1;

	int left = queue.top() >> 1;
	int right = queue.top() - left;
	queue.pop();
	if (left > 0)
		queue.push(left);
	if (right > 0)
		queue.push(right);

	int val2 = minTime(queue, timePast + 1);
	int tmpMin = val1 < val2 ? val1 : val2;

	return tmpMin;
}



int main()
{
	ifstream file;
	ofstream output;
	file.open("data.in");
	output.open("data.out");
	int T;
	file >> T;
	for (int i = 1; i <= T; ++i)
	{
		int size;
		file >> size;
		priority_queue<int> queue;
		for (int j = 0; j < size; ++j)
		{
			int tmp;
			file >> tmp;
			queue.push(tmp);
		}
		minTimeGlobal = queue.top();
		int min = minTime(queue, 0);
		output << "Case #" << i << ": " << min;
		if (i != T)
			output << endl;
	}
	file.close();
	output.close();
	return 0;
}