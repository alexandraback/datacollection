#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <numeric>
using namespace std;

vector<string> car;

void remove_rep(string &s) {
	s = s.substr(0, unique(s.begin(),s.end())-s.begin());
}

int main() {
	ios::sync_with_stdio(false);
	int T, N, res;
	string s;

	cin >> T;
	for(int cs = 1; cs <= T; ++cs) {
		cin >> N;
		car.resize(N);
		for(int i = 0; i < N; ++i) {
			cin >> car[i];
			car[i] = char(i) + car[i];
			remove_rep(car[i]);
		} 
		res = 0;
		sort(car.begin(), car.end());
		do {
			int pos = 0;
			char cc = '$';
			for(int i = 0; i < N; i++) {
				for(string::iterator it = car[i].begin()+1; it != car[i].end(); ++it) if(*it != cc) {
					if(pos & (1<<(*it-'a'))) {
						goto C;
					}
					cc = *it;
					pos |= 1<<(*it-'a');
				}
			}
			//cout << accumulate(car.begin(), car.end(), string()) << endl;
			res++;
C:;
		} while(next_permutation(car.begin(), car.end()));
		cout << "Case #" << cs << ": " << res << endl;
	}
	return 0;
}