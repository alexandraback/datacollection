#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <fstream>

using namespace std;


ifstream infile;
ofstream outfile;

string s;

int T;

int N;

int bff[1001];

vector<int> lk[1001];

bool used[1001];

int q[1001];

bool sati[1001];

int max = 0;

void reset() {
	max = 0;
	for (int i = 1; i <= 1000; ++i) {
		used[i] = false;
		sati[i] = false;
		lk[i].clear();
	}
}

void fin(int n) {
	if (bff[q[1]] != q[2] && bff[q[1]] != q[n]) return;
	if (bff[q[n]] != q[n - 1] && bff[q[n]] != q[n - 1]) return;
	for (int i = 2; i < n; ++i)
		if (bff[q[i]] != q[i + 1] && bff[q[i]] != q[i - 1]) return;

	max = max > n ? max : n;
}


void proc(int i) {
	if (sati[i - 1]) {
		for (int j = 0; j < lk[q[i - 1]].size(); ++j) {
			if (used[lk[q[i - 1]][j]]) continue;
			q[i] = lk[q[i - 1]][j];
			used[q[i]] = true;
			sati[i] = false;
			if (bff[q[i]] == q[i - 1]) sati[i] = true;
			if ((bff[q[i]] == q[1] || bff[q[1]] == q[i] || (sati[i] && sati[1])) && i > max) fin(i);
			proc(i + 1);
			used[q[i]] = false;
		}
	}
	else {
		if (used[bff[q[i - 1]]]) return;
		q[i] = bff[q[i - 1]];
		used[q[i]] = true;
		sati[i - 1] = true;
		sati[i] = false;
		if (bff[q[i]] == q[i - 1]) sati[i] = true;
		if ((bff[q[i]] == q[1] || bff[q[1]] == q[i] || (sati[1] && sati[i])) && i > max) fin(i);
		proc(i + 1);
		used[q[i]] = false;
	}
}

int main() {
	infile.open("input.txt");
	outfile.open("output.txt");

	infile >> T;

	for (int p = 1; p <= T; ++p) {
		reset();
//		max = 0;

		outfile << "Case #" << p << ": ";

		infile >> N;
		
		for (int i = 1; i <= N; ++i) {
			infile >> bff[i];
			lk[i].push_back(bff[i]);
			lk[bff[i]].push_back(i);
		}

		for (int i = 1; i <= N; ++i) {
			q[1] = i;
			used[i] = true;
			sati[1] = false;

			for (int j = 0; j < lk[i].size(); ++j) {
				q[2] = lk[i][j];
				used[q[2]] = true;
				sati[2] = false;
				if (bff[q[1]] == q[2]) sati[1] = true;
				if (bff[q[2]] == q[1]) sati[2] = true;
				fin(2);
				proc(3);
				used[q[2]] = false;
			}
			used[q[1]] = false;
		}
		
		outfile << max << endl;
	}

	infile.close();
	outfile.close();
	return 0;
}