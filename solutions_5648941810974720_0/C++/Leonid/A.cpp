#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cmath>
#include <string>
#include <cstring>
#include <cstdio>
#include <cassert>
#include <list>
using namespace std;

const char* STR[] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};

void openFiles() {
	// freopen("test.in", "rt", stdin);
	// freopen("test.out", "wt", stdout);
	freopen("A-small-attempt0.in", "rt", stdin);
	freopen("A-small-attempt0.out", "wt", stdout);
	// freopen("A-large.in", "rt", stdin);
	// freopen("A-large.out", "wt", stdout);
}

template <class T>
ostream& operator<<(ostream& os, const set<T>& s) {
	os << "[";
	for (typename set<T>::const_iterator ii = s.begin(); ii != s.end(); ++ii)
		cout << " " << *ii;
	os << " ]";
    return os;
}

template <class T>
ostream& operator<<(ostream& os, const vector<T>& v) {
	os<<"[";for(int i=0;i<v.size();i++)os<<" "<<v[i];os<<" ]";
    return os;
}

void solve() {
	vector<set<int> > let(26);
	for (int i = 0; i < 10; i++) {
		int n = strlen(STR[i]);
		//cout << STR[i] << endl;
		for (int j = 0; j < n; j++) {
			int l = STR[i][j] - 'A';
			let[l].insert(i);
		}
	}
	for (int j = 0; j < 26; j++) {
		if (let[j].size() >= 1) { 
			// cout << (char)('A' + j) << endl;
			// cout << let[j] << endl;
		}
	}

	vector<int> order;
	vector<char> letter;

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 26; j++) {
			if (let[j].size() == 1) {				
				int l = *(let[j].begin());
				//cout << (char)('A' + j) << ": " << l << endl;
				order.push_back(l);
				letter.push_back((char)('A' + j));
				for (int k = 0; k < 26; k++) {
					let[k].erase(l);
				}
				break;
			}
		}
	}

	string line; getline(cin, line);
	vector<int> f(26);
	for (int i = 0; i < line.size(); i++) {
		f[line[i] - 'A']++;
	}
	//cout << f << endl;

	vector<int> cnt(10);
	for (int i = 0; i < 10; i++) {
		int o = order[i];
		char l = letter[i];
		//cout << o << " " << l << endl;
		int fr = f[l - 'A'];
		cnt[o] = fr;
		int n = strlen(STR[o]);
		//cout << f << endl;
		for (int j = 0; j < n; j++) {
			f[STR[o][j] - 'A'] -= fr;
		}
	}


	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < cnt[i]; j++) {
			printf("%d", i);
		}
	}
	printf("\n");	
}

int main() {
    openFiles();
    int n; scanf("%d ", &n);
    for (int i = 0; i < n; i++) {
            printf("Case #%d: ", i + 1);
            solve();
    }
    return 0;
}
