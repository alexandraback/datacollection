#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#define REP(i, a, b)		for(i = (int)a; i<=(int)b ; i++)
#define FOR(i, N)			REP(i, 0, N-1)

#define VL					vector<long long>

using namespace std;

int main(){
	ifstream cin("A.in");
	ofstream cout("A-Large.out");

	int t, T;
	cin >> T;
	REP(t, 1, T) {
		string str;
		cin >> str;

		string ans = "";
		int i;
		FOR(i, str.size()) {
			if (i == 0 || str[i]  >= ans.front()) {
				ans = str.substr(i, 1) + ans;
			}
			else {
				ans.push_back(str[i]);
			}
		}
		cout << "Case #" << t << ": " << ans << endl;
	}
	return 0;
}