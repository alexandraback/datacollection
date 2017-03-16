#define _USE_MATH_DEFINES
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <memory.h>

using namespace std;

#define ll long long
#define ld long double
#define pii pair<int, int>

int x,o,t;

void add(char c)
{
	if(c=='X') ++x;
	if(c=='O') ++o;
	if(c=='T') ++t;
}

int main()
{
	int T;
	cin >> T;
	char map[5][5];
	for(int step=1; step<=T; ++step)
	{                                   
		cin >> map[0] >> map[1] >> map[2] >> map[3];

		bool full=true;
		for(int i=0; i<4; ++i)
			for(int j=0; j<4; ++j)
				if(map[i][j]=='.') full=false;
		int ans=0;
		if(!full) ans=3;
		for(int i=0; i<4; ++i)
		{
			x=0,t=0,o=0;
			for(int j=0; j<4; ++j)
				add(map[i][j]);
			if(x+t==4)
				ans=1;
			if(o+t==4)
				ans=2;
		}
		for(int j=0; j<4; ++j)
		{
			x=0,t=0,o=0;
			for(int i=0; i<4; ++i)
				add(map[i][j]);
			if(x+t==4)
				ans=1;
			if(o+t==4)
				ans=2;
		}
		x=0,t=0,o=0;
		for(int i=0; i<4; ++i)
			add(map[i][i]);
		if(x+t==4)
			ans=1;
		if(o+t==4)
			ans=2;
		x=0,t=0,o=0;
		for(int i=0; i<4; ++i)
			add(map[i][4-i-1]);
		if(x+t==4)
			ans=1;
		if(o+t==4)
			ans=2;
		cout << "Case #"<<step<<": ";
		if(ans==0)
			cout << "Draw";
		if(ans==1)
			cout << "X won";
		if(ans==2)
			cout << "O won";
		if(ans==3)
			cout << "Game has not completed";
		cout << endl;
	}	
}
