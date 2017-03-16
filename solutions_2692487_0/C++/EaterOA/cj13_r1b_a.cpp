#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ifstream fin("in.txt");
	ofstream fout("out.txt");
	int T;
	fin >> T;
	for (int t = 1; t <= T; t++) {
		int A, N;
		fin >> A >> N;
		int op = 0;
		long long* motes = new long long[N];
		memset(motes, 0, N*8);
		for (int n = 0; n < N; n++)
			fin >> motes[n];
		if (A == 1) {
			op = N;
		}
		else {
			sort(motes, motes+N);
			int* added = new int[N];
			memset(added, 0, N*4);
			long long cur = A;
			for (int n = 0; n < N; n++) {
				//cout << cur << " " << motes[n] << endl;
				while (cur <= motes[n]) {
					cur = cur*2 - 1;
					added[n]++;
				}
				cur += motes[n];
			}
			int count = 0, breakpoint = N;
			for (int n = N-1; n >= 0; n--) {
				count += added[n];
				if (count > breakpoint-n) {
					breakpoint = n;
					count = 0;
				}
			}
			for (int n = 0; n < breakpoint; n++) {
				op += added[n];
			}
			op += N-breakpoint;
			delete motes, added;
		}
		fout << "Case #" << t << ": " << op << endl;
	}
}