//============================================================================
// Name        : codejamB.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
using namespace std;


int n,m;
int a[100][100];


bool isHigher(int h, int i, int j, int di, int dj){
	for(int k = -1; k<=1; k+=2){
		int r = i + k*di;
		int c = j + k*dj;
		for(; r>=0 && r<n && c>=0 && c<m; r+= k*di, c+=k*dj){
			if(a[r][c] > h){
				return true;
			}
		}
	}
	return false;
}

string solve(){
	cin>>n>>m;
	for(int i=0; i<n; ++i){
		for(int j=0; j<m; ++j){
			cin>>a[i][j];
		}
	}
	for(int i=0; i<n; ++i){
		for(int j=0; j<m; ++j){
			if(isHigher(a[i][j], i,j, 0, 1) && isHigher(a[i][j], i, j, 1, 0)){
				return "NO";
			}
		}
	}
	return "YES";
}

int main() {
	int T;
	cin>>T;
	for(int i=0; i<T; ++i){
		string ans = solve();
		cout<<"Case #"<<i+1<<": "<<ans<<endl;
	}
	return 0;
}
