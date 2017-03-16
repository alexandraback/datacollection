#include <iostream>
#include <map>
#include <string>
using namespace std;

string S;
map<string, int> dict;
int N;
int A[1009];
int B[1009];

int main()
{
  int T;
  cin >> T;
  getline(cin, S);
  for (int Ti = 1; Ti <= T; Ti++)
  {
    // init
    dict.clear();
    int W = 0;
    
    // input
    cin >> N;
    getline(cin, S);
    for (int i = 0; i < N; ++i) {
      getline(cin, S);
      string a = S.substr(0, S.find(" "));
      string b = S.substr(S.find(" ") + 1, S.length() - S.find(" ") - 1);
      if (dict.count(a) == 0) {
	dict[a] = W;
	W++;
      }
      A[i] = dict[a];
      if (dict.count(b) == 0) {
	dict[b] = W;
	W++;
      }
      B[i] = dict[b];
    }
    
    //for (int n = 0; n < N; ++n) cout << A[n] << " " << B[n] << endl;
    
    // brute force
    bool fake[N];
    int best = 0;
    for (int n = 0; n < N; ++n)
      fake[n] = false;
    while (true) {
      // check option
      bool ok = true;
      int fakes = 0;
      for (int n = 0; n < N; ++n)
	if (fake[n] == true) {
	  fakes++;
	  bool found_a = false;
	  bool found_b = false;
	  for (int k = 0; k < N; ++k) 
	    if (fake[k] == false) {
	      if (A[n] == A[k]) found_a = true;
	      if (B[n] == B[k]) found_b = true;
	      //if (A[n] == A[k] && B[n] == B[k]) cout << "ERROR: " << n << " " << k << endl;
	    }
	  if (!found_a || !found_b) {
	    ok = false;
	    //cout << "Didnt find for n = " << n << endl;
	    break;
	  }
	}
      if (ok && (fakes > best))
	best = fakes;    
      
      // go to next option
      int n = N - 1;
      while (n >= 0 && fake[n] == true) n--;
      if (n < 0) break;
      fake[n] = true;
      for (int i = n + 1; i < N; ++i) fake[i] = false;
      
      //for (int i = 0; i < N; ++i) cout << fake[i] << " "; cout << endl;
    }
    
    // produce output
    cout << "Case #" << Ti << ": " << best << endl;
  }
  return 0;
}
