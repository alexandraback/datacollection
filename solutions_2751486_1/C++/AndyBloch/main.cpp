// 2013 code jam round 1C Problem A
int verbose = 0 ;

#include <iostream>
using namespace std ;
//#include <vector>
#include <string>
//#include <map>
//#include <set>

int caseNumber;

int isVowel (char x) {
  return (x=='a' || x=='e' || x=='i' || x=='o' || x=='u');
}
int runTest() {
  string name ;
  int n ;
  cin >> name >> n ;
  
  long long L = name.length();
  if (verbose)
    cout << "Name: " << name << " L: " << L << " n: " << n << endl ;
  
  long long numberOfSubstrings = L * (L - 1) / 2 + L;
  if (verbose)
    cout << "All substrings: " << numberOfSubstrings << endl ;
  
  int i ;
/*  for (i = 1 ; i < n ; i++) {
    numberOfSubstrings -= L- i+1 ;
  }
 */
  numberOfSubstrings -= (2*L-n+2)*(n-1)/2;
  if (verbose)
    cout << "All substrings length at least " << n << ": " << numberOfSubstrings << endl ;

  int start = 0 ;
  int consonants = n ;
  for (i = 0 ; i < n ; i++) {
    if (isVowel(name[i])) {
      start = 0 ;
      consonants = 0 ;
      break ;
    }
  }
  for ( ; i < L ; i++) {
    if (isVowel(name[i])) {
      if (consonants >= n) {
        start = i - n + 1 ;
      }
      consonants = 0 ;
    }
    else {
      consonants++ ;
      if (consonants == n) {
        int end = i ;
        int sl = end-start ;
        numberOfSubstrings -= (sl-n+2)*(sl-n+1)/2 ;
        if (verbose)
          cout << "Substring without consecutive " << n << " consonants: " << name.substr(start,sl) << endl ;
        
      }
        
    }
  }
  if (consonants < n) {
    int end = i ;
    int sl = end-start ;
    numberOfSubstrings -= (sl-n+2)*(sl-n+1)/2 ;
    if (verbose)
      cout << "Final substring without consecutive " << n << " consonants: " << name.substr(start,sl) << endl ;
  }
  
  cout << "Case #" << caseNumber << ": " ;
  cout << numberOfSubstrings << endl ;
  
  return 1;
}

int main (int argc, const char * argv[])
{
  int testCases ;
  cin >> testCases ;
  if (verbose) {
    cerr << "Verbose is on!" << endl ;
    cout << "// Test cases: " << testCases << endl ;
  }
  for (caseNumber=1 ; caseNumber <= testCases ; caseNumber++) {
    if (verbose)
      cout << "// Running case #" << caseNumber << endl ;
    int r = runTest();
    if (!r) {
      cerr << "test failed!" << endl ;
    }
  }
  return 0;
}

