/*
 * Codejam 2012: Round 1B
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
typedef vector<bool> _vb;

#define REP(i, n) for(int (i) = 0; (i) < (n); ++(i))
#define REPit(it, rit) for(typeof(rit.begin()) (it) = (rit).begin(); (it) != (rit).end(); ++(it))
#define SZ(v) (int)v.size()
#define ALL(v) v.begin(), v.end()
#define PB(m) push_back(m)
#define MP(a, b) make_pair(a, b)

bool equal(_vb a, _vb b){
	if(SZ(a) != SZ(b)){
		return false;
	} else {
		REP(i, SZ(a)){
			if(a[i] != b[i]) {
				return false;
			}
		}
		return true;
	}
}

bool possible(_vi set, _vb &t1, _vb &t2, int sum1, int sum2, int index){
	if (sum1 == sum2) cout << sum1 << " " << sum2 << endl;
	if (index == SZ(set)){
		//~ cout << index << " " << sum1 << " " << sum2 << endl;
		return sum1 == sum2;
	} else {
		if (sum1 != 0 && sum1 == sum2) {
			//~ cout << index << " " << sum1 << " " << sum2;
			return true;
		}
		t1[index] = true;
		if(possible(set, t1, t2, sum1 + set[index], sum2, index + 1)){
			return true;
		} else {
			t1[index] = false; t2[index] = true;
			if(possible(set, t1, t2, sum1, sum2 + set[index], index + 1)){
				return true;
			} else {
				t2[index] = false;
			}
		}
		return possible(set, t1, t2, sum1, sum2, index + 1);
	}
}

int main(){
	ifstream file_in("C.in");
	ofstream file_out("C.out");
	
	int T; file_in >> T;
	for(int tt = 1; tt < T + 1; tt++){
		_vi set;
		_vb t1, t2;
		int N; file_in >> N;
		REP(i, N) {
			int temp; file_in >> temp;
			set.PB(temp); t1.PB(false); t2.PB(false);
		}
		file_out << "Case #" << tt << ":" << endl;
		if(possible(set, t1, t2, 0, 0, 0)){
			bool f = true;
			REP(i, SZ(t1)){
				if(t1[i]){
					if(!f) file_out << " ";
					file_out << set[i];
					f = false;
				}
			}
			file_out << endl;
			f = true;
			REP(i, SZ(t2)){
				if(t2[i]){
					if(!f) file_out << " ";
					file_out << set[i];
					f = false;
				}
			}	
			file_out << endl;
		} else {
			file_out << "Impossible" << endl;
		}
	}
	
	return 0;
}
