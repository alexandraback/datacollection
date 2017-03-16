#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

#define FOR(i, a, b) for (int i(a), _b(b); i <= _b; ++i)
#define REP(i, n) for (int i(0), _n(n); i < _n; ++i)

struct city{
	string zip;
	vector<int> cango;
	int starting, outbound, were;
	vector<int> returning;
	city(){
		zip = "";
		starting = outbound = were = 0;
		returning.clear();
		cango.clear();
	}
};

vector<city> mp;

inline int fnd(const vector<int> &v, int n){
	REP(i, v.size()){
		if(v[i] == n){
			return i;
		}
	}
	return -1;
}
int cmp(string s1, string s2){
	if(s1.size() < s2.size())return -1;
	if(s1.size() > s2.size())return 1;
	return s1.compare(s2);
}

string getstr(vector<city> mp, int cur){
	string ret, ts;
	int togo, ti, good;

	ret = "-";
	mp[cur].were++;

	good = 1;
	FOR(i, 1, mp.size() - 1){
		if(!mp[i].were){
			good = 0;
			break;
		}
	}
	if(good) return mp[cur].zip;

	REP(i, mp[cur].cango.size()){
		togo = mp[cur].cango[i];
		if((mp[togo].outbound == 0) && (mp[togo].starting == 0)){
			mp[togo].outbound = 1;
			mp[cur].returning.push_back(togo);
			ts = getstr(mp, togo);
			mp[cur].returning.pop_back();
			mp[togo].outbound = 0;
			if(ts != "-") {if(ret == "-") {ret = ts; } else { if(cmp(ts, ret) < 0) ret = ts; }}
		}
		ti = fnd(mp[togo].returning, cur);
		if(ti > -1 ){
			mp[togo].returning.erase(mp[togo].returning.begin() + ti);
			ts = getstr(mp, togo);
			mp[togo].returning.push_back(cur);
			if(ts != "-") {if(ret == "-") {ret = ts; } else { if(cmp(ts, ret) < 0) ret = ts; }}
		}
	}

	if(ret == "-") return "-";
	if(mp[cur].were == 1) return mp[cur].zip + ret;
	return ret;
}

int main(void){
	int T, n, m, f,d;
	string ans, best;

	ifstream fin("C-small-attempt0 (1).in");
	ofstream fout("out.txt");
	fin >> T;
	REP(t, T){
		fout << "Case #" << t+1 << ": ";
		cout << "Case #" << t+1 << ": ";

		mp.clear();
		fin >> n >> m;
		mp.resize(n+1);
		FOR(i, 1, n){
			fin >> mp[i].zip;
		}
		REP(i, m){
			fin >> f >> d;
			mp[f].cango.push_back(d);
			mp[d].cango.push_back(f);
		}

		best = "-";
		FOR(i, 1, n){
			mp[i].starting = 1;
			ans = getstr(mp, i);
			if(ans!= "-"){
				if(best == "-") {
					best = ans;
				} else {
					if(cmp(best, ans) > 0) best = ans;
				}
			}
			mp[i].starting = 0;
		}

		fout << best << endl;
		cout << best << endl;
	}
system("pause");
	fout.close();
	return 0;
}
