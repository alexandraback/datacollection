// 2013 code jam round 1A Problem B
int verbose = 0 ;

#include <iostream>
using namespace std ;
#include <vector>
//#include <string>
//#include <map>
//#include <set>

int caseNumber;


int runTest() {
  int E,R,N;
  cin >> E >> R >> N ;
  if (R > E) {
    R = E ;
    cerr << "Note: R was greater than E! Setting to E." << endl ;
  }
  if (verbose) {
    cout << "E " << E << " R " << R << " N " << N << endl ;
  }
  vector<int> v ;
  int i ;
  for (i = 0 ; i < N ; i++) {
    int vi ;
    cin >> vi ;
    v.push_back(vi);
  }
  
  int gain = 0 ;
  int energy = E ;
  for (i = 0 ; i < N ; i++) {
    int toExpend = 0 ;
    int j ;
    int count = 0 ;
    for (j = i+1 ; j < N ; j++) {
      if (v[i] >= v[j]) {
        if (verbose) {
          cout << "v[" << i << "] >= v[" << j << "]" << endl ;
        }
        toExpend += R ;
        count ++ ;
        if (toExpend >= energy) {
          toExpend = energy ;
          break ;
        }
      }
      else break ;
    }
    if (j == N) {
      toExpend = energy ;
    }
    else if (energy + R + count*R - toExpend > E){
      toExpend = energy + R +count*R - E ;
      if (toExpend > energy)
        toExpend = energy ;
      
    }
    gain += toExpend * v[i];
    if (verbose) {
      cout << v[i] << '\t' << energy << '\t' << toExpend << '\t' << gain << endl ;
    }
    energy += R - toExpend ;
    if (energy > E) {
      cout << "Error! Energy is greater than E!" << endl ;
      cerr << "Error! Energy is greater than E!" << endl ;
    }
    if (energy < R) {
      cout << "Error! Energy is less than R!" << endl ;
      cerr << "Error! Energy is less than R!" << endl ;
    }
  }
  if (verbose) {
    cout << "Final energy: " << energy << endl ;
  }

  cout << "Case #" << caseNumber << ": " ;
  cout << gain << endl ;
  
  return (energy == R);
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

