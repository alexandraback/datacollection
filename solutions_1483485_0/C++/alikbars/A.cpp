
#include <stdio.h>
#include <time.h>

#include <vector>
#include <list>
#include <set>
#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <sstream>
#include <queue>
#include <map>
#include <iomanip>
#include <sstream>
#define _USE_MATH_DEFINES
#include <cmath>
#include <stack>
#include <numeric>
#include <complex>

using namespace std;


typedef long long LL;
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<double> VD;
typedef vector<LL> VL;
#define FORE(it, c, T) for(T::iterator it = c.begin(); it != c.end(); it++)
#define FORI(i, n) for(int i = 0; i < (n); i++)
#define FORIS(i, s, n) for(int i = (s); i < (n); i++)
#define CLEAR(a, n) memset(a, n, sizeof(a))
#define PB(n) push_back(n)
#define SZ(c) int((c).size())
#define ALL(c) (c).begin(), (c).end()

#define NUM 101

int T, N;

string s = "our language is impossible to understand there are twenty six factorial possibilities so it is okay if you want to just give up a zoo q";
string c = "ejp mysljylc kd kxveddknmc re jsicpdrysi rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd de kr kd eoya kw aej tysr re ujdr lkgc jv y qee z";

int main(int argc, char* argv[])
{
#define TASK_NAME(file) "A"file
#define FOLDER(file) "c:\\Projects\\coding\\cj\\2012\\QualificationRound\\"TASK_NAME("")"\\"file
//	ifstream in(FOLDER(TASK_NAME("-test.in")));
//	ofstream out(FOLDER(TASK_NAME("-test.out")));
	ifstream in(FOLDER(TASK_NAME("-small-attempt1.in")));
	ofstream out(FOLDER(TASK_NAME("-small-attempt1.out")));
//	ifstream in(FOLDER(TASK_NAME("-large.in")));
//	ofstream out(FOLDER(TASK_NAME("-large.out")));

	in >> T;
	string cc;
	getline(in, cc);
	FORI(ncase, T) {
		getline(in, cc);
		string ss;
		FORI(i, SZ(cc)) {
			FORI(j, SZ(c)) {
				if(c[j] == cc[i]) {
					ss += s[j];
					break;
				}
			}
		}
		out << "Case #" << (ncase+1) << ": " << ss << endl;
	}
	return 0;
}
