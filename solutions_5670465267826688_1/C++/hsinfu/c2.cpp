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
		string s;
		cin >> L >> X >> s;
		
		if(L*X < 3) { 
			cout << "Case #" << t+1 << ": NO" << endl; 
			continue; 
		}
		
		int charType[3] = {0};
		for(int i = 0; i < L; ++i) charType[s.at(i)-'i'] = 1;

		int nCharType = 0;
		for(int i = 0; i < 3; ++i) nCharType += charType[i];
		if(nCharType == 1 || (nCharType == 2 && L*X < 12)) { 
			cout << "Case #" << t+1 << ": NO" << endl; 
			continue;
		}
		

		int flag = 1;
		char c = '1';
		for(int i = 0; i < L; ++i) {
			pair<int,char> p = maps.find( make_pair(c, s.at(i)) )->second;
			flag *= get<0>(p);
			c = get<1>(p);
		}
		if(c == '1') {
			flag = (X%2 == 0)? 1: flag;
		} else {
			flag = (X%2 == 0)? 1: flag;
			c = (X%2 == 0)? '1': c;
			flag *= ( (X/2)%2 == 0)? 1: -1;
		}

		if(flag == -1 && c == '1') cout << "Case #" << t+1 << ": YES" << endl;
		else cout << "Case #" << t+1 << ": NO" << endl;
	}
	return 0;
}

