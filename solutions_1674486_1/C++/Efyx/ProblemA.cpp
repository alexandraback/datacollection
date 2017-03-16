// Google Code Jam 2012
// Problem A. Diamond Inheritance

#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

bool browse(vector< vector<int> > &classes, int n, vector<bool> &reached) {
	if(reached[n]) return true;
	reached[n] = true;

	vector<int> &classe = classes[n];
	for(size_t m=0; m<classe.size(); m++) {
		if(browse(classes, classe[m], reached)) return true;
	}
	return false;
}

int main(int argc, char* argv[]) {
	int T;
	cin >> T;
	for(int t=0; t<T; t++)
	{
		int N; // number of classes
		cin >> N;

		vector< vector<int> > classes(N);
		for(int n=0; n<N; n++) {
			int M;
			cin >> M;
			classes[n].resize(M);
			for(int m=0; m<M; m++) {
				cin >> classes[n][m];
				classes[n][m]--;
			}
		}

		bool diamond = false;
		for(int n=0; n<N; n++) {
			vector<bool> reached(N);
			diamond = browse(classes, n, reached);
			if(diamond) break;
		}

		cout << "Case #" << t+1 << ": " << (diamond?"Yes":"No") << endl;
	}

	return 0;
}
