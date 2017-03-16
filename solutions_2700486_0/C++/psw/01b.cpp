#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<string>
#include<set>
#include<vector>

using namespace std;



int main() {
  int T, n, i, j, cn, w;
  long double a[30000], b[30000];
  int X, Y;
  cin >> T;
  for(cn=0; cn<T; cn++){
    int res = 0;
    cin >> n >> X >> Y;
    int sum_coord = (abs(X) + abs(Y)) / 2;
    int act_n = sum_coord * (sum_coord * 2 - 1);
    int act_offset = n - act_n;
    if (act_offset > sum_coord * 4 + 1) {
      cout << "Case #" << cn+1 << ": " << 1 << "\n";
    } 
    else if (act_offset <= 0) {
      cout << "Case #" << cn+1 << ": " << 0 << "\n";   
    }
    else {
      int v = 2*sum_coord - abs(X);
      if (X == 0) {
	if (act_offset == sum_coord * 4 + 1) {
	  cout << "Case #" << cn+1 << ": " << 1 << "\n";
	} else
	{
	  cout << "Case #" << cn+1 << ": " << 0 << "\n";   
	}
      } else {
//	cout << "act_offset = "<< act_offset<< "  v = "<< v << "\n";
	for (j=0; j<2*sum_coord; j++) {a[j] = 0.; b[j] = 0.;}
	for(w=0; w<act_offset; w++) {
	  b[0] = (1. + a[0]) / 2.0;
	  for(j=1; j<2*sum_coord; j++) b[j] = (a[j-1] + a[j]) / 2.0;
	  for(j=0; j<=w-2*sum_coord; j++) b[j] = 1.;
	  for(j=0; j<2*sum_coord; j++) a[j] = b[j];
//	  for(j=0; j<2*sum_coord; j++) cout << a[j] << " ";
//	  cout << "\n";
	}
        cout << "Case #" << cn+1 << ": " << a[v] << "\n";
      }
    }
   }
  return 0;
}