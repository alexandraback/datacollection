#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <set>
#include <sstream>
#include <cassert>
using namespace std;

int R,N,M,K;

map<int, set<string> > sums;
int V[10];

set<string> possible;

string get_best_fit() {
	possible.clear();
	set<string>::iterator it;
	set<string>::iterator f;
	for(it = sums[V[0]].begin(); it != sums[V[0]].end(); it++)
		possible.insert(*it);
	for(int i = 1; i < K; i++) {
		set<string> cur = possible;
		possible.clear();
		for(it = cur.begin(); it != cur.end(); it++) {
			f = sums[V[i]].find(*it);
			if(f != sums[V[i]].end())
				possible.insert(*it);
		}
		if(possible.size()==0)
			assert(false);
	}
	return *(possible.begin());
}


int main() {
	int testcases;
	cin >> testcases;
	for(int curtestcase = 1; curtestcase <= testcases; curtestcase++) {
		cout << "Case #" << curtestcase << ":";
		cout << endl;
		cin >> R >> N >> M >> K;
		for(int a = 2; a <= M; a++)
			for(int b = a; b <= M; b++)
				for(int c = b; c <= M; c++) {
					stringstream ss;
					ss << a << b << c;
					string s = ss.str();
					sums[1].insert(s);
					sums[a].insert(s);
					sums[b].insert(s);
					sums[c].insert(s);
					sums[a*b].insert(s);
					sums[a*c].insert(s);
					sums[b*c].insert(s);
					sums[a*b*c].insert(s);
				}
				
		while(R--) {
			for(int i = 0; i < K; i++)
				cin >> V[i];
			cout << get_best_fit() << endl;
		}
	}
}