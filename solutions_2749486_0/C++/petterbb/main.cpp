#include <cstdio>
#include <iostream>
#include <cstring>
#include <sstream>
#include <string>
#include <cmath>
#include <hash_set>
#include <queue>
using namespace std;
#define MAXN 1000000
bool vis[1000][1000];

struct Node{
	int x;
	int y;
	string ans;
	int steps;
	int dist;
};
bool operator < (Node s, Node t){
		return s.dist > t.dist;
}

int d[][3] = {{1,0, 'E'},{0,-1,'S'}, {0,1, 'N'}, {-1,0, 'W'}};

int main(){
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
	int t;
	cin >> t;
	for(int cases = 1; cases <= t; cases++){
        cout << "Case #" << cases << ": ";
		int dx, dy;
		cin >> dx >> dy;
		memset(vis, false, sizeof(vis));
		Node st;
		st.x = st.y = 0;
		st.steps = 1;
		st.ans="";
		st.dist=100;
		//priority_queue<Node> q;
		queue<Node> q;
		q.push(st);
		string res = "";
		while(!q.empty()){
			Node front = q.front();
			Node tmp;
			for(int i = 0; i < 4; i++){
				int x = d[i][0]*front.steps;
				int y = d[i][1]*front.steps;
				tmp.y = front.y + y;
				tmp.x = front.x + x;
				tmp.steps = front.steps + 1;
				char c = d[i][2];
				tmp.ans = front.ans + c;
				tmp.dist = abs(x-dx)+abs(y-dy);
				if(tmp.x == dx && tmp.y == dy){
					res = tmp.ans;
					break;
				}
				if(abs(tmp.x) > 100 || abs(tmp.y) > 100)
					continue;
				if(!vis[tmp.x+300][tmp.y+300]){
					vis[tmp.x+300][tmp.y+300]=true;
					q.push(tmp);
				}

			}

			q.pop();
		}
		cout << res << endl;
	}
	//system("pause");
	return 0;
}
