#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

#define forn(i,n) for (int i = 0; i < (int)(n); i++)

ifstream fin("b.in");
ofstream fout("b.out");

#define NO 0
#define COUNTING 1
#define ENDED 2

int main() {
	int T, N;
	fin >> T;
	//cout << T << endl;
	forn(icase,T) {
		cout << "Case #" << (icase+1) << ": ";
		fout << "Case #" << (icase+1) << ": ";
		
		fin >> N;
		vector<string> s(N);
		forn(i,N) {
			fin >> s[i];
			// compressing
			string stmp;
			stmp = s[i][0];
			for (int j = 1; j < s[i].size(); j++) {
				if (s[i][j] != stmp[stmp.size()-1]) stmp += s[i][j];
			}
			s[i] = stmp;
			s[i] += ('a'+i);
			//cout << s[i] << " ";
		}
		
		//cout << endl;
		
		bool used[26];
		string cused;
		forn(i,26) used[i] = false;
		forn(i,N) forn(j,s[i].size()-1) {
			if (!used[s[i][j]-'a']) cused += s[i][j];
			used[s[i][j]-'a'] = true;
		}
		
		sort(s.begin(), s.end());
		int cnt = 0;
		//int PEPE = 0;
		do {
			//if (PEPE % 10000 == 0) cout << PEPE << endl;
			//PEPE++;
			
			string st = "";
			forn(i,N) forn(j,s[i].size()-1) st += s[i][j];
			
			//cout << st << endl;
			
			bool valid = true;
			forn(i,cused.size()) {
				int flag = NO;
				forn(j,st.size()) {
					if (st[j] == cused[i]) {
						if (flag == NO) {
							flag = COUNTING;
						} else if (flag == ENDED) {
							valid = false;
							break;
						}
					} else {
						if (flag == COUNTING) flag = ENDED;
					}
				}
				if (!valid) break;
			}
			if (valid) {
				cnt++;
				//cout << st << endl;
			}
			
		} while(next_permutation(s.begin(), s.end()));
		cout << cnt << endl;
		fout << cnt << endl;
	}
	cout << "Done" << endl;
	
	return 0;
}
