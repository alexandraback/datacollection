#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>


using namespace std;

double mas[25][25] = {0.0};
vector < pair<int, int> > can;

void dfs(int x, int y)
{
	queue < pair<int,int> > q;
	q.push(make_pair(x, y));
	while (!q.empty())
	{
		pair <int, int> buf = q.front();
		q.pop();
		if (buf.second == 20)
		{
			can.push_back(buf);
			continue;
		}
		if ((mas[buf.second + 1][buf.first + 1] != 0.0) 
			&& (mas[buf.second + 1][buf.first - 1] != 0.0) 
			&& ((mas[buf.second + 2][buf.first] != 0.0) || (buf.second + 2 > 20)) 
			&& ((mas[buf.second + 1][buf.first + 1] >= 1.0)||(mas[buf.second + 1][buf.first - 1] >= 1.0)))
		{
			can.push_back(buf);
		}

		if ((mas[buf.second + 2][buf.first] < 1.0) && (buf.second + 2 <= 20))
			q.push(make_pair(buf.first, buf.second + 2));
		if ((mas[buf.second + 2][buf.first] != 0.0) || (buf.second + 2 > 20))
		{
			if ((mas[buf.second + 1][buf.first + 1] < 1.0) && (buf.second + 1 <= 20))
				q.push(make_pair(buf.first + 1, buf.second + 1));
			if ((mas[buf.second + 1][buf.first - 1] < 1.0) && (buf.second + 1 <= 20))
				q.push(make_pair(buf.first - 1, buf.second + 1));
		}
	}
}

int main()
{
	freopen("test.in", "r", stdin);
	freopen("test.out", "w", stdout);
	int t;
	scanf("%d ", &t);
	
	
	for (int k = 0; k < t; k++)
	{
		
		long long res = 0;

		for (int i = 0; i < 21; i++)
			for (int j = 0; j < 21; j++)
				mas[i][j] = 0.0;

		int N,x,y;
		scanf("%d %d %d ", &N, &x, &y);
		//mas[20][10] = 1.0;

		for (int i = 0; i < N; i++)
		{
			can.clear();
			dfs(10, 0);
			double cur = 1.0 / (double)can.size();
			for (int j = 0; j < can.size(); j++)
			{
				pair <int, int> buf = can[j];
				mas[buf.second][buf.first] += cur;
			}

		}

		if ((abs(x) > 10) || (y > 20))
			printf("Case #%d: 0\n", k + 1);
		else
		{
			double ress = mas[20 - y][x + 10];
			if (ress > 1.0)
				ress = 1.0;
			printf("Case #%d: %.8lf\n", k + 1, ress);
		}
	}
	return 0;
}