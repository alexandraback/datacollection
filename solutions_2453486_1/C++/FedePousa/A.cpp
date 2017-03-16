#define Federico using
#define Javier namespace
#define Pousa std;
#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <vector>
#include <map>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <stack>
#include <queue>
#include <cstring>
#include <sstream>


Federico Javier Pousa

int main(){
	int T, tot;
	string board[4];
	cin >> T;
	for(int caso=1;caso<=T;++caso){
		cout << "Case #" << caso << ": ";
		for(int i=0;i<4;++i)cin >> board[i];
		bool fin = false;
		
		for(int i=0;!fin&&i<4;++i){
			tot = 0;
			for(int j=0;j<4;++j)tot += (board[i][j]=='X'||board[i][j]=='T')?1:0;
			if(tot==4)fin=true;
		}
		
		for(int i=0;!fin&&i<4;++i){
			tot = 0;
			for(int j=0;j<4;++j)tot += (board[j][i]=='X'||board[j][i]=='T')?1:0;
			if(tot==4)fin=true;
		}
		
		tot = 0;
		for(int i=0;i<4;++i){
			tot += (board[i][i]=='X'||board[i][i]=='T')?1:0;
		}
		if(tot==4)fin=true;
		
		tot = 0;
		for(int i=0;i<4;++i){
			tot += (board[i][3-i]=='X'||board[i][3-i]=='T')?1:0;
		}
		if(tot==4)fin=true;
		
		if(fin){
			cout << "X won" << endl;
			continue;
		}
		
		
		for(int i=0;!fin&&i<4;++i){
			tot = 0;
			for(int j=0;j<4;++j)tot += (board[i][j]=='O'||board[i][j]=='T')?1:0;
			if(tot==4)fin=true;
		}
		
		for(int i=0;!fin&&i<4;++i){
			tot = 0;
			for(int j=0;j<4;++j)tot += (board[j][i]=='O'||board[j][i]=='T')?1:0;
			if(tot==4)fin=true;
		}
		
		tot = 0;
		for(int i=0;i<4;++i){
			tot += (board[i][i]=='O'||board[i][i]=='T')?1:0;
		}
		if(tot==4)fin=true;
		
		tot = 0;
		for(int i=0;i<4;++i){
			tot += (board[i][3-i]=='O'||board[i][3-i]=='T')?1:0;
		}
		if(tot==4)fin=true;
		
		
		if(fin){
			cout << "O won" << endl;
			continue;
		}
		
		
		bool com = true;
		for(int i=0;i<4;++i){
			for(int j=0;j<4;++j){
				if(board[i][j]=='.'){
					com = false;
				}
			}
		}
		if(com){
			cout << "Draw" << endl;
		}else{
			cout << "Game has not completed" << endl;
		}
	}
	return 0;
}
