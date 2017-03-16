#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector <string> vs;
typedef vector <int> vi;
#define REP(a,b) for(int a=0;a<(b);++a)
#define FOR(a,c,b) for(int a=c;a<(b);++a) 



int main() 
{
	ifstream fin("B-small-attempt0.in");
	//ifstream fin("b.in");
	ofstream fout("b.out");

	int tc;
	int n, s, p, a;



	fin >> tc;

	REP(tcase,tc) {
		int can1 = 0, can2 = 0, minscore1, minscore2;
		fin >> n >> s >> p;

		minscore1 = 3*p-2;
		minscore2 = 3*p-4;

		if (p == 1) {
			minscore2 = 1;
		}

		REP(i,n) {
			fin >> a;
			if ( a >= minscore1 ) can1++;
			else if (a >= minscore2) can2++;
		}

		int res = can1 + min(can2, s);

		fout << "Case #" << tcase+1 << ": "<< res << endl;;
	}

	fout.close();

	return 0;
}