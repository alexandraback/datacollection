#include <stdio.h>
#include <iostream>
#include <memory.h>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>
#include <map>
#include <set>
#include <queue>
using namespace std;
map<pair<int,int>,int>M;
map<pair<int,int>,int>D;
struct Node{
	int x,y,d;
	Node(int _x,int _y,int _d){
		x=_x;y=_y;d=_d;
	}
};
queue<Node>Q;
int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
char ink[4] = {'E','W','N','S'};
int main(){
	int T,cas=0;
	freopen("B-small-attempt0.in","r",stdin);
	freopen("B-small-attempt0.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		int X,Y;
		scanf("%d%d",&X,&Y);
		M.clear();
		D.clear();
		while(Q.empty() != true) Q.pop();
		Q.push(Node(0,0,0));
		while(Q.empty() !=true) {
			Node cur = Q.front();
			Q.pop();
			int d = cur.d+1,x = cur.x,y = cur.y;
			if(x == X && y == Y) {
				break;
			}
			for(int i = 0;i < 4;i++) {
				int dx = x + dir[i][0] * d,dy = y + dir[i][1] * d;
				if(M.find(make_pair(dx,dy)) == M.end()) {
					M[make_pair(dx,dy)] = d;
					D[make_pair(dx,dy)] = i;//dir
					Q.push(Node(dx,dy,d));
				}
			}
		}
		string path = "";
		int curx = X,cury = Y;
		while(1) {
			if(curx == 0 && cury == 0) break;
			int go = D[make_pair(curx,cury)];
			int d = M[make_pair(curx,cury)];
			int tmpx,tmpy;
			tmpx = curx + (-d) * dir[go][0];
			tmpy = cury + (-d) * dir[go][1];
			curx = tmpx;cury = tmpy;
			path += ink[go];
		}
		string ans = "";
		for(int i = path.length()-1;i>=0;i--)ans+=path[i];
		cout<<"Case #"<<++cas<<": "<<ans<<endl;
	}
	return 0;
}