#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

int main() {

	int T, S, N, p;
	vector<int> v;
	cin >> T;
	for(int i=1; i<=T; i++) {
		cin>>N>>S>>p;
		v.clear();
		for(int j=0; j<N; j++) {
			int t;
			cin>>t;
			v.push_back(t);
		}
		cout<<"Case #"<<i<<": ";

		sort(v.begin(), v.end());	

		reverse(v.begin(), v.end());

		int ret=0;
		for(int i=0; i<(int)v.size(); i++) {
			if (v[i]>=p+2*max(p-1,0)) {
				ret++;
			} else if(v[i]<p+2*max(p-2,0)) {
				break;
			} else {
				if (S==0) {
					break;
				} else {
					ret++;
					S--;
				}
			}
		}
		cout<<ret<<endl;
	}

	return 0;
}
