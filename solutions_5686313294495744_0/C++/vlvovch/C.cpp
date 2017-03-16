#include <cstdio>
#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <ctime>
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;

int T;
int N;
vector<string> firsts, seconds;
vector<string> ford, sord;

vector<int> used;
map<string, int> fcnt, scnt;
map<string, int> totfcnt, totscnt;

int ret = 0;

void FillFakes() {
	rep(i,N)
		if (!used[i]) {
			if (fcnt.count(firsts[i])!=0 && scnt.count(seconds[i])!=0) {
				ret++;
				used[i] = 1;
				ford.push_back(firsts[i]);
				sord.push_back(seconds[i]);

				if (fcnt.count(firsts[i])==0) fcnt[firsts[i]] = 0;
				fcnt[firsts[i]]++;

				if (scnt.count(seconds[i])==0) scnt[seconds[i]] = 0;
				scnt[seconds[i]]++;
			}
		}
}

int main()
{
    fstream fin("C-small-attempt1.in",ifstream::in);
    fstream fout("C-small-attempt1.out",ofstream::out);
    fin >> T;
	for(int tc=1;tc<=T;tc++)
    {
		fin >> N;
		firsts.resize(N);
		seconds.resize(N);
		ford.resize(0);
		sord.resize(0);
		fcnt.clear();
		scnt.clear();
		totfcnt.clear();
		totscnt.clear();
		ret = 0;
		rep(i,N) {
			fin >> firsts[i] >> seconds[i];
			if (totfcnt.count(firsts[i])==0) totfcnt[firsts[i]] = 0;
			totfcnt[firsts[i]]++;

			if (totscnt.count(seconds[i])==0) totscnt[seconds[i]] = 0;
			totscnt[seconds[i]]++;
		}
		used.resize(N);
		rep(i,N) used[i] = 0;

		rep(i,N) {
			if (totfcnt[firsts[i]]==1 || totscnt[seconds[i]]==1) {
				used[i] = 1;
				ford.push_back(firsts[i]);
				sord.push_back(seconds[i]);

				if (fcnt.count(firsts[i])==0) fcnt[firsts[i]] = 0;
				fcnt[firsts[i]]++;

				if (scnt.count(seconds[i])==0) scnt[seconds[i]] = 0;
				scnt[seconds[i]]++;
			}
		}

		FillFakes();

		while (ford.size()<firsts.size()) {
			bool fl = false;
			rep(i,N) {
				if (!used[i]) {
					if (fcnt.count(firsts[i])==0 && scnt.count(seconds[i])==0) {
						fl = true;
						used[i] = 1;
						ford.push_back(firsts[i]);
						sord.push_back(seconds[i]);

						if (fcnt.count(firsts[i])==0) fcnt[firsts[i]] = 0;
						fcnt[firsts[i]]++;

						if (scnt.count(seconds[i])==0) scnt[seconds[i]] = 0;
						scnt[seconds[i]]++;
						break;
					}
				}
			}

			if (!fl) {
				rep(i,N) {
					if (!used[i]) {
						//if (fcnt.count(firsts[i])==0 && scnt.count(seconds[i])==0) 
						{
							fl = true;
							used[i] = 1;
							ford.push_back(firsts[i]);
							sord.push_back(seconds[i]);

							if (fcnt.count(firsts[i])==0) fcnt[firsts[i]] = 0;
							fcnt[firsts[i]]++;

							if (scnt.count(seconds[i])==0) scnt[seconds[i]] = 0;
							scnt[seconds[i]]++;
							break;
						}
					}
				}
			}

			FillFakes();
		}


		fout << "Case #" << tc << ": " << ret << "\n";
    }
    fin.close();
    fout.close();
    cout << "running time=" << clock()/(double)CLOCKS_PER_SEC << "\n";
    //system("PAUSE");
    return 0;
}
