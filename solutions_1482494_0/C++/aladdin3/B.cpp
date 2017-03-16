/*
 * Codejam 2012: Round 1A
 * Author: Mahmoud Aladdin (Platter)
 * 
 */

#include <map>
#include <cmath>
#include <string>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <fstream>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long _long;
typedef vector<int> _vi;
typedef pair<int, int> _pii;
typedef vector<_pii> _vpii;
typedef vector<string> _vs;

#define REP(i, n) for(int (i) = 0; (i) < (n); ++(i))
#define REPit(it, rit) for(typeof(rit.begin()) (it) = (rit).begin(); (it) != (rit).end(); ++(it))
#define SZ(v) (int)v.size()
#define ALL(v) v.begin(), v.end()
#define PB(m) push_back(m)
#define MP(a, b) make_pair(a, b)

int main(){
	ifstream file_in("B.in");
	ofstream file_out("B.out");

	int T, N;
	file_in >> T;
	for(int tt = 1; tt < T + 1; ++tt){
		file_in >> N;
		_vpii lvl; vector<bool> reached, sr;
		REP(i, N){
			int s, l; file_in >> s >> l;
			lvl.PB(MP(l, s));
			reached.PB(false);
			sr.PB(false);
		}
		sort(ALL(lvl)); bool pos = true;
		for(int i = 0; i < SZ(lvl); i++){
			if(lvl[i].first <= (i) * 2) {
				reached[i] = true;
				sr[i] = true;
			} else {
				int p = ((i == 0)? 0: (i) * 2);
				int S = lvl[i].first - ((i == 0)? 0: (i) * 2);
				cout << tt << " " << S << " " << p << endl;
				for(int j = i; j < SZ(lvl); j++){
					if(sr[j]) continue;
					if(lvl[j].second <= p){
						S--;
						sr[j] = true;
					}
					if(S == 0) break;
				}
				if (S != 0) {
					pos = false;
					break;
				}
			}
		}
		file_out << "Case #" << tt << ": ";
		if(!pos){
			file_out << "Not Possible\n";
			cout << "Not Possible\n";
			
		} else {
			int req = SZ(lvl) + lvl[0].first;
			file_out << req << endl;
			cout << "req " << req << endl;
		}
		
		
	}
	cout << "Program Terminated";
	return 0;
}
