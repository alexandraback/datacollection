#include<iostream>
#include<string>
#include<map>
#include<algorithm>
#include<set>
#include<cmath>
#include<stdio.h>
#include<utility>
#include<queue>
#include<stack>
#include<deque>
#include<string.h>
using namespace std;

int main()
{
	int t;
	cin >> t;
	int n;
	string first, second;
	//return 0;
	for(int z = 1; z <= t; ++ z){
		cin >> n;
		vector<string> firsts, seconds;
		int ret = 0;
		for(int i = 0; i < n; ++ i){
			cin >> first >> second;
			firsts.push_back(first);
			seconds.push_back(second);
		}
		for(int i = 1; i < (1 << n); ++ i){
			vector<int> orig, fakes;
			int mult = 1;
			for(int j = 0; j < n; ++ j){
				if(mult&i){
					orig.push_back(j);
				}
				else fakes.push_back(j);
				mult *= 2;
			}
			//cout << fakes.size() + orig.size() << ' ' << n << endl;
			set<string> origFirsts, origSeconds;
			bool can = true;
			for(int j = 0; j < orig.size(); ++ j){
				int sz = origFirsts.size(), sz1 = origSeconds.size();
				origFirsts.insert(firsts[orig[j]]);
				origSeconds.insert(seconds[orig[j]]);
				if(sz == origFirsts.size() && origSeconds.size() == sz1){
					can = false;
					break;
				}
			}
			if(!can) continue;
			for(int j = 0; j < fakes.size(); ++ j){
				int sz = origFirsts.size(), sz1 = origSeconds.size();
				if(origFirsts.find(firsts[fakes[j]]) == origFirsts.end() || origSeconds.find(seconds[fakes[j]]) == origSeconds.end()){
					can = false;
					break;
				}
			}
			if(can){
			ret = max(ret, (int)fakes.size());
			}
		}
		cout << "Case #" << z << ": " << ret << endl;
	}
	return 0;
}