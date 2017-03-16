//Problem A. Password Problem
#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <cstring>
#include <climits>
using namespace std;
#define PB push_back
#define MP make_pair
#define REP(i,n) for(i=0;i<(n);++i)
#define FOR(i,l,h) for(i=(l);i<=(h);++i)
#define FORD(i,h,l) for(i=(h);i>=(l);--i)
#define foreach(itr, cont) for (typeof(cont.begin()) itr = cont.begin(); itr != cont.end(); itr++)
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<double> VD;
typedef long long LL;
typedef pair<int,int> PII;

int main() {
	int T, A, B;

	//ifstream in("A-small-attempt1.in");
	//ofstream out("A-small-attempt1.out");
	//ifstream in("C-large.in");
	//ofstream out("C-large.out");
	FILE *in = fopen("A-large.in", "r");	
	FILE *out = fopen("A-large.out", "w");

	//in >> T;
	fscanf(in, "%d", &T);
	for (int cs = 1; cs <= T; cs ++) {
		//out << "Case #" << cs << ": ";
		fprintf(out, "Case #%d: ", cs);

		//in >> A >> B;
		fscanf(in, "%d%d", &A, &B);
		vector<double> prob;
		for (int i = 0; i < A; i ++) {
			double input;
			fscanf(in, "%lf", &input);
			//cout << input << endl;
			prob.push_back(input);
		}
		double exp = 10000000.0;

		double sum = 1.0;
		for (int i = 0; i < A; i ++) {
			sum *= prob[i];
			exp = min(exp, (A-1-i+B-i)*sum + (1.0-sum)*(A-1-i+B-i+B+1));
			//cout << (A-i+B-i-1)*sum + (1.0-sum)*(A-i+B-i-1+B+1) << endl;
		}
		//cout << A + B + 1.0 << endl;
		//cout << B + 2.0 << endl;
		exp = min(exp, A + B + 1.0);
		exp = min(exp, B + 2.0);
		//out << exp << endl;
		fprintf(out, "%.6lf\n", exp);
	}
	return 0;
}
