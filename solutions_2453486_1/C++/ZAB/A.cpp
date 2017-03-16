#include <stdio.h>
#include <functional>
#include <bitset>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <sstream>
#include <queue>
#include <bitset>
#include <string.h>
using namespace std;

char field[4][4];

void readCase()
{
	scanf("%s\n", &field[0]);
	scanf("%s\n", &field[1]);
	scanf("%s\n", &field[2]);
	scanf("%s\n", &field[3]);
}

void solve()
{
	int filled = 0;
	for(int x = 0; x < 4; x++)
		for(int y = 0; y < 4; y++) {
			if(field[x][y] != '.') filled++;
		}
	
	bool Ywon = false;

	for(int x = 0; x < 4; x++) {
		bool won = true;
		for(int y = 0; y < 4; y++) {
			if(field[x][y] != 'X' && field[x][y] != 'T') won = false;
		}
		if(won) {
			printf("X won");
			return;
		}
	}

	for(int y = 0; y < 4; y++) {
		bool won = true;
		for(int x = 0; x < 4; x++) {
			if(field[x][y] != 'X' && field[x][y] != 'T') won = false;
		}
		if(won) {
			printf("X won");
			return;
		}
	}

	for(int x = 0; x < 4; x++) {
		bool won = true;
		for(int y = 0; y < 4; y++) {
			if(field[x][y] != 'O' && field[x][y] != 'T') won = false;
		}
		if(won) {
			printf("O won");
			return;
		}
	}

	for(int y = 0; y < 4; y++) {
		bool won = true;
		for(int x = 0; x < 4; x++) {
			if(field[x][y] != 'O' && field[x][y] != 'T') won = false;
		}
		if(won) {
			printf("O won");
			return;
		}
	}

	{
		bool won = true;
		for(int y = 0; y < 4; y++) {
			int x = y;
			if(field[x][y] != 'X' && field[x][y] != 'T') won = false;
		}
		if(won) {
			printf("X won");
			return;
		}
	}

	{
		bool won = true;
		for(int y = 0; y < 4; y++) {
			int x = 3 - y;
			if(field[x][y] != 'X' && field[x][y] != 'T') won = false;
		}
		if(won) {
			printf("X won");
			return;
		}
	}

	{
		bool won = true;
		for(int y = 0; y < 4; y++) {
			int x = y;
			if(field[x][y] != 'O' && field[x][y] != 'T') won = false;
		}
		if(won) {
			printf("O won");
			return;
		}
	}

	{
		bool won = true;
		for(int y = 0; y < 4; y++) {
			int x = 3 - y;
			if(field[x][y] != 'O' && field[x][y] != 'T') won = false;
		}
		if(won) {
			printf("O won");
			return;
		}
	}

	if(filled == 16) {
		printf("Draw");
		return;
	}

	printf("Game has not completed");
}

int main()
{
	//string fname = "./test/A-example.in";
	//string fname = "./test/A-small-attempt0.in";
	string fname = "./test/A-large.in";
	
	freopen(fname.c_str(),"r",stdin);freopen((fname+".out").c_str(),"w",stdout);

	int analizeCase = -1;
	
	int T;
	scanf("%d", &T);
	for(int tCase = 1; tCase <= T; tCase++) {
		printf("Case #%d: ", tCase);
		readCase();
		if(analizeCase < 0 || analizeCase == tCase) solve();
		printf("\n");
		fflush(stdout);
		fprintf(stderr, "Done %d %%     \r", 100 * tCase / T );
	}
	return 0;
}

