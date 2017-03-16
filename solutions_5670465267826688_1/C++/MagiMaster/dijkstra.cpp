#include "dijkstra.h"

#include <fstream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iostream>
#include <array>
using namespace std;

class grid {
public:
	char *data;
	int w, h;

	grid(int W, int H) {
		w = W;
		h = H;
		data = new char[w*h];
	}

	grid(grid &&g) {
		w = g.w;
		h = g.h;
		data = g.data;
		g.data = nullptr;
	}

	grid(const grid &g) {
		w = g.w;
		h = g.h;
		data = new char[w*h];
		for(int i = 0; i < w*h; ++i)
			data[i] = g.data[i];
	}

	~grid() { delete[] data; }

	char &operator()(int x, int y) { return data[y*w + x]; }
	char operator()(int x, int y) const { return data[y*w + x]; }
};

char table[8][8][8] = { {
	{ 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o' },
	{ 'i', 'l', 'k', 'n', 'm', 'h', 'o', 'j' },
	{ 'j', 'o', 'l', 'i', 'n', 'k', 'h', 'm' },
	{ 'k', 'j', 'm', 'l', 'o', 'n', 'i', 'h' },
	{ 'l', 'm', 'n', 'o', 'h', 'i', 'j', 'k' },
	{ 'm', 'h', 'o', 'j', 'i', 'l', 'k', 'n' },
	{ 'n', 'k', 'h', 'm', 'j', 'o', 'l', 'i' },
	{ 'o', 'n', 'i', 'h', 'k', 'j', 'm', 'l' }
} };

grid multiplyTable(string s) {
	grid out(s.length(), s.length() + 1);

	for(int i = 0; i < s.length(); ++i) {
		out(i, i) = 'h';
		char last = 'h';
		for(int j = i; j < s.length(); ++j) {
			last = table[last - 'h'][s[j] - 'h'][0];
			out(i, j + 1) = last;
		}
	}

	return out;
}

char multiply(char x, char y) {
	return table[x - 'h'][y - 'h'][0];
}

char multiply(char x, char y, char z) {
	return table[x - 'h'][y - 'h'][z - 'h'];
}

array<char, 4> multiplyRep(char c) {
	array<char, 4> res;
	char last = 'h';
	res[0] = 'h';
	c -= 'h';

	for(int i = 1; i < 4; ++i) {
		 last = table[last - 'h'][c][0];
		 res[i] = last;
	}

	return res;
}

void initTable() {
	for(int i = 1; i < 8; ++i) {
		for(int j = 0; j < 8; ++j) {
			for(int k = 0; k < 8; ++k) {
				table[i][j][k] = table[0][i][table[0][j][k] - 'h'];
			}
		}
	}
}

void dijkstra(string filename) {
	initTable();

	ifstream infile(filename + ".in");
	ofstream outfile(filename + ".out");

	int t;
	infile >> t;

	for(int z = 1; z <= t; ++z) {
		long long l, x;
		string s;
		bool ok = false;

		infile >> l >> x >> s;

		auto split = multiplyTable(s);
		auto rep = multiplyRep(split(0, l));

		for(int ri = 0; ri < 4 && !ok; ++ri) {
			for(int i = 0; i < s.length() && !ok; ++i) {
				if(multiply(rep[ri], split(0, i)) != 'i')
					continue;

				for(int rj = -1; rj < 4 && !ok; ++rj) {
					for(int j = 0; j < s.length() && !ok; ++j) {
						if(rj == -1 && j <= i)
							continue;

						char cj;
						if(rj == -1)
							cj = split(i, j);
						else
							cj = multiply(split(i, l), rep[rj], split(0, j));

						if(cj != 'j')
							continue;

						int used = ri + rj + 2;
						int rk = x - used;
						if(rk < 0)
							continue;

						if(multiply(split(j, l), rep[rk % 4]) != 'k')
							continue;

						ok = true;
					}
				}
			}
		}

		if(ok)
			outfile << "Case #" << z << ": YES" << endl;
		else
			outfile << "Case #" << z << ": NO" << endl;
	}
}