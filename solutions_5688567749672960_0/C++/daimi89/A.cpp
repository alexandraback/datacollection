#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

const int MAXN = 1000000;
// const int MAXN = 1000;

int main() {
  int T;
  cin >> T;
  for (int t=1; t<=T; t++) {
    int N;
    cin >> N;
    int answer = 0;

    vector<int> m(MAXN+1,0);

    for (int i=1; i<=MAXN; i++) m[i]=i;
    for (int i=1; i<=MAXN; i++) {
	if (m[i+1]>m[i]+1) m[i+1]=m[i]+1;
	int orgi=i,revi = 0;
	while (orgi>0) revi=revi*10+(orgi % 10), orgi /=10;
	if (m[revi]>m[i]+1) {
	  m[revi]=m[i]+1;
	  if (revi<i) { cout << "UPS..." << i << endl; }
	}
	//	cout << i << " " << revi << endl;
      };
    
    answer = m[N];

    cout << "Case #" << t << ": " << answer << endl;
  };
  return 0;
};
