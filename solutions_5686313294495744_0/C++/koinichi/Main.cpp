#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool makeable(pair<string, string> p, vector<pair<string, string> > &listed)
{
	int l_s = listed.size();
	bool first = false, second = false;
	for (int i=0; i<l_s; i++) {
		if (p == listed[i]) { return false; }
		if (p.first == listed[i].first) { first = true; }
		if (p.second == listed[i].second) { second = true; }
		if (first && second) { break; }
	}
	return first && second; 
}

int check(int n, int mask, vector<pair<string, string> > s)
{
	vector<pair<string, string> > fakes, listed;
	int ret = 0;
	for (int i=0; i<n; i++) {
		ret += mask&1;
		if (mask&1) { fakes.push_back(s.back()); }
		else { listed.push_back(s.back()); }
		s.pop_back();
		mask >>= 1;
	}
	

	int f_s = fakes.size();
	for (int i=0; i<f_s; i++) {
		if (!makeable(fakes[i], listed)) {
			return 0;
		}
	}

	return ret;
}


int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);


	int _n;
	cin >> _n;

	for (int _t=1; _t<=_n; _t++) {
		int n, ret = 0;
		vector<pair<string, string> > s;
		cin >> n;
		for (int i=0; i<n; i++) {
			string a,b;
			cin >> a >> b;
			s.push_back(make_pair(a,b));
		}
		int mask_max = 1 << n;
		for (int i=1; i<mask_max; i++) {
			int count = check(n, i, s);
			if (ret < count) {
				ret = count;
			}
		}
		cout << "Case #" << _t << ": " << ret << endl;
	}
}
