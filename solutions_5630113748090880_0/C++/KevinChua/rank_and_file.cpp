#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

void randAndFile(vector<vector<int> > &lines, int N) {
	vector<int> record(2500, 0);
	for (vector<vector<int> >::iterator it = lines.begin(); it != lines.end(); ++it) {
		vector<int> line = *it;
		for (vector<int>::iterator it2 = line.begin(); it2 != line.end(); ++it2) {
			int pos = *it2;
			record[pos-1] = (record[pos-1] + 1) % 2;
		}
	}
	for (int i = 0; i < record.size(); ++i) {
		if (record[i] == 1) {
			cout << i+1;
			if (--N > 0) cout << " ";
		}
	}
}

int main( int argc, char** argv ) {
	int count = 0;
	cin >> count;
	for (int i = 0; i < count; ++i) {
		int N;
		cin >> N;
		vector<vector<int> > lines(2*N-1, vector<int>(N));
		for (int r = 0; r < 2*N-1; ++r) {
			for (int c = 0; c < N; ++c) {
				int height;
				cin >> height;
				lines[r][c] = height;
			}
		}
		cout << "Case #" << i + 1 << ": ";
		randAndFile(lines, N);
		cout << endl;
	}
	return 0;
}
