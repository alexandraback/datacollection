#define _CRT_SECURE_NO_DEPRECATE
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <map>
#include <list>
#include <sstream>
#include <algorithm>
#include <vector>
#include <bitset>
#include <iomanip>
#include <queue>
#include <set>	
#include <cstring>
using namespace std;
typedef long long		ll;
typedef pair<int, int>	ii;
typedef pair<ii, int>	iii;
typedef vector<ii>		vii;
typedef vector<iii>		viii;
typedef vector<int>		vi;
typedef vector<char>	vc;
typedef vector<vc>		vvc;
typedef vector<string>	vs;
typedef unsigned long long	ull;
typedef vector<ull>		vul;
typedef vector<bool>	vb;
typedef vector<vi>		vvi;
typedef vector<vii>		vvii;
typedef vector<double>	vd;
#define INF 1000000000
#define PI 3.14159265


bool isCons(char c) {
	return (c!='a' && c!='e' && c!='i' && c!='o' && c!='u');
}


int main(int argc, char *argv[]){
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);

	int T;
	cin >> T;
	for (int t=1; t<=T; t++) {
		int N;
		cin >> N;
		vi d(N), n(N), w(N), e(N), s(N), delta_d(N), delta_p(N), delta_s(N);
		for (int i=0; i<N; i++){ 
			cin >> d[i] >> n[i] >> w[i] >> e[i] >> s[i] >> delta_d[i] >> delta_p[i] >> delta_s[i];
		}

		// put attacks in sequence
		map<int, vector < pair < int, pair <int, int> > > > seq;

		// each tribe
		for (int i=0; i<N; i++) {
			int tempW = w[i];
			int tempE = e[i];
			int tempS = s[i];
			int tempD = d[i];
			// each attack
			for (int k=0; k<n[i]; k++) {
				pair<int, int> tempP(tempW,tempE);
				pair<int, pair<int, int>> tempPP(tempS,tempP);
				seq[tempD].push_back(tempPP);
				
				tempD += delta_d[i];
				tempW += delta_p[i];
				tempE += delta_p[i];
				tempS += delta_s[i];
			}
		}

		map<int,int> height;
		int totalAttacks = 0;
		// check
		for (map<int,vector<pair<int,pair<int,int>>>> :: iterator it=seq.begin(); it!=seq.end(); it++) {
			int day = (*it).first;
			//cout << "day " << (*it).first << endl; 
			for (vector< pair < int, pair <int, int> > >:: iterator itV=(*it).second.begin(); itV!=(*it).second.end(); itV++) {
				int west = (*itV).second.first;
				int east = (*itV).second.second;
				int strength = (*itV).first;
				//cout << "w e s : (" << (*itV).second.first << ", " << (*itV).second.second << ") " << (*itV).first << endl;

				// attack!
				for (int i=west; i<east; i++){
					if (height[i] < strength) {
						totalAttacks ++;
						i = east;
						//cout << "Attacked: " << day << " " << west  << " "<< east << " " << strength << endl;
					}
				}
			}


			// end of the day

			for (vector< pair < int, pair <int, int> > >:: iterator itV=(*it).second.begin(); itV!=(*it).second.end(); itV++) {
				int west = (*itV).second.first;
				int east = (*itV).second.second;
				int strength = (*itV).first;
				//cout << "w e s : (" << (*itV).second.first << ", " << (*itV).second.second << ") " << (*itV).first << endl;
				

				// restore!
				for (int i=west; i<east; i++){
					if (height[i] < strength) {
						height[i] = strength;
					}
				}
			}
		}
		
		cout << "Case #"<<t <<": " << totalAttacks << endl;

	}



	return EXIT_SUCCESS;
}