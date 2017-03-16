#include <iostream>  // includes cin to read from stdin and cout to write to stdout
#include <vector>
#include <map>
#include <algorithm>
using namespace std;  // since cin and cout are both in namespace std, this saves some text
int main() {
  int t;
  cin >> t; cin.ignore(INT_MAX,'\n');
  for (int i = 1; i <= t; ++i) {
  	int n;
  	map<int, int> map;
  	cin >> n;
  	for(int j=n*(2*n-1); j>0 ;j--){
  		int h;
  		cin >> h;
  		map[h]++;
	  }
	vector<int> res;
	for(auto e:map){
		if(e.second%2)res.push_back(e.first);
	}
	sort(res.begin(), res.end());
    cout << "Case #" << i << ":";
    for(int j:res) cout<< " " <<j;
    cout<<endl;
  }
}
