#include <iostream>
#include <vector>
#include <string>

#define FOR(i,n) for(int i = 0, _n = (n); i < _n; i++)


using namespace std;

vector<string> construct(int R, int C, int M){
	vector<string> null;
	vector<string> mine(R, string(C,'*'));
	
	if(R*C-M == 1){
		mine[0][0] = 'c';
		return mine;
	}
	
	if(R<C){
		vector<string> mine2 = construct(C,R,M);
		if(mine2.empty()) return null;
		FOR(i,R) FOR(j,C) mine[i][j] = mine2[j][i];
		return mine;
	}
	
	int N = R*C - M;
	if(C == 1){
		if(N<2) return null;
		
		FOR(i,N) mine[i][0] = '.';
		mine[0][0] = 'c';
		return mine;
	}
	
	if(C==2){
		if(N%2 == 1 || N < 4) return null;
		
		FOR(i,N/2) mine[i][0] = mine[i][1] = '.';
		mine[0][0] = 'c';
		return mine;
	}
	
	if(N < 4 || N == 5 || N == 7) return null;
	
	for(int c = 2; c <= C; c++){
		if(N%c == 0 && N/c <= R){
			FOR(i, N/c) FOR(j, c) mine[i][j] = '.';
			mine[0][0] = 'c';
			return mine;
		}
		
		if(N%c >=2 && (N/c+1 <= R)){
			FOR(i, N/c) FOR(j, c) mine[i][j] = '.';
			FOR(j, N%c) mine[N/c][j] = '.';
			mine[0][0] = 'c';
			return mine;
		}
		
		if(N%c == 1 && (N/c+1 <=R) && (c >= 3) && (N/c >=3)){
			FOR(i, N/c) FOR(j, c) mine[i][j] = '.';
			mine[N/c][0] = '.';
			mine[N/c][1] = '.';
			mine[N/c-1][c-1] = '*';
			mine[0][0] = 'c';
			return mine;
		}
	}
	
	return null;
}

int main(){

	int T;
	cin >> T;
	double R, C, M;
	
	FOR(caseid, T){
		cin>>R>>C>>M;
		cout<<"Case #"<<caseid+1<<":"<<endl;
		vector<string> mine = construct(R,C,M);
		if(mine.empty()){
			cout<<"Impossible"<<endl;
		}
		else{
			FOR(i, R){
				FOR(j, C) cout<<mine[i][j];
				cout<<endl;
			}
		}
	}
	return 0;
}