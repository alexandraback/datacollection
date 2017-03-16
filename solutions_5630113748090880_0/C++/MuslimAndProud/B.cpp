#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>

#define REP(i, a, b)		for(i = (int)a; i<=(int)b ; i++)
#define FOR(i, N)			REP(i, 0, N-1)

#define VL					vector<long long>

using namespace std;

int main(){
	ifstream cin("B.in");
	ofstream cout("B-Small.out");

	int t, T;
	cin >> T;
	REP(t, 1, T) {
		int N;
		cin >> N;

		set<int> s;
		int i, n;
		int M = (2 * N * N) - N;
		FOR(i, M){
			cin >> n;
			if (s.find(n) == s.end()) {
				s.insert(n);
			}
			else {
				s.erase(s.find(n));
			}
		}
		cout << "Case #" << t << ":";
		for (set<int>::iterator it = s.begin(); it != s.end(); it++){
			cout << " " << *it;
		}
		cout << endl;
	}
	return 0;
}