#include<iostream>
#include<algorithm>
using namespace std;
const int maks = 200;
int t, n, l;
long long a, b, k;
int main(){
  cin >> t;
  for (int i = 1; i <= t; i++) {
	  int count = 0;
    cin >> a >> b >> k;
    cout << "Case #" << i << ": ";
    for (int x = 0; x < a; ++x)
	    for (int y = 0; y < b; ++y) {
		    if ((x&y)<k){
			    count++;
		    };
	    };
    cout << count  << endl;
  };
};
