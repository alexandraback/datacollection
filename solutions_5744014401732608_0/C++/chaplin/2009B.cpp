//============================================================================
// Name        : 2009B.cpp
// Author      : Javier Sardinas
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <cstdio>
using namespace std;

int h,w,m[100][100];

pair<int, int> neighbor(pair<int, int> p){
	int x = p.first, y = p.second;
	int a=0,b=0;
	//test N
	if (x-1>=0 && m[x-1][y] < m[x][y])
		a=-1, b=0;
	//test W
	if (y-1>=0 && m[x][y-1] < m[x][y] && m[x][y-1] < m[x+a][y+b])
		a=0, b=1;
	//test E
	if (y+1<w && m[x][y+1] < m[x][y] && m[x][y+1] < m[x+a][y+b])
		a=0,b=1;
	//test S
	if (x+1<h && m[x+1][y] < m[x][y] && m[x+1][y] < m[x+a][y+b])
		a=1, b=0;
	return std::make_pair(a,b);
}

int main() {
	int t,mark[100][100];

	scanf("%d", &t);
	for(int c = 1; c <= t; ++c){
		scanf("%d%d", &h, &w);
		for(int i = 0; i < h; ++i)
			for(int j = 0; j < w; ++j)
				scanf("%d", &m[i][j]);
		int next = 1;
		mark[0][0] = 0;
		for(int i = 0; i < h; ++i)
			for(int j = 0; j < w; ++j){
				pair<int, int> p = neighbor(std::make_pair(i,j));
				int a = p.first, b = p.second;
				if(!a && !b)
					mark[i][j] = next++;
				else if (a < 0 || b < 0)
					mark[i][j] = mark[i+a][j+b];
				else
					mark[i+a][j+b] = mark[i][j];
			}
		printf("Case #%d:", c);
		for(int i = 0; i < h; ++i){
			printf("%c", mark[i][0]+'a');
			for(int j = 1; j < w; ++j)
				printf(" %c", mark[i][j]+'a');
			printf("\n");
		}


	}

	return 0;
}
