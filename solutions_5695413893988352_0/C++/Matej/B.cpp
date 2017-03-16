#include <iostream>
#include <algorithm>
#include <string>
#include <iomanip>
using namespace std;

string S;
int N;
string A;
string B;

int main()
{
  int T;
  cin >> T;
  getline(cin, S);
  for (int Ti = 1; Ti <= T; Ti++)
  {
    // input
    getline(cin, S);
    string A = S.substr(0, S.find(" "));
    string B = S.substr(S.find(" ") + 1, S.length() - S.find(" ") - 1);
    //cout << "-" << A << "-" << B << "-" << endl;
    int N = A.length();
    
    // brute force
    int mind = 1e9 + 9;
    int best_a = 0;
    int best_b = 0;
    for (int a = 0; a < 1000; ++a)
      for (int b = 0; b < 1000; ++b)
      {
	bool ok = true;
	int aa = a; int bb = b;
	for (int n = N - 1; n >= 0; --n)
	{
	  if (A[n] != '?' && ((aa % 10) != A[n] - '0')) ok = false;
	  if (B[n] != '?' && ((bb % 10) != B[n] - '0')) ok = false;
	  aa /= 10;
	  bb /= 10;
	  //if (a == 730 && b == 727) cout << ok << " N = " << N << " aa = " << aa << "; bb = " << bb << endl;
	}
	if (ok && aa == 0 && bb == 0 && abs(a - b) < mind) {
	  best_a = a;
	  best_b = b;
	  mind = abs(a - b);
	}
      }
    
    // produce output
    cout << "Case #" << Ti << ": " << setw(N) << setfill('0') << best_a << " " << setw(N) << setfill('0') << best_b << endl;
  }
  return 0;
}
