#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cmath>

using namespace std;

bool isPal(long long num) {
	string snum;
	stringstream ss;
	ss << num;
	ss >> snum;
	for (int i=0; i<snum.size()/2+1;i++)
		if (snum[i]!=snum[snum.size()-i-1])
			return false;
	return true;
}

int main() {
	ifstream in("q3.in");
	ofstream out("q3.out");

	int t,caseNum = 1;
	in >> t;
	while (caseNum <=t) {
		long long total = 0;
		long long a,b;
		in >> a >> b;
//cout << (long long)sqrtl(a) << ' ' << (long long)sqrtl(b) << endl;
		long long sa = (long long)sqrtl(a);
		long long sb = (long long)sqrtl(b);
		long long p = sa;
		while (p<=sb+1) {
			if (p*p<a || p*p>b) {
				p++;
				continue;
			}
			if (!isPal(p)) {
				p++;
				continue;
			}
			if (!isPal(p*p)) {
				p++;
				continue;
			}
cout << "Find : " << p << ' ' << p*p << endl;
			p++;
			total++;
		}
		out << "Case #" << caseNum << ": " << total << endl;
		caseNum++;
	}
	out.close();
}