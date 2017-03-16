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
	int T, N, M, board[105][105], board2[105][105], maxi;
	cin >> T;
	for(int caso=1;caso<=T;++caso){
		cout << "Case #" << caso << ": ";
		cin >> N >> M;
		for(int i=0;i<N;++i){
			for(int j=0;j<M;++j){
				cin >> board[i][j];
				board2[i][j] = 100;
			}
		}
		
		for(int i=0;i<N;++i){
			maxi = -1;
			for(int j=0;j<M;++j)maxi = max(maxi,board[i][j]);
			for(int j=0;j<M;++j){
				board2[i][j] = min(board2[i][j], maxi);
			}
		}
		
		for(int j=0;j<M;++j){
			maxi = -1;
			for(int i=0;i<N;++i)maxi = max(maxi,board[i][j]);
			for(int i=0;i<N;++i){
				board2[i][j] = min(board2[i][j], maxi);
			}
		}
		
		bool dis = false;
		
		for(int i=0;i<N;++i){
			for(int j=0;j<M;++j){
				if(board[i][j]!=board2[i][j])dis=true;
			}
		}
		
		if(dis){
			cout << "NO" << endl;
		}else{
			cout << "YES" << endl;
		}
	}
	return 0;
}
