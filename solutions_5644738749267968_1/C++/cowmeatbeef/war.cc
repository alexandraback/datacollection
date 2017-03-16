#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

#define REP(i,a) for(int i=0;i<(a);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define FORE(i,a,b) for(int i=(a);i<=(b);i++)
#define SZ(x) ((int)x.size())

string l; // line of input
#define STR(s) getline(cin,l,'\n');s=l;
#define PAR(...) getline(cin,l,'\n');sscanf(l.c_str(),__VA_ARGS__);

void computeCase(int);

int main() {
	freopen("D-large.in", "rt", stdin);
	freopen("D-large.out", "wt", stdout);
	// freopen("D-test.in", "rt", stdin);

	int ncases;
	PAR("%d",&ncases);

	FORE(i,1,ncases)
		computeCase(i);

	return 0;
}

void computeCase(int casen) {
	int N;
	PAR("%d",&N);
	vector<double> nw(N, 0.0);
	REP(i,N) {
		cin >> l;
		sscanf(l.c_str(),"%lf",&nw[i]);
	}
	getline(cin,l,'\n');
	vector<double> kw(N, 0.0);
	REP(i,N) {
		cin >> l;
		sscanf(l.c_str(),"%lf",&kw[i]);
	}
	getline(cin,l,'\n');
	vector<double> ndw(nw);
	vector<double> kdw(kw);

	cout << "Case #" << casen << ": ";

	// decietful war
	sort(ndw.begin(),ndw.end());
	sort(kdw.begin(),kdw.end());
	int points = 0;
	REP(i,N) {
		REP(j,SZ(kdw)) {
			if (ndw.at(i) > kdw.at(j)) {
				kdw.erase(kdw.begin()+j);
				points++;
				break;
			}
		}
	}

	cout << points << " ";

	// war
	sort(nw.begin(),nw.end());
	sort(kw.begin(),kw.end());
	points = 0;
	REP(i,N) {
		REP(j,SZ(nw)) {
			if (kw.at(i) > nw.at(j)) {
				nw.erase(nw.begin()+j);
				points++;
				break;
			}
		}
	}
	cout << N - points;
	cout << endl;
}
