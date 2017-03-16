// code jam d
int verbose = 0 ;

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std ;

int regularScore(vector<double> naomi, vector<double> ken, int N) {
  if (N == 1)
    return naomi[0] > ken[0] ;
  int score = 0 ;
  int kenIndex = N-1 ;
  int naomiIndex = N-1 ;
  for (naomiIndex = N-1; naomiIndex >= 0 ; naomiIndex --) {
    if (naomi[naomiIndex] > ken[kenIndex]) {
      score++;
    }
    else {
      kenIndex--;
    }
  }
  return score ;
}

/*
int cheatScore(vector<double> naomi, vector<double> ken, int N) {
  if (N == 1)
    return naomi[0] > ken[0] ;
  int score = 0 ;
  int kenIndex = N-1 ;
  int naomiIndex = N-1 ;
  for (naomiIndex = 0; naomiIndex < N ; naomiIndex ++) {
    if (naomi[naomiIndex] > ken[kenIndex]) {
      score++;
    }
    else {
      kenIndex--;
    }
  }
  return score ;
}
*/

int runTest() {
  
  int N ;
  cin >> N ;
  vector<double> naomi;
  vector<double> ken;
  int i;
  double x;
  for (i = 0 ; i < N ; i++) {
    cin >> x ;
    naomi.push_back(x);
  }
  for (i = 0 ; i < N ; i++) {
    cin >> x ;
    ken.push_back(x);
  }
  if (N > 1) {
    sort(naomi.begin(), naomi.end());
    sort(ken.begin(), ken.end());
  }
  if (verbose) {
    cout << endl ;
    for (i = 0 ; i< N ; i++)
      cout << naomi[i] << '\t' ;
    cout << endl ;
    for (i = 0 ; i< N ; i++)
      cout << ken[i] << '\t' ;
    cout << endl ;
  }
  int rscore = regularScore(naomi, ken, N);
  int cscore = N-regularScore(ken,naomi, N);
  cout << cscore << " " <<  rscore << endl ;
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
  int i;
  for (i=0 ; i < testCases ; i++) {
    if (verbose)
      cout << "// Running case #" << i+1 << endl ;
    cout << "Case #" << i + 1 << ": " ;
    int r = runTest();
    if (!r) {
      cerr << "test failed!" << endl ;
    }
  }
  
  return 0;
}

