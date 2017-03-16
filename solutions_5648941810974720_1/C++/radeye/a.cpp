#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std ;
typedef unsigned long long ull ;
typedef long long ll ;
const char *names[] = {
  "ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"
} ;
char keys[] = { 'Z', 'W', 'U', 'X', 'G', 'F', 'H', 'V', 'O', 'I' } ;
int vals[] = { 0, 2, 4, 6, 8, 5, 3, 7, 1, 9 } ;
int main(int argc, char *argv[]) {
   int K ;
   cin >> K ;
   for (int kase=1; kase<=K; kase++) {
      ll r = 33 ;
      string s ;
      cin >> s ;
      vector<int> cnts(128) ;
      for (int i=0; i<s.size(); i++)
	cnts[s[i]]++ ;
      vector<int> digs(10) ;
      for (int i=0; i<10; i++) {
	digs[vals[i]] = cnts[keys[i]] ;
	for (int j=0; names[vals[i]][j]; j++)
	  cnts[names[vals[i]][j]] -= digs[vals[i]] ;
      }
      for (int i=0; i<128; i++)
	if (cnts[i])
	  cout << "FAIL " ;
      cout << "Case #" << kase << ": " ;
      for (int i=0; i<10; i++)
	for (int j=0; j<digs[i]; j++)
	  cout << i ;
      cout << endl ;
   }
}
