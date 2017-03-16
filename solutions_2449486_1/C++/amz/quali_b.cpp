#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <vector>
#include <map>
#include <list>
#include <cmath>

using namespace std;


void processCase(istream& in, ostream& out)
{
	int N, M;
	in >> N;
	in >> M;

	std::vector<int> lawn(N * M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			in >> lawn[i * M + j];
		}
	}

	// Their minimum height... starts at 0, so that's fine
	std::vector<int> hCutters(N);
	std::vector<int> vCutters(M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			int h = lawn[i * M + j];

			hCutters[i] = std::max(hCutters[i], h);
			vCutters[j] = std::max(vCutters[j], h);
		}
	}

	// Now just verify whether, for each tile, one of the two cutters could have done it
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			int h = lawn[i * M + j];
			if (h < hCutters[i] && h < vCutters[j]) {
				out << "NO";
				return;
			}
		}
	}
	out << "YES";
}

int main()
{
	ifstream in("B-large.in");
	//ostream& out = cout;
	ofstream out("B-large.out", std::ios_base::out);

	int nCases;
	in >> nCases;

	for (int i=0; i<nCases; i++) {
		out << "Case #" << (i+1) << ": ";
		processCase(in, out);
		out << endl;
	}

	out.flush();
}
