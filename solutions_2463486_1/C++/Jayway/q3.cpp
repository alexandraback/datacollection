#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cmath>

using namespace std;

const long long palsq[39] = {
	1,4,9,121,484,
    10201,
	12321,
	14641,
	40804,
	44944,
	1002001,
	1234321,
	4008004,
	100020001,
	102030201,
	104060401,
	121242121,
	123454321,
	125686521,
	400080004,
	404090404,
	10000200001L,
	10221412201L,
	12102420121L,
	12345654321L,
	40000800004L,
	1000002000001L,
	1002003002001L,
	1004006004001L,
	1020304030201L,
	1022325232201L,
	1024348434201L,
	1210024200121L,
	1212225222121L,
	1214428244121L,
	1232346432321L,
	1234567654321L,
	4000008000004L,
	4004009004004L};

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
		for (int i=0;i<39;i++) {
			if (palsq[i]>=a && palsq[i]<=b) {
				total++;
			}else if (palsq[i] > b) {
				break;
			}
		}

		/*long long sa = (long long)sqrtl(a);
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
//cout << "Find : " << p << ' ' << p*p << endl;
			p++;
			total++;
		}*/
		out << "Case #" << caseNum << ": " << total << endl;
		caseNum++;
	}
	out.close();
}