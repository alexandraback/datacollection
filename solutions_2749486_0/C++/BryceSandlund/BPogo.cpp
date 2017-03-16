//============================================================================
// Name        : BPogo.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <list>
using namespace std;

int C = 300;

int nVisited = 0;
vector<vector<int> > visited(C * 2 + 1, vector<int>(C * 2 + 1, 501));

vector<vector<vector<int> > > dp(C * 2 + 1, vector<vector<int> >(C * 2 + 1, vector<int>(501, 501)));

pair<int, int> directions[4] = {make_pair(0, 1), make_pair(1, 0), make_pair(0, -1), make_pair(-1, 0)};
char d[4] = {'N', 'E', 'S', 'W'};

vector<vector<list<char> > > pathG(C * 2 + 1, vector<list<char> >(C * 2 + 1));

void visit(int total, int cur, int x, int y, list<char> &path)
{
	if (!(x > C || y > C || x < -1 * C || y < -1 * C))
	{
		if (dp[x + C][y + C][cur] <= total)
		{
			return;
		}
		dp[x + C][y + C][cur] = total;
	}

	if (cur == 0)
	{
		if (x > 100 || y > 100 || x < -100 || y < -100)
			return;

		//cout << x << ", " << y << endl;
		if (total < visited[x + C][y + C])
		{
			++nVisited;
			visited[x + C][y + C] = total;
			pathG[x + C][y + C] = path;
		}
	}
	else
	{
		for (int i = 0; i < 4; ++i)
		{
			list<char> newL(path);
			newL.push_front(d[i]);
			visit(total, cur - 1, directions[i].first * cur + x, directions[i].second * cur + y, newL);
		}
	}
}

string convert(list<char> path)
{
	list<char>::iterator iter = path.begin();
	string str = "";
	while (iter != path.end())
	{
		str += *iter;
		++iter;
	}
	return str;
}

int main() {
	int i = 0;
	while (nVisited < 40401)
	//while (nVisited < 1000)
	{
		cout << i << endl;
		cout << nVisited << endl;
		list<char> blah;
		visit(i, i, 0, 0, blah);
		++i;
	}
	cout << "here";

	int T;
	cin >> T;
	for (int caseNum = 1; caseNum <= T; ++caseNum)
	{
		int X, Y;
		cin >> X >> Y;

		cout << "Case #" << caseNum << ": " << convert(pathG[X + C][Y + C]) << endl;
	}
	return 0;
}
