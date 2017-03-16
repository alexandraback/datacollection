#include <iostream>
#include <vector>
#include <map>
using namespace std;

#define PII pair<int,int>
#define MK make_pair

int main(int argc, char *argv[]) {
	int t1, t2;
	cin >> t1;
	t2 = t1;
	while(t2--) {
		cout << "Case #" << t1 - t2 << ": ";
		int desx, desy;
		cin >> desx >> desy;
		PII des(desx, desy);
		vector<PII> pos;
		vector<PII> trace;
		vector<int> step;
		map<PII, bool> reach;
		reach[MK(0, 0)] = true;
		pos.push_back(MK(0, 0));
		trace.push_back(MK(0, 0));
		step.push_back(1);
		int i = 0;
		bool find = false;
		while(1) {
			PII cur = pos[i];
			PII new_pos[4];
			new_pos[0] = cur; new_pos[0].first += step[i];
			new_pos[1] = cur; new_pos[1].second -= step[i];
			new_pos[2] = cur; new_pos[2].first -= step[i];
			new_pos[3] = cur; new_pos[3].second += step[i];
			for(int k = 0; k < 4; k++) {
				if(!reach[new_pos[k]]) {
					reach[new_pos[k]] = true;
					pos.push_back(new_pos[k]);
					step.push_back(step[i] + 1);
					trace.push_back(MK(i, k));
					if(des == new_pos[k]) {
						find = true;
						break;
					}
				}
			}
			if(find) break;
			++i;
		}
		i = trace.size() - 1;
		string ans = "";
		while(i) {
			PII t = trace[i];
			i = t.first;
			switch (t.second) {
				case 0: ans += 'E';	break;
				case 1: ans += 'S';	break;
				case 2: ans += 'W';	break;
				case 3: ans += 'N';	break;
			}
		}
		for(int x = ans.length() - 1; x >= 0; --x) cout << ans[x];
		cout << endl;
	}
	return 0;
}
