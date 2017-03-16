#include<cstdio>
#include<queue>
#include<string>
#include<iostream>
#include<cmath>
#define MAX 100

using namespace std;

string p[201][201];

struct BFS{
	int x, y;
	int cnt;
	string path;
	BFS(int x,int y,int cnt,string path){
		this->x = x;
		this->y= y;
		this->cnt = cnt;
		this->path = path;
	}
};

void process(){
	queue<BFS> q;
	q.push(BFS(0,0,0,""));

	while(q.size()){
		BFS now = q.front(); q.pop();
		if(abs(now.x) > MAX || abs(now.y) > MAX)	continue;
		if(p[now.x + 100][now.y+100] != "")	continue;
		p[now.x+100][now.y+100] = now.path;
		q.push( BFS(now.x + now.cnt + 1,now.y,now.cnt+1, now.path + "E"));
		q.push( BFS(now.x - 1 - now.cnt,now.y,now.cnt+1, now.path + "W"));
		q.push( BFS(now.x,now.y + 1 + now.cnt,now.cnt+1, now.path + "N"));
		q.push( BFS(now.x,now.y - 1 - now.cnt,now.cnt+1, now.path + "S"));
	}

	int t;
	int X, Y;
	scanf("%d",&t);
	for(int i=0;i<t;i++){
		scanf("%d %d",&X,&Y);
		cout << "Case #" << i+1 << ": " << p[X+100][Y+100] << endl;
	}
}
int main(){
	process();
	return 0;

}