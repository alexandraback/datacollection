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

#define MONDAI "A"
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

	typedef map<char, char> Map;
	Map s_dic;
	void setup() {
		string enc = "y qee ejp mysljylc kd kxveddknmc re jsicpdrysi rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd de kr kd eoya kw aej tysr re ujdr lkgc jv";
		string dec = "a zoo our language is impossible to understand there are twenty six factorial possibilities so it is okay if you want to just give up";

		enc = setup_lastone(enc);
		dec = setup_lastone(dec);

		out(enc);
		out(dec);

		for(int i=0; i<enc.size(); ++i) {
			s_dic.insert(Map::value_type(enc[i], dec[i]));
		}

		out(s_dic.size());
	}

	string setup_lastone(string s) {
		for(char c='a'; c<='z'; ++c) {
			if (string::npos == s.find(c)) {
				s.push_back(c);
				break;
			}
		}
		return s;
	}

	void solve_all_cases(ifstream &in, ofstream &out) {
		setup();

		int T;
		in >> T;
		string s;
		getline(in, s);
		for(int i=0; i<T; i++) {
			string r = solve_a_case(in);
			out << "Case #" << i+1 << ": " << r << endl;
		}
	}

	string solve_a_case(ifstream &in) {
		string r;

		string s;
		getline(in, s);

		out(s);

		for(int i=0; i<s.size(); ++i) {
			r.push_back(s_dic[s[i]]);
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
