// GCJ 2011 Qual 1.cpp : main project file.

// Test.cpp : main project file.

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <math.h>
#include <map>
#include <set>

using namespace std;

/*
•"X won" (the game is over, and X won) 
•"O won" (the game is over, and O won) 
•"Draw" (the game is over, and it ended in a draw) 
•"Game has not completed" (the game is not over yet) 
*/
string doit(vector<string> rows) {
	for(int i=0;i<4;i++) cout<<rows[i]<<endl;
	vector<int> startX, startY, dirX, dirY;
	for(int i=0;i<4;i++) {
		startX.push_back(0);
		startY.push_back(i);
		dirX.push_back(1);
		dirY.push_back(0);

		startX.push_back(i);
		startY.push_back(0);
		dirX.push_back(0);
		dirY.push_back(1);
	}
	startX.push_back(0);
	startY.push_back(0);
	dirX.push_back(1);
	dirY.push_back(1);

	startX.push_back(0);
	startY.push_back(3);
	dirX.push_back(1);
	dirY.push_back(-1);

	for(int i=0;i<dirX.size();i++) {
		int countX=0,countO=0;
		for(int j=0;j<4;j++) {
			int x=startX[i]+dirX[i]*j;
			int y=startY[i]+dirY[i]*j;
			char c = rows[y][x];
			if(c=='X') countX++;
			else if(c=='O') countO++;
			else if(c=='T') { countX++; countO++; }
		}
		if(countX==4) return "X won";
		if(countO==4) return "O won";
	}
	bool draw=true;
	for(int i=0;i<4;i++) for(int j=0;j<4;j++) if(rows[i][j]=='.') draw=false;
	if(draw) return "Draw";
	return "Game has not completed";
}

int main()
{
	ifstream infile;
	string prefix = "A-small-attempt0";
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
		vector<string> rows;
		for(int j=0;j<4;j++) {
			string row;
			infile>>row;
			rows.push_back(row);
		}
		outfile << "Case #" << (i+1) << ": " << doit(rows) << endl; 
	}
	cout<<"DONE"<<endl;
	string zzz;
	cin>>zzz;
	outfile.close();
	return 0;
}