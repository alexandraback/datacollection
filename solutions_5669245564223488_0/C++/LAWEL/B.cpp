#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>

using namespace std;

typedef long long lli;

vector<pair<string, int> > vec;

bool calc(int p){
	if(p >= vec.size()){
		return true;
	}else{
		for(int i=p+1;i<vec.size();i++){
			if(vec[i-1].first[1] != vec[i].first[0]) break;
			if(calc(i+1)) return true;
		}
	}
	return false;
}

int main(){
	int T;
	cin >> T;
	for(int t=0;t<T;t++){
		int n;
		cin >> n;
		vec.clear();
		for(int i=0;i<n;i++){
			string in;
			cin >> in;
			string tmp = in.substr(0, 1);
			tmp += in.back();
			vec.push_back(make_pair(tmp, i));
		}
		sort(vec.begin(), vec.end());
		lli ans = 0LL;
		do{
			if(calc(0)) ans = (ans + 1) % 1000000007LL;
		}while(next_permutation(vec.begin(), vec.end()));
		cout << "Case #" << t + 1 << ": ";
		cout << ans << endl;
	}
	return 0;
}
