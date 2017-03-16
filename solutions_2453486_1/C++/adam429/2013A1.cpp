#include <cstring>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
#include <vector>
#include <sstream>

#define MAX(x,y) ((x)>(y)?(x):(y))
#define MIN(x,y) ((x)<(y)?(x):(y))

using namespace std;		

char map[4][4];

void check(int i)
{
	bool has_empty=false;
	
	// check row
	for (int y=0;y<4;y++)
	{
		bool is_same=true;
		char color='.';
		
		for (int x=0;x<4;x++)
		{
			if (map[x][y]=='.') {
				has_empty=true;
				is_same=false;
				break;
			}
			
			if (map[x][y]=='T') continue;
			
			// X or O
			if (color=='.') 
			{
				color=map[x][y];
			} else {
				if (color!=map[x][y]) 
					{
						is_same=false;
						break;
					}
			}
		}
		if (is_same) {
			cout << "Case #"<< i << ": " << color << " won" << endl;
			return;
		}
	}


	// check column
	for (int x=0;x<4;x++)
	{
		bool is_same=true;
		char color='.';
		
		for (int y=0;y<4;y++)
		{
			if (map[x][y]=='.') {
				has_empty=true;
				is_same=false;
				break;
			}
			
			if (map[x][y]=='T') continue;
			
			// X or O
			if (color=='.') 
			{
				color=map[x][y];
			} else {
				if (color!=map[x][y]) 
					{
						is_same=false;
						break;
					}
			}
		}
		if (is_same) {
			cout << "Case #"<< i << ": " << color << " won" << endl;
			return;
		}
	}	

	// check cross
		bool is_same=true;
		char color='.';
		
		for (int y=0;y<4;y++)
		{
			int x=y;
			if (map[x][y]=='.') {
				has_empty=true;
				is_same=false;
				break;
			}
			
			if (map[x][y]=='T') continue;
			
			// X or O
			if (color=='.') 
			{
				color=map[x][y];
			} else {
				if (color!=map[x][y]) 
					{
						is_same=false;
						break;
					}
			}
		}
		if (is_same) {
			cout << "Case #"<< i << ": " << color << " won" << endl;
			return;
		}
		
		is_same=true;
		color='.';
		
		for (int y=0;y<4;y++)
		{
			int x=3-y;
			if (map[x][y]=='.') {
				has_empty=true;
				is_same=false;
				break;
			}
			
			if (map[x][y]=='T') continue;
			
			// X or O
			if (color=='.') 
			{
				color=map[x][y];
			} else {
				if (color!=map[x][y]) 
					{
						is_same=false;
						break;
					}
			}
		}
		if (is_same) {
			cout << "Case #"<< i << ": " << color << " won" << endl;
			return;
		}
		
		if (has_empty) {
			cout << "Case #"<< i << ": Game has not completed" << endl;
			
		} else {
			cout << "Case #"<< i << ": Draw" << endl;
			
		}
}

int main() 
{
	int n;
	
	cin >> n;
	
	for (int i=1;i<=n;i++) {
		memset(map,'.',sizeof(map));
		for (int y=0;y<4;y++)
			for (int x=0;x<4;x++)
			{
				char ch;
				cin >> ch;
				map[x][y]=ch;
			}
		
		check(i);
	}

/*	
	print out
	
	for (int y=0;y<4;y++) {
		for (int x=0;x<4;x++)
		{
			cout << map[x][y];
			}
			cout << endl;
			}
*/
}
