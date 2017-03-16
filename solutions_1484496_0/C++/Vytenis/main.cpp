#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

typedef vector <string> vs;
typedef vector <int> vi;
#define REP(a,b) for(int a=0;a<(b);++a)
#define FOR(a,c,b) for(int a=c;a<(b);++a) 

vector <int> num;
vector <int> res1, res2;
int n;

bool go(int pos, int s1, int s2)
{
	if (s1 == s2 && s1 > 0) return true;
	if (pos >= n) return false;

	res1.push_back(num[pos]);
	if (go(pos+1, s1+num[pos], s2)) return true;
	res1.pop_back();
	res2.push_back(num[pos]);
	if (go(pos+1, s1, s2+num[pos])) return true;
	res2.pop_back();
	if (go(pos+1, s1, s2)) return true;

	return false;
}



int main() 
{
	ifstream fin("C-small-attempt0.in");
	//ifstream fin("C-large.in");
	//ifstream fin("c.in");
	ofstream fout("c.out");

	int tc;

	fin >> tc;

	REP(tcase,tc) {
		fout << "Case #" << tcase+1 << ":" << endl;

		fin >> n;

		num.resize(n);
		REP(i,n) {
			fin >> num[i];
		}

		sort(num.rbegin(), num.rend());

		res1.clear(); res2.clear();
		go(0, 0, 0);

		if (res1.size() == 0) fout << "Impossible" << endl;
		else {
			fout << res1[0];
			FOR(i,1,res1.size()) fout << " " << res1[i];
			fout << endl;
			fout << res2[0];
			FOR(i,1,res2.size()) fout << " " << res2[i];
			fout << endl;
		}
	}

	fout.close();

	return 0;
}