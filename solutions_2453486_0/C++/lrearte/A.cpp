#include <string>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>

using namespace std;

#define all(x) x.begin(),x.end()
#define bits(x) __builtin_popcount(x)
#define FOR(it,x) for(__typeof(x.begin())it=x.begin();it!=x.end();++it)

#define N 4

bool won(char s, vector<string> tabla) {
	bool ok;
	for (int i=0;i<N;i++) {
		ok = true;
		for (int j=0;j<N;j++) if (tabla[i][j] != 'T' && tabla[i][j]!=s) ok=false;
		if (ok) return true;
	}
	for (int j=0;j<N;j++) {
		ok = true;
		for (int i=0;i<N;i++) if (tabla[i][j] != 'T' && tabla[i][j]!=s) ok=false;
		if (ok) return true;
	}
	
	ok = true;
	for (int i=0;i<N;i++) if (tabla[i][i] != 'T' && tabla[i][i]!=s) ok=false;
	if (ok) return true;
	
	ok = true;
	for (int i=0;i<N;i++) if (tabla[i][N-1-i] != 'T' && tabla[i][N-1-i]!=s) ok=false;
	
	return ok;
}

bool filled(vector<string> tabla) {
	for (int i=0;i<N;i++) for (int j=0;j<N;j++) if (tabla[i][j]=='.') return false;
	return true;
}

int main() {
	int n;

	cin>>n;
	for (int caso = 1; caso <= n; caso++) {
		vector<string> tabla(N);
		for (int i=0;i<N;i++) cin>>tabla[i];
		
		cout << "Case #" << caso << ": ";
		
		if (won('X', tabla)) cout<<"X won";
		else if (won('O', tabla)) cout<<"O won";
		else if (filled(tabla)) cout<<"Draw";
		else cout<<"Game has not completed";
		
		cout << endl; 
	}
	return 0;
}
