#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>

using namespace std;
int dx[4] = {-1,0,1,0};
int dy[4] = {0,-1,0,1};
char dir[4] = {'W', 'S', 'E', 'N'};

int main()
{
    int T,X,Y;
    cin >> T;
    for (int c=1; c<=T; c++) {
	cin >> X >> Y;
	queue<pair<pair<int,int>,int> > q;
	map<pair<pair<int,int>,int>, char> parent;
	q.push(make_pair(make_pair(0,0),1));
	int x,y,d;
	while (!q.empty()) {
	    pair<pair<int,int>,int> t = q.front(); q.pop();
	    x = t.first.first;
	    y = t.first.second;
	    d = t.second;
	    if (x == X && y == Y) {
		break;
	    } else {
		for (int i=0; i<4; i++) {
		    int a = x+dx[i]*d;
		    int b = y+dy[i]*d;
		    if (parent.count(make_pair(make_pair(a,b),d+1)) == 0) {
			//cout << "push " << a << " " << b << " " << d+1 << endl;
			q.push(make_pair(make_pair(a,b),d+1));
			parent[make_pair(make_pair(a,b),d+1)] = i;
		    }
		}
	    }
	}

	vector<char> path;
	while (d>1) {
	    char t = parent[make_pair(make_pair(x,y),d)];
	    path.push_back(dir[t]);
	    d--;
	    x = x - dx[t]*d;
	    y = y - dy[t]*d;
	}
	cout << "Case #" << c << ": ";
	for (int i=path.size()-1; i>= 0; i--) cout << path[i];
	cout << endl;
    }
    return 0;
}
