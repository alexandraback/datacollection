#include <iostream>
#include <cmath>
#include <vector>
#include <sstream>
#include <string>
#include <cstring>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>

using namespace std;

struct Node{
	int X;
	int Y;
	char prev;
	string path;

	Node(int _x, int _y, char _prev, string _path)
	{
		X = _x;
		Y = _y;
		prev = _prev;
		path = _path;
	}
};

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w+", stdout);

	int N;
	cin >> N;

	for(int T = 0; T < N; ++T)
	{
		int X, Y;
		cin >> X >> Y;
		int currX = 0, currY = 0;
		Node nn(currX, currY, 0, "");
		queue<Node> q;
		q.push(nn);
		map<pair<int, int>, bool > m;
		while(!q.empty())
		{
			Node n = q.front(); q.pop();

			if(m[make_pair(n.X, n.Y)])
				continue;
			m[make_pair(n.X, n.Y)] = 1;

			if(n.X == X && n.Y == Y)
			{
				cout << "Case #" << (T+1) << ": " << n.path << endl;
				break;
			}

			int f = (int)n.path.size() + 1;

			string path =  n.path + "N";
			q.push(Node(n.X, n.Y+f, 'N', path));
		
			path =  n.path + "S";
			q.push(Node(n.X, n.Y-f, 'S', path));
			
			path =  n.path + "E";
			q.push(Node(n.X+f, n.Y, 'E', path));
		
			path =  n.path + "W";
			q.push(Node(n.X-f, n.Y, 'W', path));

		}
	}


	return 0;
}