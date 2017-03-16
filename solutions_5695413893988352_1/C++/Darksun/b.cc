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

void dfs(long long i, string ret){
	//cout << i << ' ' << ret << endl;
	if (i == ret.size()){
		string tc, tj;
		for (long long j = 0; j < ret.size() / 2; j ++){
			tc += ret[j];
		}
		for (long long j = ret.size() / 2; j < ret.size(); j++){
			tj += ret[j];
		}
		stringstream ss;
		ss << tc << " " << tj;
		long long sc, sj;
		ss >> sc >> sj;
		//cout << tc << ' ' << tj << ' ' << sc << ' ' << sj << endl;
		long long nd = abs(sc - sj);
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
	for (long long j = 0; j < 10; j++){
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

long long getdiff(string sa, string sb){
	stringstream ss;
	long long a, b;
	ss << sa << ' ' << sb;
	ss >> a >> b;
	return abs(a - b);	
}

void gao(){
	long long n = cs.size();
	cans = cs;
	jans = js;
	for (long long i = 0; i < n; i++){
		if (cans[i] == '?' && jans[i] == '?'){
			cans[i] = jans[i] = '0';
			continue;
		}
		if (cans[i] == '?' && jans[i] != '?'){
			cans[i] = jans[i];
			continue;
		}
		if (cans[i] != '?' && jans[i] == '?'){
			jans[i] = cans[i];
			continue;
		}
		if (cans[i] == jans[i]) continue;
		
		if (cans[i] > jans[i]){
			for (long long j = i + 1; j < n; j++){
				if (cans[j] == '?') cans[j] = '0';
				if (jans[j] == '?') jans[j] = '9';
			}
			string ttc = cans, ttj = jans;			
			long long diff = getdiff(cans, jans);
			for (long long j = i; j >= 0; j--){
				if (js[j] == '?' && cans[j] != '9'){
					string tc = cans.substr(0, j+1);
					string tj = jans.substr(0, j);
					tj += char(cans[j] + 1);
					for (long long k = j + 1; k < n; k++){
						if (cs[k] == '?') tc += '9'; else tc += cs[k];
						if (js[k] == '?') tj += '0'; else tj += js[k];
					}
					long long d2 = getdiff(tc, tj);
					if (d2 < diff || d2 == diff && tc < cans
					|| d2 == diff && tc == cans && tj < jans){
						diff = d2; cans = tc; jans = tj;
					}
					break;
				}
			}

			for (long long j = i; j >= 0; j--){
				if (cs[j] == '?' && ttj[j] != '0'){
					string tc = ttc.substr(0, j);
					string tj = ttj.substr(0, j+1);
					tc += char(ttj[j] - 1);
					for (long long k = j + 1; k < n; k++){
						if (cs[k] == '?') tc += '9'; else tc += cs[k];
						if (js[k] == '?') tj += '0'; else tj += js[k];
					}
					//cout << tc << ' ' << tj << endl;
					long long d2 = getdiff(tc, tj);
					if (d2 < diff || d2 == diff && tc < cans
					|| d2 == diff && tc == cans && tj < jans){
						diff = d2; cans = tc; jans = tj;
					}
					break;
				}
			}
			return;
		}
		
		if (cans[i] < jans[i]){
			for (long long j = i + 1; j < n; j++){
				if (cans[j] == '?') cans[j] = '9';
				if (jans[j] == '?') jans[j] = '0';
			}
			string ttc = cans, ttj = jans;
			long long diff = getdiff(cans, jans);
			for (long long j = i; j >= 0; j--){
				if (cs[j] == '?' && jans[j] != '9'){
					string tc = cans.substr(0, j);
					string tj = jans.substr(0, j+1);
					tc += char(jans[j] + 1);
					for (long long k = j + 1; k < n; k++){
						if (cs[k] == '?') tc += '0'; else tc += cs[k];
						if (js[k] == '?') tj += '9'; else tj += js[k];
					}
					long long d2 = getdiff(tc, tj);
					if (d2 < diff || d2 == diff && tc < cans
						|| d2 == diff && tc == cans && tj < jans){
						diff = d2; cans = tc; jans = tj;
					}
					break;
				}
			}

			for (long long j = i; j >= 0; j--){
				if (js[j] == '?' && ttc[j] != '0'){
					string tc = ttc.substr(0, j+1);
					string tj = ttj.substr(0, j);
					tj += char(ttc[j] - 1);
					for (long long k = j + 1; k < n; k++){
						if (cs[k] == '?') tc += '0'; else tc += cs[k];
						if (js[k] == '?') tj += '9'; else tj += js[k];
					}
					long long d2 = getdiff(tc, tj);
					if (d2 < diff || d2 == diff && tc < cans
					|| d2 == diff && tc == cans && tj < jans){
						diff = d2; cans = tc; jans = tj;
					}
					break;
				}
			}
			return;
		}
	}
}

int main(){
	long long tt; cin >> tt;
	for (long long cas = 1; cas <= tt; cas++){
		cout << "Case #" << cas << ":" << ' ';
		cin >> cs >> js;
		cans = jans = "";
		gao(); 
		//brute();
		cout << cans << ' ' << jans << endl;
	}
	return 0;
}