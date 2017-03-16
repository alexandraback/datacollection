#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

ofstream fout("out.txt");
ifstream fin("in.txt");

int B, M;

bool pathExists(int a, int b, const vector<int> &X) {
	//cout << a << " to " << b << endl;
	int p = ((a+1)*(2*B-2-a))/2;
	//cout << p << endl;
	p -= B - b;
	//cout << p << endl;
	return X[p];
}

bool nextPerm(vector<int> &X) {
	int s = X.size();
	int i = s - 1;
	while (i>=0 && X[i] == 1)
		i--;

	if (i == -1)
		return false;
	X[i] = 1;
	while (++i < s)
		X[i] = 0;
}

void printMatrix(const vector<int> &X) {
	for (int i = 0; i < B; i++) {
		for (int j = 0; j < B; j++) {
			if (i < j)
				fout << pathExists(i, j, X);
			else
				fout << 0;
		}
		fout << endl;
	}
}

void function1(const int test_no) {
	fin >> B;
	fin >> M;
	//B = 5;
	//M = 4;
	
	int v = (B*B - B) / 2;

	vector<int> X(v, 0);
	bool possible = false;
	do {
		//counting time
		vector<int> res(B, 0);
		res[0] = 1;
		for (int b = 1; b < B; b++) {
			for (int c = 0; c < b; c++)
				if (pathExists(c, b, X))
					res[b] += res[c];
		}
				
		if (res[B - 1] == M) {
			
			cout << res[B - 1] << endl;
			for (int i = 0; i < X.size(); i++)
				cout << X[i];
			cout << endl;
			
			possible = true;
			break;
		}

	} while (nextPerm(X));
	
	if (!possible) {
		fout << "Case #" << test_no << ": " << "IMPOSSIBLE" << endl;
		return;
	}
	fout << "Case #" << test_no << ": " << "POSSIBLE" << endl;
	printMatrix(X);
}

int main() {
	int T;
	fin >> T;
	//T = 1;
	for (int t = 1; t <= T; t++) {
		function1(t);
	}

	return 0;
}