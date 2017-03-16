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

vector<string> letts;

string number;
int totalused = 0;
vector<int> used;
vector<int> conf(10, 0);

vector<int> cnt(10, 0);

void solve(int pos) {
	if (pos==10) return;
	bool fl = true;
	int totalusedo = totalused;
	vector<int> usedo = used;
	vector<int> confo = conf;
	vector< vector<int> > tpos(0);
	while (fl) {
		tpos.push_back(vector<int>(0));
		if (cnt[pos]!=-1 && tpos.size()==cnt[pos]+1) break;
		rep(i,letts[pos].size()) {
			bool find = false;
			rep(j,number.size())
				if (!used[j] && number[j]==letts[pos][i]) { 
					find = true; 
					//used[j] = 1; 
					//totalused++; 
					tpos[tpos.size()-1].push_back(j);
					break; 
				}
			if (!find) { fl = false; break; }
		}
		if (fl) {
			rep(i,tpos[tpos.size()-1].size()) {
				used[tpos[tpos.size()-1][i]] = 1;
				totalused++;
			}
			conf[pos]++;
		}
		//else tpos.resize(tpos.size()-1);
	}

	if (tpos.size()<cnt[pos]+1) {
		used = usedo;
		conf = confo;
		totalused = totalusedo;
		return;
	}

	for(int tn=tpos.size()-2;tn>=0;tn--) {
		solve(pos+1);
		if (totalused==number.size()) return;

		if (tpos.size()==cnt[pos]+1) {
			used = usedo;
			conf = confo;
			totalused = totalusedo;
			return;
		}

		rep(i, tpos[tn].size()) {
			used[tpos[tn][i]] = 0;
			totalused--;
		}
		conf[pos]--;
	}
	solve(pos+1);
	if (totalused==number.size()) return;
	used = usedo;
	conf = confo;
	totalused = totalusedo;
	return;
}

int main()
{
	letts.resize(10);
	letts[0] = "ZERO";
	letts[1] = "ONE";
	letts[2] = "TWO";
	letts[3] = "THREE"; 
	letts[4] = "FOUR";
	letts[5] = "FIVE";
	letts[6] = "SIX";
	letts[7] = "SEVEN";
	letts[8] = "EIGHT";
	letts[9] = "NINE";
	
	fstream fin("A-large.in",ifstream::in);
    fstream fout("A-large.out",ofstream::out);
    fin >> T;
	for(int tc=1;tc<=T;tc++)
    {
		cout << tc << "\n";
		fin >> number;
		used.resize(number.size());

		rep(i, cnt.size()) cnt[i] = -1;

		int tcnt = 0;
		rep(i,number.size())
			if (number[i]=='Z') tcnt++;
		cnt[0] = tcnt;

		tcnt = 0;
		rep(i,number.size())
			if (number[i]=='W') tcnt++;
		cnt[2] = tcnt;

		tcnt = 0;
		rep(i,number.size())
			if (number[i]=='U') tcnt++;
		cnt[4] = tcnt;

		tcnt = 0;
		rep(i,number.size())
			if (number[i]=='X') tcnt++;
		cnt[6] = tcnt;

		tcnt = 0;
		rep(i,number.size())
			if (number[i]=='G') tcnt++;
		cnt[8] = tcnt;


		totalused = 0;
		rep(i,used.size()) used[i] = 0;
		rep(i,conf.size()) conf[i] = 0;
		solve(0);
		fout << "Case #" << tc << ": ";// << ret << "\n";
		for(int i=0;i<10;++i) {
			for(int j=0;j<conf[i];++j)
				fout << i;
		}
		fout << "\n";
    }
    fin.close();
    fout.close();
    cout << "running time=" << clock()/(double)CLOCKS_PER_SEC << "\n";
    //system("PAUSE");
    return 0;
}
