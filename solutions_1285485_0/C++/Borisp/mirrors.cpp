#define _CRT_SECURE_NO_DEPRECATE
#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include<deque>
#include<queue>
#include<stack>
#include<numeric>
#include<math.h>
#include<set>
#include<map>
#include<fstream>
#define epsilon 0.000000001
#define cosinusa(a, b, c) ((a * a + b * b - c * c) / (2.0 * a * b));
#define infi 1000000000
using namespace std;

vector<string> matrix;
int n, m;
double targX, targY;
double my_distance(const pair<double, double>& from, const pair<double, double>& target)
{
	return sqrt((from.first - target.first) * (from.first - target.first) + (from.second - target.second) * (from.second - target.second));
}

int isVisible(const pair<double, double>& from, const pair<double, double>& target)
{
	if (fabs(from.first - target.first) < epsilon && fabs(from.second - target.second) < epsilon)
		return fabs(from.first - targX) < epsilon && fabs(from.second - targY) < epsilon ? 0 : -1;
	pair<double, double> xPoint, yPoint;
	if (from.first > target.first + epsilon)
	{
		double x = floor(from.first - epsilon);
		double y = from.second + ((x - from.first) / (target.first - from.first)) * (target.second - from.second);
		xPoint = make_pair(x, y);
	} else if (from.first + epsilon < target.first)
	{
		double x = ceil(from.first + epsilon);
		double y = from.second + ((x - from.first) / (target.first - from.first)) * (target.second - from.second);
		xPoint = make_pair(x, y);
	}

	if (from.second > target.second + epsilon)
	{
		double y = floor(from.second - epsilon);
		double x = from.first + ((y - from.second) / (target.second - from.second)) * (target.first - from.first);
		yPoint = make_pair(x, y);
	} else if (from.second + epsilon < target.second)
	{
		double y = ceil(from.second + epsilon);
		double x = from.first + ((y - from.second) / (target.second - from.second)) * (target.first - from.first);
		yPoint = make_pair(x, y);
	}

	double distX = my_distance(from, xPoint);
	double distY = my_distance(from, yPoint);
	double dist3 = my_distance(from, target);
	if (dist3 < distX + epsilon && dist3 < distY + epsilon)
		return fabs(target.first - targX) < epsilon && fabs(target.second - targY) < epsilon ? 0 : -1;
	int tmp;
	if(fabs(from.first - target.first) < epsilon || distY + epsilon < distX)
	{
		int i = (yPoint.first < -epsilon) ? (int) (yPoint.first - epsilon) : (int)(yPoint.first + epsilon);
		int j = (yPoint.second < -epsilon) ? (int) (yPoint.second - epsilon) : (int)(yPoint.second + epsilon);
		if (matrix[i][j] == '#' || matrix[i][j - 1] == '#')
		{
			double x = target.first;
			double y = yPoint.second - (target.second - yPoint.second);
			tmp = isVisible(yPoint, make_pair(x, y));
			return tmp != -1 ? 1 + tmp : -1;
		}
		else
		{
			return isVisible(yPoint, target);
		}
		
	}

	if(fabs(from.second - target.second) < epsilon || distX + epsilon < distY)
	{
		int i = (xPoint.first < -epsilon) ? (int) (xPoint.first - epsilon) : (int)(xPoint.first + epsilon);
		int j = (xPoint.second < -epsilon) ? (int) (xPoint.second - epsilon) : (int)(xPoint.second + epsilon);
		if (matrix[i][j] == '#' || matrix[i - 1][j] == '#')
		{
			double y = target.second;
			double x = xPoint.first - (target.first - xPoint.first);
			tmp = isVisible(xPoint, make_pair(x, y));
			return tmp != -1 ? 1 + tmp : -1;
		}
		else
		{
			return isVisible(xPoint, target);
		}
	}
	int x = (xPoint.first < -epsilon) ? (int) (xPoint.first - epsilon) : (int)(xPoint.first + epsilon);
	int y = (xPoint.second < -epsilon) ? (int) (xPoint.second - epsilon) : (int)(xPoint.second + epsilon);
	int mat[4][2] = {{0, 0}, {-1, 0}, {0, -1}, {-1, -1}};
	int cnt = 0;
	for (int i = 0; i < 4; i++)
		cnt += matrix[x + mat[i][0]][y + mat[i][1]] == '#';
	if (cnt == 0 || (cnt == 2 && matrix[x][y] == matrix[x - 1][y - 1]))
		return isVisible(xPoint, target);
	if (cnt == 1)
		return -1;
	if (cnt == 3)
	{
		double x = 2 * xPoint.first - target.first;
		double y = 2 * xPoint.second - target.second;
		tmp = isVisible(xPoint, make_pair(x, y));
		return tmp != -1 ? 1 + tmp : -1;
	}
	// cnt == 2, two next to each other
	if (matrix[x][y] == matrix[x][y - 1])
	{
		double y = target.second;
		double x = xPoint.first - (target.first - yPoint.first);
		tmp = isVisible(xPoint, make_pair(x, y));
		return tmp != -1 ? 1 + tmp : -1;
	}
	else
	{
		double x = target.first;
		double y = yPoint.second - (target.second - yPoint.second);
		tmp = isVisible(yPoint, make_pair(x, y));
		return tmp != -1 ? 1 + tmp : -1;
	}
}

int main()
{
	freopen("google.in", "r", stdin);
	freopen("google.out", "w", stdout);
	int numTests;
	cin >> numTests;
	for(int testCounter = 0; testCounter < numTests; ++testCounter)
	{
		printf("Case #%d: ", testCounter + 1);
		matrix.clear();
		cin >> n >> m;
		int d;
		cin >> d;
		matrix.resize(n);

		for (int i = 0; i < n; i++)
		{
			cin >> matrix[i];
		}
		int x, y;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
			{
				if(matrix[i][j] == 'X')
				{
					matrix[i][j] = '.';
					x = i;
					y = j;
				}
			}
		targX = x + 0.5;
		targY = y + 0.5;
		int cnt = 0;
		vector<pair<int, int> > solutions;
		int tmp;
		for (int i = -51; i <= 51; i++)
		{
			for (int j = -51; j <= 51; j++)
			{
				if(i * i + j * j <= d * d)
				{
					tmp = isVisible(make_pair((double)x + 0.5, (double)y + 0.5), make_pair((double)x + i + 0.5, (double)y + j + 0.5));
					if(tmp > 0)
					{
						solutions.push_back(make_pair(i, j));
					}
				}
			}
		}
		for (int i = 0; i < solutions.size(); i++)
		{
			bool does = true;
			for (int j = 0; j < i; j++) 
			{
				if (solutions[i].first * solutions[j].second == solutions[i].second * solutions[j].first
					&& solutions[i].first * solutions[j].first >= 0
					&& solutions[i].second * solutions[j].second >= 0)
				{
					does = false;
					break;
				}
			}
			if(does)
				cnt++;
		}
		cout << cnt << endl;
	}
	return 0;
}
