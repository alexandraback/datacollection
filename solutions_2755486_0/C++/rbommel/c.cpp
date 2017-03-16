#include <iostream>
#include <fstream>
#include <algorithm>
#include <cstring>
#include <set>
#include <cassert>

using namespace std;

ifstream fin ("c.in");
ofstream fout ("c.out");

int T, N, A;
int muur[1000];
struct attack {
	int d;
	int e;
	int w;
	int h;
};

struct sortattack {
	bool operator () (attack const& lhs, attack const& rhs) {
		if (lhs.d != rhs.d)
		    return lhs.d < rhs.d;
		if (lhs.h != rhs.h)
		    return lhs.h < rhs.h;
		if (lhs.e != rhs.e)
		    return lhs.e < rhs.e;
		return lhs.w < rhs.w;
	}
};
	

set<attack,sortattack> aanvallen;

void addattack(int day, int east, int west, int height) {
	attack aanval;
	aanval.d = day;
	aanval.e = east;
	aanval.w = west;
	aanval.h = height;
	aanvallen.insert(aanval);
	return;
}

int checkattack(int day, int east, int west, int height) {
	//cout << "checkattack(" << day << ", " << east;
	//cout << ", " << west << ", " << height << ") = ";
	for (int i = east + 500; i < west + 500; i++)
	if (muur[i] <  height) {
		//cout << "1\n";
		return 1;
	}
	//cout << "0\n";
	return 0;
}

void resolveattack(int day, int east, int west, int height) {
	//cout << "resolveattack(" << day << ", " << east;
	//cout << ", " << west << ", " << height << ");\n";
	for (int i = east + 500; i < west + 500; i++)
		muur[i] = max(muur[i], height);
	return;
}

int main () {
	fin >> T;
	for (int i = 1; i <= T; i++) {
		fout << "Case #" << i << ": ";
		//cout << "\n";
		fin >> N;
		A = 0;
		aanvallen.clear();
		int di, ni, wi, ei, si, ddi, dpi, dsi;
		for (int j = 0; j < N; j++) {
			fin >> di >> ni >> wi >> ei >> si;
			fin >> ddi >> dpi >> dsi;
			for (int k = 0; k < ni; k++) {
				addattack(di + k*ddi, wi + k*dpi, ei + k*dpi, si + k*dsi);
			}
		}
	
		int opl = 0;
		for (int j = 0; j < 1000; j++)
			muur[j] = 0;
		set<attack>::iterator itb, ite;
		ite = aanvallen.begin();
		itb = ite;
		while (ite != aanvallen.end()) {
			int day = (*ite).d;
			while ((ite != aanvallen.end()) and ((*ite).d == day)) {
				opl += checkattack((*ite).d, (*ite).e, (*ite).w, (*ite).h);
				ite++;
			}
			while (itb != ite) {
				resolveattack((*itb).d, (*itb).e, (*itb).w, (*itb).h);
				itb++;
			}
		}
	
		fout << opl << '\n';	
	}
	
	
	return 0;
}
