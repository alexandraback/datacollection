#include <vector>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

bool dfs( const vector< vector<int> >& gr, vector<bool>& vis, int v )
{
	vis[v] = true;
	for( int i = 0; i < gr[v].size(); i++ ) {
		if( vis[gr[v][i]] ) {
			return true;
		}
		if( dfs( gr, vis, gr[v][i] ) ) {
			return true;
		}
	}
	return false;
}

void solveTest()
{
	int n;
	cin >> n;
	vector< vector<int> > gr(n);
	for( int i = 0; i < n; i++ ) {
		int tmp;
		cin >> tmp;
		gr[i].resize(tmp);
		for( int j = 0; j < tmp; j++ ) {
			cin >> gr[i][j];
			gr[i][j]--;
		}
	}

	for( int i = 0; i < n; i++ ) {
		vector<bool> vis(n);
		if( dfs( gr, vis, i ) ) {
			cout << "Yes" << endl;
			return;
		}
	}
	cout << "No" << endl;
}
int main() {
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int tn = 0;
	cin >> tn;
	for( int tc = 1; tc <= tn; tc++ ) {
		cout << "Case #" << tc << ": ";
		solveTest();
	}
	return 0;
}
