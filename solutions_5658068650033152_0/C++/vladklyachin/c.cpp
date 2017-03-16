#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <utility>
#include <cstring>

using namespace std;

int pop(unsigned x)
{
    x = x - ((x >> 1) & 0x55555555);
    x = (x & 0x33333333) + ((x >> 2) & 0x33333333);
    x = (x + (x >> 4)) & 0x0F0F0F0F;
    x = x + (x >> 8);
    x = x + (x >> 16);
    return x & 0x0000003F;
}

#define F(y,x) field[(y)*M+(x)]

char field[1000];

int main(int argc, char ** argv)
{
	if (argc != 3) {
		cerr << "Usage: infile outfile\n";
		return 1;
	}
	ifstream fi(argv[1]);
	if (!fi) {
		cerr << argv[1] << ": " << strerror(errno) << endl;
		return 1;
	}
	ofstream fo(argv[2]);
	if (!fo) {
		cerr << argv[2] << ": " << strerror(errno) << endl;
		return 1;
	}

	int T;
	fi >> T;
	for (int t = 1; t <= T; ++t) {
		int N, M, K;
		fi >> N >> M >> K;
		int nm = N*M;
		int iLimit = 1 << nm;
		int best = (N == 1 && M == 1) ? 1 : 2*N+2*M-4;
		for (int i = 1; i < iLimit; ++i) {
			int bits = pop(i);
			if (bits >= best) continue;
			for (int j = 0; j < nm; ++j) {
				field[j] = (i & (1 << j)) ? '@' : '.';
			}
			int count = 0;
			vector<pair<int,int>> p;
			for (int x = 0; x < M; ++x) {
				if (F(0,x) == '.') {
					p.push_back(make_pair(0,x));
				}
				if (N != 1 && F(N-1,x) == '.') {
					p.push_back(make_pair(N-1,x));
				}
			}
			for (int y = 0; y < N; ++y) {
				if (F(y,0) == '.') {
					p.push_back(make_pair(y,0));
				}
				if (M != 1 && F(y,M-1) == '.') {
					p.push_back(make_pair(y,M-1));
				}
			}
			for (size_t pi = 0; pi < p.size(); ++pi) {
				int y = p[pi].first;
				int x = p[pi].second;
				if (F(y,x) == '.') {
					F(y,x) = '#';
					++count;
					if (y != 0 && F(y-1,x) == '.') p.push_back(make_pair(y-1,x));
					if (y != N-1 && F(y+1,x) == '.') p.push_back(make_pair(y+1,x));
					if (x != 0 && F(y,x-1) == '.') p.push_back(make_pair(y,x-1));
					if (x != M-1 && F(y,x+1) == '.') p.push_back(make_pair(y,x+1));
				}
			}
			if (nm - count < K) continue;
			if (best > bits) best = bits;
		}
		fo << "Case #" << t << ": " << best << endl;
	}
}

/* vim: set ts=4 sw=4 noet: */
