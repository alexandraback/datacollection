#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <math.h>
#include <map>
#include <set>
#include <algorithm>
#include <queue>

using namespace std;

int mem[301][301][100];
int dir[301][301][100];
int offset=100;

string doit(int x,int y) {
	queue<pair<pair<int, int>,int> > q;
	q.push(make_pair(make_pair(offset,offset),1));
	memset(mem,-1,sizeof(mem));
	mem[offset][offset][1]=1;
	int dy[4]={1,-1,0,0};
	int dx[4]={0,0,-1,1};
	string directions="NSWE";
	cout<<"<<<<<<<<<<<<<"<<endl;
	while(q.size()) {
		int curY=q.front().first.first;
		int curX=q.front().first.second;
		int move=q.front().second;
		//cout<<curY<<" "<<curX<<" "<<move<<endl;
		q.pop();
		if(curY-offset==y&&curX-offset==x) {
			string ret="";
			while(move!=1) {
				int d=dir[curY][curX][move];
				ret=directions[d]+ret;
				//cout<<y<<" "<<x<<" "<<curY<<" "<<curX<<" "<<move<<" "<<d<<endl;
				int newY=curY-dy[d]*(move-1);
				int newX=curX-dx[d]*(move-1);
				curY=newY;
				curX=newX;
				move--;
			}
			//cout<<ret<<endl;
			int xx=0,yy=0;
			for(int i=0;i<ret.size();i++) {
				if(ret[i]=='N') {
					yy+=i+1;
				}
				if(ret[i]=='S') {
					yy-=i+1;
				}
				if(ret[i]=='E') {
					xx+=i+1;
				}
				if(ret[i]=='W') {
					xx-=i+1;
				}
			}
			cout<<xx<<" "<<yy<<endl;
			if(xx!=x||yy!=y) cout<<"BAD "<<x<<" "<<y<<endl;
			return ret;
		}
		for(int d=0;d<4;d++) {
			int newY=curY+dy[d]*move;
			int newX=curX+dx[d]*move;
			if(newY>300||newY<0||newX>300||newX<0) continue;
			if(mem[newY][newX][move+1]!=-1) continue;
			mem[newY][newX][move+1]=move+1;
			dir[newY][newX][move+1]=d;
			q.push(make_pair(make_pair(newY,newX),move+1));
			//cout<<newY<<" "<<newX<<" "<<(move+1)<<endl;
		}
	}
	return "";
}

int main()
{
	ifstream infile;
	string prefix = "B-small-attempt1";
	//string prefix = "test";
	infile.open(prefix + ".in");
	ofstream outfile(prefix + ".out");
	int cases;
	if (infile.is_open()) {
		infile>>cases;
	}
	else {
		return 0;
	}
	for(int i=0;i<cases;i++) {
		int x,y;
		infile>>x>>y;
		cout<<x<<" "<<y<<"****"<<endl;
		outfile << "Case #" << (i+1) << ": " << doit(x,y) << endl; 
	}
	cout<<"DONE"<<endl;
	string zzz;
	cin>>zzz;
	outfile.close();
	return 0;
}