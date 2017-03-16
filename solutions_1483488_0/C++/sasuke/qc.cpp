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

#define MONDAI "C"
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
		int A, B;
		in >> A >> B;

		int r = 0;

		vector<int> mark(B+1, 0);

		int maxD = 1;
		while(maxD<=B) {
			maxD *= 10;
		}

		for(int i=A; i<=B; ++i) {
			if (mark[i]==0) {

				typedef set<int> Set;
				Set cand;
				cand.insert(i);

				for(int j=10; j<=B; j*=10) {
					int a = i / j;
					int b = i % j;

					int c = a + b*(maxD/j);

					if (A<=c && B>=c) { 
						cand.insert(c);
					}
				}

				int CS = cand.size();
				if (CS>=2) {
					int pairs = 1;
					mark[i] = r+1;
					for(Set::iterator itr = cand.begin(); itr!=cand.end(); itr++) {
						mark[*itr] = r+1;
					}
					r += CS*(CS-1)/2;
				}
			}
		}

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
