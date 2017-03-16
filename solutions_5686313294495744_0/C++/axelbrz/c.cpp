#include <string>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <set>

#define forsn(i,s,n) for(int i=(s);i<(int)(n);i++)
#define forn(i,n) for(int i=0;i<(int)(n);i++)
#define forall(i,c) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)

using namespace std;

map<string, int> _id;
int id(string w) {
	if (_id.find(w) == _id.end()) {
		_id[w] = _id.size();
	}
	return _id[w];
}

int main() {
	ifstream fin("c.in");
	ofstream fout("c.out");
	
	int T, N;
	fin >> T;
	cout << T << endl;
	forn (t, T) {
		_id.clear();
		fin >> N;
		string w1, w2;
		vector<pair<int, int> > ws;
		forn(w,N) {
			fin >> w1 >> w2;
			id(w1);	id(w2);
			cout << id(w1) << " " << id(w2) << endl; 
			ws.push_back(make_pair(id(w1), id(w2)));
		}
		
		
		int mx = 0;
		forn(i,2<<(ws.size()-1)) {
			//cout << "----- " << i << endl;
			set<int> s1, s2;
			vector<pair<int, int> > checks;
			forn (j,ws.size()) {
				if ((i >> j) % 2) {
					s1.insert(ws[j].first);
					s2.insert(ws[j].second);
					//cout << "inserted " << ws[j].first << " " << ws[j].second << endl;
				} else {
					checks.push_back(ws[j]);
				}
			}
			int checks_c = 0;
			forn(j,checks.size()) {
				/*
				cout << "Checking " << checks[j].first << " " << checks[j].second << ": ";
				
				cout << "s1:";
				forall(it, s1) {
					cout << *it << " ";
				}
				cout << endl;
				cout << "s2:";
				forall(it, s2) {
					cout << *it << " ";
				}
				cout << endl;
				
				cout << (s1.find(checks[j].first) != s1.end()) << endl;
				*/
				if (s1.find(checks[j].first) != s1.end() && s2.find(checks[j].second) != s2.end()) {
					checks_c++;
					//cout << "in" << endl;
				}
				//cout << "out" << endl;
			}
			if (checks_c == (int)checks.size()) {
				// valid case
				mx = max(mx, checks_c);
			}
			//cout << "!" << i << " " << mx << endl;
			
			//if (i == 3) return 0;
			
		}
		
		fout << "Case #" << t+1 << ": " << mx << endl;
		cout << "Case #" << t+1 << ": " << mx << endl;
	}
	return 0;
}
