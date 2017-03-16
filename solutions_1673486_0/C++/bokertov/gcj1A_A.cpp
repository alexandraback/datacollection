#include <iostream>
#include <cstdio>
#include <fstream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <list>

using namespace std;

const double EPS = 1E-14;

ifstream fin("A.in");
ofstream fout("A.out");

int main()
{
	int T;
	fin >> T;
	for(int caseID=1; caseID<=T; caseID++) {
		//fout << "Case #" << caseID << ": ";
		printf("Case #%d: ", caseID);
		int A, B;
		fin >> A >> B;
		vector<double> p(A+1);
		for(int i=1; i<=A; i++) {
			fin >> p[i];
			p[i] = 1-p[i];
		}
		vector<double> p1(A+1); // p1[i]: (1-p1)*..*(1-pi);
		p1[0] = 1.0;
		for(int i=1; i<=A; i++) {
			p1[i] = p1[i-1]*(1-p[i]);
		}

		double minsteps = 2+B;
		for(int k=0; k<=A; k++) {
			double tmp = A-2*k+(2-p1[k])*(B+1);
			//fout << k << " " << p1[k] << " " << tmp << endl;
			if(tmp<minsteps)
				minsteps = tmp;
		}
		printf("%lf\n", minsteps);
	}

	return 0;
}
