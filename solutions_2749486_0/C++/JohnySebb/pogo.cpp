/*
 * =====================================================================================
 *
 *       Filename:  pogo.cpp
 *
 *    Description:  Pogo stick
 *
 *        Version:  1.0
 *        Created:  05/12/2013 11:10:21 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Jan Sebechlebsky (), sebecjan@fit.cvut.cz
 *   Organization:  FIT CTU
 *
 * =====================================================================================
 */

#include <cstdio>
#include <cstdlib>
#include <queue>
#include <map>
#include <stack>

using namespace std;

struct Node {
	int x, y, dist;
	Node( int x  = 0, int y = 0 ){
		this->x = x;
		this->y = y;
		this->dist = 0;
	}
	bool operator < ( const struct Node & n )const {
		if(x == n.x)
			return n.y < y;
		return n.x < x;
	}
	bool operator == ( const struct Node & n )const{
		return (x==n.x)&&(y==n.y);
	}
};

int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
char d[4] = {'N','E','S','W'};

void solve( int x, int y ) {	
	queue<Node> q;
	map<Node,Node> m;
	q.push(Node(0,0));
	while(!q.empty()){
		Node n;
		n = q.front(); q.pop();
		//printf("\n x = %d, y = %d\n",n.x,n.y);
		bool found = false;
		for( int i = 0; i < 4; i++ ){
			Node tmp = n;
			tmp.dist++;
			tmp.x+=(dir[i][0]*tmp.dist);
			tmp.y+=(dir[i][1]*tmp.dist);
			if( m.find(tmp) != m.end() )continue;
			m.insert( pair<Node,Node>(tmp,n));
			q.push(tmp);
			if((tmp.x==x)&&(tmp.y==y)){
				found = true;
				break;
			}
		}
		if(found)break;
	}
	stack<char> s;
	while(1){
		map<Node,Node>::iterator it = m.find(Node(x,y));
		int nx = it->second.x;
		int ny = it->second.y;
		if(nx==x){
			s.push(ny>y?'S':'N');
		} else {
			s.push(nx>x?'W':'E');
		}
		if((nx==0)&&(ny==0))break;
		x = nx;
		y = ny;	
	}
	while(!s.empty()){
		putchar(s.top());
		s.pop();
	}
	putchar('\n');
} 

int main( int argc, char ** argv ) {
	int n,x,y;
	scanf("%d",&n);
	for( int c = 1; c <= n; c++ ){
		scanf("%d%d",&x,&y);
		printf("Case #%d: ",c);
		solve(x,y);
	}
	return 0;
}
