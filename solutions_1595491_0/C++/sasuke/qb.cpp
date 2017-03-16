#include <cstdlib>
#include <cstdio>
#include <string>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <map>
#include <set>
#include <algorithm>
#include <utility>

#define MONDAI "B"
#define DEBUG 0

using namespace std;

class Main {
public:
	Main () {
#if 0
			ifstream in(MONDAI".in");
			ofstream out(MONDAI".out");
#elif 1
			ifstream in(MONDAI"-small-attempt0.in");
			ofstream out(MONDAI"-small-attempt0.out");
#elif 0
			ifstream in(MONDAI"-large.in");
			ofstream out(MONDAI"-large.out");
#endif
			solve_all_cases(in, out);
	}

	void solve_all_cases(ifstream &in, ofstream &out) {

		int T;
		in >> T;
		for(int i=0; i<T; i++) {
			int r = solve_a_case(in);
			out << "Case #" << i+1 << ": " << r << endl;
		}
	}

	int solve_a_case(ifstream &in) {

		int N, S, p;
		in >> N >> S >> p;
		vector<int> t(N);
		for(int i=0; i<N; ++i) {
			in >> t[i];
		}
		out(t);

		int A,B;
		A=B=0;

		int pm1 = max(0, p-1);
		int pm2 = max(0, p-2);
		for(int i=0; i<N; ++i) {
			if (p+pm1+pm1<=t[i]) {
				A++;
			} else if (p+pm2+pm2<=t[i]) {
				B++;
			}
		}

		int r = A + min(S, B);

		waitConsole();
		return r;
	}

	template<typename T>
	void out(vector<T> vt) {
		for(int i=0; i<vt.size(); ++i) {
			out(vt[i]);
		}
	}

	template<typename T>
	void out(T t) {
#if DEBUG
		cout << t << endl;
#endif
	}

	void waitConsole() {
#if DEBUG
		// wait console
		printf("---- put any key ----");
		char c;
		scanf("%c", &c);
#endif
	}

};

int main () {
	Main();
	return 0;
}
