#include <iostream>
#include <vector>
#include <map>
#include <utility>      // std::pair, std::get
#include <string>
#include <cstring> // memset(void *b, int c, size_t len);
#include <algorithm> // sort
#include <iomanip> // cout << std::fixed << std::setprecision(4)

using namespace std;

int main(int argc, char* argv[]) {
	int T;
	cin >> T;
	map< pair<char,char>, pair<int,char> > maps;
	maps.insert(make_pair(make_pair('1','1'), make_pair(1,'1')));
	maps.insert(make_pair(make_pair('1','i'), make_pair(1,'i')));
	maps.insert(make_pair(make_pair('1','j'), make_pair(1,'j')));
	maps.insert(make_pair(make_pair('1','k'), make_pair(1,'k')));

	maps.insert(make_pair(make_pair('i','1'), make_pair(1,'i')));
	maps.insert(make_pair(make_pair('i','i'), make_pair(-1,'1')));
	maps.insert(make_pair(make_pair('i','j'), make_pair(1,'k')));
	maps.insert(make_pair(make_pair('i','k'), make_pair(-1,'j')));

	maps.insert(make_pair(make_pair('j','1'), make_pair(1,'j')));
	maps.insert(make_pair(make_pair('j','i'), make_pair(-1,'k')));
	maps.insert(make_pair(make_pair('j','j'), make_pair(-1,'1')));
	maps.insert(make_pair(make_pair('j','k'), make_pair(1,'i')));

	maps.insert(make_pair(make_pair('k','1'), make_pair(1,'k')));
	maps.insert(make_pair(make_pair('k','i'), make_pair(1,'j')));
	maps.insert(make_pair(make_pair('k','j'), make_pair(-1,'i')));
	maps.insert(make_pair(make_pair('k','k'), make_pair(-1,'1')));

	for(int t = 0; t < T; ++t) {
		long long L, X;
		string s, ss;
		cin >> L >> X >> s;
		
		if(L*X < 3) {
			cout << "Case #" << t+1 << ": NO" << endl;
			continue;
		}

		ss.reserve(L*X);
		for(int x = 0; x < X; ++x) ss += s;

		int i_check = 0, j_check = 0, k_check = 0;
		int flag = 1;
		char c = '1';
		for(int i = 0; i < L*X; ++i) {
			pair<int,char> p = maps.find( make_pair(c, ss.at(i)) )->second;
			flag *= get<0>(p);
			c = get<1>(p);
			if(i_check) {
				if(j_check) {
					if(i == L*X-1 && flag == -1 && c == '1') k_check = 1;
				} else {
					if(flag == 1 && c == 'k') j_check = 1;
				}
			} else {
				if(flag == 1 && c == 'i') i_check = 1;
			}
		}
		if(k_check) cout << "Case #" << t+1 << ": YES" << endl;
		else cout << "Case #" << t+1 << ": NO" << endl;
	}
	return 0;
}

