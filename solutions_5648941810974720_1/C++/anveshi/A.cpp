// Anve$hi $hukla
#include <bits/stdc++.h>
using namespace std;
struct ${$(){ios_base::sync_with_stdio(false);cin.tie(NULL);}}$;

typedef long long LL;
const int Maxn = 200005;
int testcases;

int main() {
	vector <string> v = {"ZERO", "ONE", "TWO", "THREE", "FOUR", 
	"FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
	map <int, char> m;

	m[0] = 'Z';
	m[2] = 'W';
	m[4] = 'U';
	m[6] = 'X';
	m[8] = 'G';
	m[1] = 'O';
	m[3] = 'T';
	m[5] = 'F';
	m[7] = 'V';
	m[9] = 'E';

	vector <int> order = {0, 2, 4, 6, 8, 1, 3, 5, 7, 9};

	cin >> testcases;   

	for(int tt = 1; tt <= testcases; tt++) {

		vector <int> Ans;
		string s;
		cin >> s;
		vector <int> temp(27, 0);
		int n = s.length();

		for(int i = 0; i < n; i++) {
			temp[s[i] - 'A']++;
		}
		for(int i = 0; i < 10; i++) {
			char z = m[order[i]];
			int val = order[i];
			if(temp[z-'A'] > 0){
				int y = temp[z-'A'];
				for(int j = 0; j < y; j++) {
					Ans.push_back(val);
					for(int k = 0; k < v[val].size(); k++) {
						temp[v[val][k] - 'A']--;
					}
				}
			}
		}
		sort(Ans.begin(), Ans.end());

		cout << "Case #" << tt << ": ";
		for(int i = 0; i < Ans.size(); i++) {
			cout << Ans[i];
		}
		cout << endl;
	}
	return 0;
}
