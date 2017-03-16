#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

typedef long long LL;

vector<LL> rebuild(map<LL,LL> M, LL x) {
	vector<LL> ret;
	while (x>0) {
		LL p = M[x];
		ret.push_back(x-p);
		x = p;
	}
	return ret;
}

int main() {
	int T;
	cin >> T;


	for (int t=1; t<=T; t++) {
		int N;
		cin >> N;
		vector<LL> v;
		v.resize(N);
		for (int i=0; i<N; i++) 
			cin >> v[i];
		sort(v.begin(), v.end());
/*		for (int i=0; i<N; i++)  {
			cout << v[i]<<" ";
		}
		cout<<endl;*/

		map<LL,LL> M;
		M[0]=-1;

		bool found = 0; vector<LL> s0,s1;
		for (size_t i=0; !found && i<N; i++) {
			LL x = v[i];
//			cout<<"----- x="<<x<<endl;

			set<LL> keys;
//			cout<<"keys";
			for (map<LL,LL>::iterator it = M.begin(); it!=M.end(); ++it) {
				keys.insert(it->first);
			}


			for (set<LL>::iterator it = keys.begin(); !found && it!=keys.end(); ++it) {
				LL sum = x+*it;
//				cout<<" add "<<x<<" to set "<<*it<<" sum="<<sum<<endl;
				if (M.find(sum)==M.end()) {
					M[sum] = *it;
				} else{
//					cout<<" already exists set!"<<sum<<endl;
					s0 = rebuild(M,sum);
					M[sum] = *it;
					s1 = rebuild(M,sum);
					found = 1;
				}
			}
		}

		cout << "Case #" << t << ":" << endl;
		if (found) {
			for (int i=0; i<s0.size(); i++) {
				cout<<s0[i];
				if (i<s0.size()-1) cout<<" ";
			}
			cout<<endl;
			for (int i=0; i<s1.size(); i++) {
				cout<<s1[i];
				if (i<s1.size()-1) cout<<" ";
			}
			cout<<endl;
		} else {
			cout << "Impossible" <<endl;
		}
	}


}