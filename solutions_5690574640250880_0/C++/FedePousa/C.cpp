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

int di[8] = {-1,-1,-1,0,1,1,1,0};
int dj[8] = {-1,0,1,1,1,0,-1,-1};

typedef pair<int,int> pii;

int main(){
	int T, R, C, M, board[10][10],used[10][10];
	cin >> T;
	for(int caso=1;caso<=T;caso++){
		cin >> R >> C >> M;
		vector<int> vec;
		for(int i=0;i<R*C-M;i++){
			vec.push_back(0);
		}
		for(int i=0;i<M;i++){
			vec.push_back(1);
		}
		
		bool encontre=false;
		do{
			for(int i=0;i<R;i++){
				for(int j=0;j<C;j++){
					board[i][j] = vec[i*C+j];
				}
			}
			int ip=-1,jp,act;
			for(int i=0;i<R;i++){
				for(int j=0;j<C;j++){
					if(board[i][j])continue;
					act = 0;
					for(int k=0;k<8;k++){
						if(i+di[k]>=0&&i+di[k]<R&&j+dj[k]>=0&&j+dj[k]<C)act += board[i+di[k]][j+dj[k]];
					}
					if(!act){
						ip = i;
						jp = j;
					}
				}
			}
			if(ip==-1)continue;
			
			pii actual = pii(ip,jp);
			int proc = 0, iact, jact;
			queue<pii> cola;
			cola.push(actual);
			memset(used, 0, sizeof used);
			used[ip][jp] = 1;
			while(!cola.empty()){
				actual = cola.front();
				//~ cerr << actual.first << " " << actual.second << endl;
				cola.pop();
				proc++;
				act = 0;
				iact = actual.first;
				jact = actual.second;
				for(int k=0;k<8;k++){
					if(iact+di[k]>=0&&iact+di[k]<R&&jact+dj[k]>=0&&jact+dj[k]<C)act += board[iact+di[k]][jact+dj[k]];
				}
				if(act)continue;
				for(int k=0;k<8;k++){
					if(iact+di[k]>=0&&iact+di[k]<R&&jact+dj[k]>=0&&jact+dj[k]<C){
						if(used[iact+di[k]][jact+dj[k]])continue;
						if(board[iact+di[k]][jact+dj[k]])continue;
						cola.push(pii(iact+di[k],jact+dj[k]));
						used[iact+di[k]][jact+dj[k]] = 1;
					}
				}
			}
			//~ cerr << "Proc " << proc << endl;
			if(proc==R*C-M){
				encontre = true;
				board[ip][jp] = 2;
			}
		}while(!encontre&&next_permutation(vec.begin(),vec.end()));
		
		if(!encontre&&M==R*C-1){
			for(int i=0;i<R;i++){
				for(int j=0;j<C;j++){
					board[i][j] = 1;
				}
			}
			board[0][0] = 2;
			encontre = true;
		}
		
		cout << "Case #" << caso << ":" << endl;
		if(!encontre){
			cout << "Impossible" << endl;
		}else{
			for(int i=0;i<R;i++){
				for(int j=0;j<C;j++){
					if(board[i][j]==0){
						cout << ".";
					}
					if(board[i][j]==1){
						cout << "*";
					}
					if(board[i][j]==2){
						cout << "c";
					}
				}
				cout << endl;
			}
		}
	}
	return 0;
}
