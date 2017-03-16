#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <map>
#include <list>
#include <set>
#include <numeric>
#include <queue>
#include <stack>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <cstring>
#define FOR(i, b, e) for (typeof(b) i = (b); i != (e); ++i)
#define VAR(a,b) typeof(b) a=b
#define dout cout
using namespace std;
typedef long long LL;

struct SCOPE
{
	void run(int Case)
	{
		int A, B;
		cin >> A >> B;
		double d=B+1;
		double correct = 1;
		FOR(i,0,A){
			//cout << i << ".. " << d << endl;
			double p;
			cin >> p;
			correct *= p;
			double d0=2+d;
			double d1=correct*(B+1)+(1-correct)*2*(B+1);
			double d2=A+1+B+1;
			d=min(d0,d1);
			d=min(d,d2);
			//cout << i << ": " << d << ", " << d0 << ", " << d1 << endl;
		}
		cout << "Case #" << Case << ": " << d - A << endl;
	}
};

int main() {
	cout.precision(10);
	int T;
	cin >> T;
	for (int t=1;t<=T;t++) {
		SCOPE* pSCOPE = new SCOPE();
		pSCOPE->run(t);
		delete pSCOPE;
	}
}
