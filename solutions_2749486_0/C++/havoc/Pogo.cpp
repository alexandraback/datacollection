#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
#include<iomanip>
#include<map>
#include<stdio.h>
#include<vector>
#include<string.h>
#include<set>
#include<stack>
#include<queue>
#include<sstream>
#include<fstream>
using namespace std;
struct pogoNode 
{
	int numberOfMoves;
	int currentStrength;
	string movesSoFar;
	int x,y;
	pogoNode(int nm,int cs,string msf,int xx,int yy)
	{
		numberOfMoves=nm;
		currentStrength=cs;
		movesSoFar = msf;
		x=xx;
		y=yy;
	}
};
bool operator<(const pogoNode& first, const pogoNode& second)
{
	return first.numberOfMoves>second.numberOfMoves;
}

string bfs(int x2,int y2)
{
	map<pair<pair<int,int>,int>,bool> visited;
	queue<pogoNode> pQ;
	pQ.push(pogoNode(0,1,"",0,0));
	while(!pQ.empty())
	{
		pogoNode top = pQ.front();
		pQ.pop();
		if(top.x==x2&&top.y==y2)
			return top.movesSoFar;
		pair<pair<int,int>,int> pp = make_pair(make_pair(top.x,top.y),top.currentStrength);
		if(visited[pp])
			continue;
		visited[pp]=true;
		pQ.push(pogoNode(top.numberOfMoves+1,top.currentStrength+1,top.movesSoFar+'N',top.x,top.y+top.currentStrength));
		pQ.push(pogoNode(top.numberOfMoves+1,top.currentStrength+1,top.movesSoFar+'S',top.x,top.y-top.currentStrength));
		pQ.push(pogoNode(top.numberOfMoves+1,top.currentStrength+1,top.movesSoFar+'E',top.x+top.currentStrength,top.y));
		pQ.push(pogoNode(top.numberOfMoves+1,top.currentStrength+1,top.movesSoFar+'W',top.x-top.currentStrength,top.y));
	}
	return "";
}
int main()
{
	ifstream cin("B-small-attempt1.in");
	ofstream cout("B-small.out");
	int T;
	cin>>T;
	for (int i = 0; i < T ; i++)
	{
		
		int x,y;
		cin>>x>>y;
		cout<<"Case #"<<i+1<<": "<<bfs(x,y)<<endl;
	}
	return 0;
}