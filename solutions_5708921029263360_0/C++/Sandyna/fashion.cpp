#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main () {
  long long t, je, pa, sh, k;
  cin >> t;
  for (int i = 0; i < t; i++) {
    cin >> je >> pa >> sh >> k;
    vector<vector<vector<long long> > > howManyTimesUsed (je+1, vector<vector<long long> > (pa+1, vector<long long> (sh+1, 0) ) );
    vector<vector<long long> > result;
    cout << "Case #" << i+1 << ": ";
    for (int j = 1; j <= je; j++) {
      for (int p = 1; p <=pa; p++) {
	for (int s = 1; s <= sh; s++) {
// 	  cout << j << " " << p << " " << s << endl;
	  //can I add it?
	  if (howManyTimesUsed[0][p][s] < k && howManyTimesUsed[j][0][s] < k && howManyTimesUsed[j][p][0] < k) {
	    vector<long long> res = {j, p, s};
	    result.push_back(res);
	    howManyTimesUsed[0][p][s] ++;
	    howManyTimesUsed[j][0][s] ++;
	    howManyTimesUsed[j][p][0] ++;
	  }
	}
      }
    }
    cout << result.size() << endl;
    for (int j = 0; j < result.size(); j++) {
      cout << result[j][0] << " " << result[j][1] << " " << result[j][2] << endl;
    }
  }
}