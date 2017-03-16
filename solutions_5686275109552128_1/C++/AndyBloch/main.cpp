// code jam b
int verbose = 0 ;

#include <iostream>
#include <iomanip>
#include <vector>

using namespace std ;

int findBest(vector<int> pancakes) {
  sort (pancakes.begin(),pancakes.end() );
  int maxPancakes = pancakes.back() ;
  int bestTime = maxPancakes ;
  int i ;
  for (i = 1 ; i < maxPancakes ; i++) {
    int totalSplits = 0 ;
    int j ;
    for (j=0;j<pancakes.size() ; j++) {
      int splits = pancakes[j]/i ;
      if (splits*i == pancakes[j])
        splits--;
      totalSplits+= splits;
    }
    int time = totalSplits + i ;
    if (time < bestTime)
      bestTime = time ;
    if (verbose) {
      cout << "pancake goal: " << i << " splits: " << totalSplits << endl ;
    }
  }
  return bestTime;
}

int findBestOld(vector<int> pancakes) {
  sort (pancakes.begin(),pancakes.end() );
  int maxPancakes = pancakes.back() ;
  //cout << "maxPancakes = " << maxPancakes << endl ;
  int bestTime = maxPancakes ;
  if (verbose) {
    int i ;
    cout << " max " << maxPancakes << " : " ;
    for (i = 0 ; i < pancakes.size() ; i++) {
      cout << " " << pancakes[i] ;
    }
    cout << endl ;
  }
  if (maxPancakes < 4)
    return bestTime ;
  pancakes.back() = maxPancakes/2 ;
  pancakes.push_back(maxPancakes - pancakes.back());
  int time = 1 + findBestOld(pancakes);
  if (time < bestTime)
    bestTime = time ;
  return bestTime;
}

int runTest() {
  int diners ;
  cin >> diners ;

  if (verbose) {
    cout << endl << "Diners: " << diners << " :" ;
  }

  vector<int> pancakes(diners) ;
  int i;
  
  for (i = 0 ; i < diners ; i++) {
    cin >> pancakes[i] ;
    if (verbose) cout << " " << pancakes[i] ;
  }
  if (verbose) cout << endl ;
  
  int bestTime = findBest(pancakes);
  if (verbose) {
    int bestTimeOld = findBestOld(pancakes);
    if (bestTimeOld != bestTime)
      cout << "Best with old algo: " << bestTimeOld << endl ;
  }
  cout << bestTime << endl ;
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
    if (!r)
      cerr << "Test " << i+1 << " failed!" << endl ;
  }
  return 0;
}

