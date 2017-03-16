#include <bits/stdc++.h>

using namespace std;

set<string> f, s;
vector<pair<string, string> > v;
int main(void) {

	ifstream fin;
	ofstream fout;
	fin.open("C-small-attempt0.in");
	fout.open("output.out");

	int tt;
	fin>>tt;
	for(int t = 1; t <= tt; ++t) {
		cout<<t<<endl;
		v.clear();
		int n;
		fin>>n;
		for(int i = 0; i < n; ++i) {
			string a, b;
			fin>>a>>b;
			v.push_back(make_pair(a, b));
		}
		int ans = 0;
		for(int i = 0; i < (1<<n); ++i) {
			f.clear();
			s.clear();
			int tot = 0;
			for(int j = 0; j < n; ++j) {
				if(i&(1<<j)) {
					f.insert(v[j].first);
					s.insert(v[j].second);
					tot++;
				}
			}
			bool flag = true;
			for(int j = 0; j < n; ++j) {
				if(!(i&(1<<j))) {
					string a = v[j].first;
					string b = v[j].second;
					if((f.find(a) == f.end()) || (s.find(b) == s.end())) {
						flag = false;
						break;
					}
				}
			}
			if(flag)	ans = max(ans, n-tot);
		}


		fout<<"Case #"<<t<<": "<<ans<<"\n";

	}




	fin.close();
	fout.close();
	return 0;
}

