/*Santiago Zubieta*/
#include <iostream>
#include <numeric>
#include <fstream>
#include <climits>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <queue>
#include <list>
#include <map>
#include <set>
#include <stack>
#include <deque>
#include <vector>
#include <string>
#include <cstdlib>
#include <cassert>
#include <sstream>
#include <iterator>
#include <algorithm>  

using namespace std;

bool control; 

bool won(int count){
	return count == 4;
}

void winner(char who, int ncase){
	control = true;
	printf("Case #%d: %c won\n",ncase, who);
}

void nocomplete(int ncase){
	printf("Case #%d: Game has not completed\n",ncase);
}

void draw(int ncase){
	printf("Case #%d: Draw\n",ncase);
}

int main(){
	char tictac[4][4];
	int nCases;
	bool left;
	char l;
	int countX1, countX2;
	int countO1, countO2;
	cin >> nCases;
	for(int i = 1; i <= nCases; ++i){
		getchar();
		left = false;
		control = false;
		for(int j = 0; j < 4; ++j){
			for (int k = 0; k < 4; ++k){
				tictac[j][k] = getchar();
				if(tictac[j][k] == '.'){
					left = true;
				}
			}
			getchar();
		}
		for(int j = 0; j < 4; ++j){
			countX1 = countX2 = 0;
			countO1 = countO2 = 0;
			for(int k = 0; k < 4; ++k){
				if(tictac[j][k] == 'X' || tictac[j][k] == 'T'){
					countX1++;
				}
				if(tictac[j][k] == 'O' || tictac[j][k] == 'T'){
					countO1++;
				}
				if(tictac[k][j] == 'X' || tictac[k][j] == 'T'){
					countX2++;
				}
				if(tictac[k][j] == 'O' || tictac[k][j] == 'T'){
					countO2++;
				}
			}
			if(won(countX1) || won(countX2)){
				winner('X', i);
			}
			if(won(countO1) || won(countO2)){
				winner('O', i);
			}
		}
		countX1 = countX2 = 0;
		countO1 = countO2 = 0;
		for(int j = 0; j < 4; ++j){
			int k = 4 - j - 1;
			if(tictac[j][j] == 'X' || tictac[j][j] == 'T'){
				countX1++;
			}
			if(tictac[j][j] == 'O' || tictac[j][j] == 'T'){
				countO1++;
			}
			if(tictac[k][j] == 'X' || tictac[k][j] == 'T'){
				countX2++;
			}
			if(tictac[k][j] == 'O' || tictac[k][j] == 'T'){
				countO2++;
			}
			if(won(countX1) || won(countX2)){
				winner('X', i);
			}
			if(won(countO1) || won(countO2)){
				winner('O', i);
			}
		}
		if(control == false){
			if(left) nocomplete(i);
			else draw(i);
		}
	}
}