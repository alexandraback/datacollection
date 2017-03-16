#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <list>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <numeric>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <iterator>
#include <complex>
#include <stack>
#include <queue>
#include <ctime>
#include <cassert>
//#include <NTL/ZZ.h>
using namespace std;
//using namespace NTL;
static const double EPS = 1e-8;
typedef long long ll;
typedef unsigned long long ull;
typedef complex <double> pt;
typedef complex <ll> pti;

vector <string> swapv(vector <string> &vs) {
	int r=vs.size(), c=vs[0].size();
	vector <string> res(c);
	for(int i=0; i<c; i++) {
		for(int j=0; j<r; j++) {
			res[i].push_back(vs[j][i]);
		}
	}
	return res;
}

vector <string> solve(int R, int C, int M) {
	vector <string> res;
	bool sswap=(R<C);
	string IMP="Impossible";

	int E=R*C-M;
	if(E==1) {
		res.push_back("c");
		for(int i=1; i<C; i++) res[0].push_back('*');
		for(int i=1; i<R; i++) {
			res.push_back(string(C, '*'));
		}
		return res;
	}
	if(sswap) swap(R, C);
	if(C==1) {
		res.push_back("c");
		for(int i=0; i<R-M-1; i++) {
			res.push_back(".");
		}
		for(int i=0; i<M; i++) {
			res.push_back("*");
		}
		if(sswap) return swapv(res);
		return res;
	}
	if(E<4 || E==5 || E==7) {
		res.push_back(IMP);
		return res;
	}
	if(C==2 && E%2==1) {
		res.push_back(IMP);
		return res;
	}
	int cc=C;
	while(cc>=2) {
		int rr=E/cc;
		int rem=E%cc;
		if(rr<2) {
			cc--;
			continue;
		}
		if(rr>R || rr==R && rem>0) break;
		if(rem==1) {
			if(cc==2) break;
			if(rr==2) {
				cc--;
				continue;
			}
			for(int i=0; i<rr-1; i++) res.push_back(string(cc, '.')+string(C-cc, '*'));
			res.push_back(string(cc-1, '.')+string(C-(cc-1), '*'));
			res.push_back(string(2, '.')+string(C-2, '*'));
			for(int i=rr+1; i<R; i++) res.push_back(string(C, '*'));
		} else {
			for(int i=0; i<rr; i++) res.push_back(string(cc, '.')+string(C-cc, '*'));
			if(rem>0) res.push_back(string(rem, '.')+string(C-rem, '*'));
			else if(rr<R) res.push_back(string(C, '*'));
			for(int i=rr+1; i<R; i++) res.push_back(string(C, '*'));
		}
		res[0][0]='c';
		if(sswap) return swapv(res);
		return res;
	}
	
	res.push_back(IMP);
	return res;
}

int main() {
	int practice=0;
	string prb[12];
	const string difficulty[2][2]={{"-small-attempt.in", "-large.in"}, {"-small-practice.in", "-large-practice.in"}};
	const string extension="";
	//const string extension=".txt";

	char key;
	while(1) {
		for(int i=0; i<12; i++) {
			prb[i].assign(1, 'A'+i/2);
			prb[i]+=difficulty[practice][i%2];
			prb[i]+=extension;
			cout << (char)(i%2?('A'+i/2):('a'+i/2)) << ". " << prb[i] << endl;
		}
		cout << "p. " << (practice?"change to practice mode.":"change to match mode.") << endl;

		do {
			cout << "Choose the input file." << endl;
			cin >> key;
		} while(!('a'<=key && key<'a'+6) && !('A'<=key && key<'A'+6) && key!='p');
		if(key!='p') break;
		practice^=1;
		system("cls");
	}

	int index, cap;
	if(key>='a') { index=(key-'a')*2; cap=0; }
	else { index=(key-'A')*2+1; cap=1; }
	string filename=prb[index];

	if(!cap && !practice) {
		do {
			cout << "Choose number of attempt times." << endl;
			cin >> key;
		} while(key<'0' || '9'<key);
		filename.insert(15, 1, key);
	}

	cout << "Filename is " << filename << endl;
	ifstream ifs(filename.c_str());

	ofstream ofs("output.txt");

	int testcase;
	ifs >> testcase; ifs.ignore();
	for(int testnum=1; testnum<=testcase; testnum++) {
		int R, C, M;
		ifs >> R >> C >> M;
		vector <string> res=solve(R, C, M);
		ofs << "Case #" << testnum << ":" << endl;
		for(int i=0; i<(int)res.size(); i++) {
			ofs << res[i] << endl;
		}
	}
}

//Powered by NTL-5.5.2 (http://www.shoup.net/ntl/)