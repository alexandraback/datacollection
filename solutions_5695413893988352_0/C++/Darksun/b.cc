#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>

using namespace std;

string cs, js;
string cans, jans;

long long diff;

void dfs(int i, string ret){
	//cout << i << ' ' << ret << endl;
	if (i == ret.size()){
		string tc, tj;
		for (int j = 0; j < ret.size() / 2; j ++){
			tc += ret[j];
		}
		for (int j = ret.size() / 2; j < ret.size(); j++){
			tj += ret[j];
		}
		stringstream ss;
		ss << tc << " " << tj;
		int sc, sj;
		ss >> sc >> sj;
		//cout << tc << ' ' << tj << ' ' << sc << ' ' << sj << endl;
		int nd = abs(sc - sj);
		if (nd < diff 
		|| (nd == diff && tc < cans)
		|| (nd == diff && tc == cans && tj < jans)){
			diff = nd;
			cans = tc;
			jans = tj;
		}
		return;
	}
	if (ret[i] != '?'){
		dfs(i+1, ret);
		return;
	}
	for (int j = 0; j < 10; j++){
		ret[i] = char(j + '0');
		dfs(i+1, ret);
	}
}

void brute(){
	diff = 1ll << 60;
	cans = cs;
	jans = js;
	dfs(0, cs+js);
}

int main(){
	int tt; cin >> tt;
	for (int cas = 1; cas <= tt; cas++){
		cout << "Case #" << cas << ":" << ' ';
		cin >> cs >> js;
		cans = jans = "";
		brute();
		cout << cans << ' ' << jans << endl;
	}
	return 0;
}