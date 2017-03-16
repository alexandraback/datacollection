#include <iostream>
#include <vector>
#include <cstdio>
#include <set>

using namespace std;

int main() {
	int T;
	cin >> T;
	for(int cc = 0; cc < T; cc++) {
		int A, B;
		cin >> A >> B;
		long long rec = 0;
		char x[20];
		sprintf(x, "%d", B);
		string bb(x);
		set<string> done;
		for(int i = A; i <= B; i++) {
			sprintf(x, "%d", i);
			string n(x);
			for(int j = 1; j < n.size(); j++) {
				string m = n.substr(j) + n.substr(0, j);
				if(m[0] == '0') continue;
				else if(n < m && m <= bb) {
					if(done.count(n + m)) continue;
					done.insert(n + m);
					rec++;
				}
			}
		}
		cout << "Case #" << cc + 1 << ": " << rec << endl;
	}
}
