#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>
#include <vector>
#include <map>

using namespace std;

int main() {
	int T, A, B;

	cin>>T;
	for(int i=1; i<=T; i++) {
		cin>>A>>B;
		long ret=0;
		cout<<"Case #"<<i<<": ";

		for (int j=A; j<=B; j++) {
			stringstream ss;
			ss<<j;
			string s=ss.str();
			map<int,int> mp;
			for(int k=1; k<s.length(); k++) {
				string tmp=s.substr(k) + s.substr(0,k);
				stringstream pp;
				pp<<tmp;
				int r;
				pp>>r;
				if(r>=A && r<j) {
					mp[r]++;
				}
			}
			ret+=mp.size();
		}
		cout<<ret<<endl;
	}

	return 0;
}
