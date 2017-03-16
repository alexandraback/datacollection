#include <iostream>
#include <algorithm>
#include <cstdio>
#include <deque>
#include <cmath>

using namespace std;

const int BufferSize = 1000;

char buf[BufferSize];
int n;
int lane[BufferSize];
double speed[BufferSize];
double pos[BufferSize];
int status[BufferSize];

void Int2Lane(int s, int *lane)
{
	for (int i = 0; i < n; ++i)
		lane[i] = (s >> i) & 1;
}

int Lane2Int(int *lane)
{
	int s = 0;
	for (int i = 0; i < n; ++i)
		s |= (lane[i] << i);
	return s;
}

bool IsConsisent(int s)
{
//	cout << "status" << endl;
//	for (int i = 0; i < n; ++i)
//		cout << ((s>>i) &1) << " ";
//	cout << endl;

	for (int i = 0; i < n; ++i)
	{
		for (int j = i+1; j < n; ++j)
		{
			if (((s >> i)&1) == ((s >> j)&1) && fabs(pos[i] - pos[j]) < 5 - 1e-6)
			{
				return false;
			}
		}
	}

	return true;
}

void Move(double time)
{
	for (int i = 0; i < n; ++i)
		pos[i] += speed[i] * time;
}

bool Possible(int *status)
{
	for (int i = 0; i < (1 << n); ++i)
	{
		if (status[i])
			return true;
	}
	return false;
}

void SearchStatus(int *status)
{
	deque<int> qu;
	for (int i = 0; i < (1 << n); ++i)
	{
		if (status[i])
			qu.push_back(i);
	}

	while (!qu.empty())
	{
		int x = qu.front();
		qu.pop_front();

		for (int i = 0; i < n; ++i)
		{
			int y = (x ^ (1 << i));
			if (status[y] == 0 && IsConsisent(y))
			{
				qu.push_back(y);
				status[y] = 1;
			}
		}
	}
}

void ValidateStatus(int *status)
{
	for (int i = 0; i < (1 << n); ++i)
	{
		if (status[i])
		{
			status[i] = IsConsisent(i);
		}
	}
}

double NextCollide()
{
	double minimum = 1e100;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (speed[i] > speed[j] + 1e-6)
			{
				if (pos[i] < pos[j] - 5 - 1e-6)
				{
					double t = (pos[j] - 5 - pos[i]) / (speed[i] - speed[j]);
					if (t < minimum)
						minimum = t;
				}
				else if (pos[i] < pos[j] + 5 - 1e-6)
				{
					double t = (pos[j] + 5 - pos[i]) / (speed[i] - speed[j]);
					if (t < minimum)
						minimum = t;
				}
			}
		}
	}

	return minimum;
}

int main(int argc, char *argv[])
{
	int t;
	scanf("%d", &t);
	for (int index = 1; index <= t; ++index)
	{
		scanf("%d", &n);
		for (int i = 0; i < n; ++i)
		{
			scanf("%s %lf %lf", buf, &speed[i], &pos[i]);
			if (buf[0] == 'L')
				lane[i] = 0;
			else
				lane[i] = 1;
		}

		fill_n(status, BufferSize, 0);
		status[Lane2Int(lane)] = 1;

		int possible = false;
		double time = 0;
		while (true)
		{
			ValidateStatus(status);
			SearchStatus(status);
			if (!Possible(status))
				break;

			double delta = NextCollide();
			Move(1e-4);
			ValidateStatus(status);
			if (!Possible(status))
				break;

			//printf("%.6f %.6f\n", time, delta);

			if (delta == 1e100)
			{
				possible = true;
				break;
			}
			else
			{
				Move(delta - 1e-4);
				time += delta;
			}
		}

		if (possible)
			printf("Case #%d: Possible\n", index);
		else
			printf("Case #%d: %.6f\n", index, time);
	}

	return 0;
}

