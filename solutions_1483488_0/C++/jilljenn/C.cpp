#include <iostream>
#include <sstream>
#include <string>
#include <map>
using namespace std;

string s, t;
stringstream out;

int f(int A, int B) {
	int m, nbPaires = 0;
	map<int, int> ms;
	for(int n = A ; n <= B ; n++) {
		out << n;
		s = out.str();
		for(int i = 1 ; i < s.length() ; i++) {
			t = s.substr(i) + s.substr(0, i);
			m = atoi(t.c_str());
			if(!ms.count(m) && m > n && m >= A && m <= B) {
				ms[m] = 1;
				nbPaires++;
			}
		}
		out.clear();
		out.str(string());
		ms.clear();
	}
	return nbPaires;
}

int main() {
	int A, B, T;
	cin >> T;
	for(int i = 1 ; i <= T ; i++) {
		cin >> A >> B;
		cout << "Case #" << i << ": " << f(A, B) << endl;
	}
	return 0;
}