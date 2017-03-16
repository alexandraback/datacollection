
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

template<class T> inline string toString(T a) { ostringstream is; is << a; is.flush(); return is.str(); }

LL T, R, N, M, K, N2;
LL k[20];
LL a[20];
LL ss[5000];

int main(int argc, char* argv[])
{
#define TASK_NAME(file) "C"file
#define FOLDER(file) "c:\\Projects\\coding\\cj\\2013\\Round1A\\"TASK_NAME("")"\\"file
//	ifstream in(FOLDER(TASK_NAME("-test.in")));
//	ofstream out(FOLDER(TASK_NAME("-test.out")));
//	ifstream in(FOLDER(TASK_NAME("-small-1-attempt0.in")));
//	ofstream out(FOLDER(TASK_NAME("-small-1-attempt0.out")));
	ifstream in(FOLDER(TASK_NAME("-small-2-attempt2.in")));
	ofstream out(FOLDER(TASK_NAME("-small-2-attempt2.out")));

	in >> T;
	in >> R >> N >> M >> K;
	N2 = 1LL<<N;
	out << "Case #1:" << endl;
	FORI(ncase, R) {
		FORI(i, K)
			in >> k[i];

		string res;
		res = "";
		FORI(i, N)
			res += toString(2);
		
		FORI(attempt, 50) {
			LL mm = 2;
			FORI(i, N) {
				a[i] = rand()%(M-mm+1)+mm;
//				mm = a[i];
			}

			FORI(l, N2) {
				LL p = 1;
				FORI(i, N) {
					if(l & (1<<i))
						p *= a[i];
				}
				ss[l] = p;
			}
			sort(ss, ss+N2);

			bool good = 1;
			FORI(i, K) {
				if(!binary_search(ss, ss+N2, k[i])) {
					good = 0;
					break;
				}
			}
			if(good) {
				res = "";
				FORI(i, N)
					res += toString(a[i]);
				goto l1;
			}
		}
l1:

		out << res << endl;
	}
	return 0;
}
