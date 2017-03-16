#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <unordered_set>
#include <map>
#include <fstream>

#define MODN 1000000007

using namespace std;

int T, N;
int main()
{
	string filename = "B-small-attempt2";
	ifstream fin(filename + ".in");
	FILE *fout = fopen((filename + ".out").c_str(), "w");

	fin >> T;
	for(int t = 1; t <= T; t++)
	{
		string trs[101] = {""};
		fin >> N;
		for(int i = 0; i < N; i++) {
			fin >> trs[i];
		}
		sort(trs, trs + N);

		int grsc = 0;
		unordered_set<char> grs[101];
		for(int i = 0; i < 101; i++) {
			grs[i] = unordered_set<char>();
		}

		for(int i = 0; i < N; i++) {
			for(int k = 0; k < 101; k++) {
				if(grs[k].size() == 0) {
					for(int j = 0; j < trs[i].length(); j++) {
						grs[k].insert(trs[i][j]);
					}
					grsc++;
					break;
				}
				else{
					for(int j = 0; j < trs[i].length(); j++) {
						if(grs[k].find(trs[i][j]) != grs[k].end()) {
							for(int l = 0; l < trs[i].length(); l++) {
								grs[k].insert(trs[i][l]);
							}
							k = 101;
							break;
						}
					}
				}
			}
		}

		long long fac[101] = {0};
		fac[0] = 1;
		for(int i = 1; i < 101; i++) {
			fac[i] = fac[i - 1] * i;
			fac[i] %= MODN;
		}

		bool ws[26][2];
		for(int i = 0; i < 26; i++) {
			for(int j = 0; j < 2; j++) {
				ws[i][j] = false;
			}
		}
		long long bc[26] = {0};
		bool ic[26] = {false};

		bool work = true;
		for(int i = 0; i < N; i++) {
			bool bloc = true;
			char ss = trs[i][0];
			char se = trs[i][trs[i].length() - 1];
			for(int j = 0; j < trs[i].length(); j++) {
				if(trs[i][j] != ss) {
					bloc = false;
					break;
				}
			}

			if(bloc) {
				bc[ss - 'a']++;
			}
			else {
				int cc = 1;
				while(cc < trs[i].length() && trs[i][cc] == ss) {
					cc++;
				}

				int ec = trs[i].length() - 1;
				while(ec >= 0 && trs[i][ec] == se) {
					ec--;
				}
				if(cc <= ec) {
					char cChar = trs[i][cc];
					for(int j = cc; j <= ec; j++) {
						if(ic[trs[i][j] - 'a']) {
							work = false;
							// printf("1 %d:%d %c %c --- %s\n", t, cc, ss, trs[i][j], trs[i].c_str());
							// cout << "NOT WORKING" << endl;
							i = N;
							break;
						}
						else if(trs[i][j] != cChar) {
							ic[cChar - 'a'] = true;
							cChar = trs[i][j];
						}
					}
					ic[cChar - 'a'] = true;
				}

				if(work) {
					if(!ws[ss - 'a'][0]) {
						ws[ss - 'a'][0] = true;
					}
					else {
						work = false;
							// printf("2 %d: %s\n", t, trs[i].c_str());
							// cout << "NOT WORKING" << endl;
						break;
					}

					if(!ws[se - 'a'][1]) {
						ws[se - 'a'][1] = true;
					}
					else {
						work = false;
							// printf("3 %d: %s\n", t, trs[i].c_str());
							// cout << "NOT WORKING" << endl;
						break;
					}					
				}
			}
		}

		long long count = work;
		if(work) {
			for(int i = 0; i < 26; i++) {
				// if(bc[i]){
				// 	printf("%d: bc[%d]: %d -> %d * %d\n", t, i, bc[i], fac[bc[i]], count);
				// }
				count *= fac[bc[i]];
				count %= MODN;			
			}
			// printf("%d: grsc: %d -> %d * %d\n", t, grsc, fac[grsc], count);

			count *= fac[grsc];
			count %= MODN;
		}
		fprintf(fout, "Case #%d: %d\n", t, count);
	}

	fin.close();
	fclose(fout);
 	return 0;
}