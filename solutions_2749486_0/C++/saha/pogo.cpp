/*
 * osmos.cpp
 *
 *  Created on: May 4, 2013
 *      Author: saha
 */


#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <algorithm>
#include <cstring>
#include <queue>
#include <deque>
#include <map>

using namespace std;

typedef long long mylong;

int main()
{
	int T;
	int fx, fy;

	cin >> T ;
//	cout << "Number of test cases = " << T << endl;
	for(int t=1; t<=T ; t++) {
		cin >> fx >> fy ;

		map<pair<int,int>, string > tab;
		map<pair<int,int>, int > jump;
		queue<pair<int,int> > Q;
		Q.push(make_pair(0,1));
		Q.push(make_pair(0,-1));
		Q.push(make_pair(1,0));
		Q.push(make_pair(-1,0));
		tab[make_pair(1,0)]  = "E";
		tab[make_pair(-1,0)] = "W";
		tab[make_pair(0,1)]  = "N";
		tab[make_pair(0,-1)] = "S";
		jump[make_pair(0,1)]  = 1;
		jump[make_pair(0,-1)] = 1;
		jump[make_pair(1,0)]  = 1;
		jump[make_pair(-1,0)] = 1;

		string res = "";
		while(!Q.empty()) {
			pair<int,int> f = Q.front();
			Q.pop();
			string sofar = tab[f];
			int step     = jump[f]+1;

			if(f.first == fx && f.second == fy) {
				res = tab[f];
				break;
			}

			if(tab.count(make_pair(f.first+step,f.second)) == 0) {
				Q.push(make_pair(f.first+step,f.second));
				tab[make_pair(f.first+step,f.second)] = sofar + "E";
				jump[make_pair(f.first+step,f.second)] = step;
//				cout << "Reaches (" << f.first+step << "," << f.second << ") with path = " << sofar + "E" << " in " << step << " steps" << endl;
			}
			if(tab.count(make_pair(f.first-step,f.second)) == 0) {
				Q.push(make_pair(f.first-step,f.second));
				tab[make_pair(f.first-step,f.second)] = sofar + "W";
				jump[make_pair(f.first-step,f.second)] = step;
//				cout << "Reaches (" << f.first-step << "," << f.second << ") with path = " << sofar + "W" << " in " << step << " steps" << endl;
			}
			if(tab.count(make_pair(f.first,f.second+step)) == 0) {
				Q.push(make_pair(f.first,f.second+step));
				tab[make_pair(f.first,f.second+step)] = sofar + "N";
				jump[make_pair(f.first,f.second+step)] = step;
//				cout << "Reaches (" << f.first << "," << f.second+step << ") with path = " << sofar + "N" << " in " << step << " steps" << endl;
			}
			if(tab.count(make_pair(f.first,f.second-step)) == 0) {
				Q.push(make_pair(f.first,f.second-step));
				tab[make_pair(f.first,f.second-step)] = sofar + "S";
				jump[make_pair(f.first,f.second-step)] = step;
//				cout << "Reaches (" << f.first << "," << f.second-step << ") with path = " << sofar + "S" << " in " << step << " steps" << endl;
			}

//			cout << "Now we checked for all steps of length = " << step << endl;
		}

		cout << "Case #" << t <<": " << res << endl;
	}
	return 0;
}




