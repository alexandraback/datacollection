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

void solve(int pos) {
	if (pos==10) return;
	bool fl = true;
	int totalusedo = totalused;
	vector<int> usedo = used;
	vector<int> confo = conf;
	while (fl) {
		solve(pos+1);
		if (totalused==number.size()) return;
		rep(i,letts[pos].size()) {
			bool find = false;
			rep(j,number.size())
				if (!used[j] && number[j]==letts[pos][i]) { find = true; used[j] = 1; totalused++; break; }
			if (!find) { fl = false; break; }
		}
		if (!fl) {
			used = usedo;
			conf = confo;
			totalused = totalusedo;
		}
		else {
			conf[pos]++;
		}
	}
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
	
	fstream fin("A-small-attempt0.in",ifstream::in);
    fstream fout("A-small-attempt0.out",ofstream::out);
    fin >> T;
	for(int tc=1;tc<=T;tc++)
    {
		fin >> number;
		used.resize(number.size());
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
